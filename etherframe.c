/*
 * Copyright (c) 2018, Valerio Bellizzomi
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the System Experiments Laboratory, Rome nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** @page main Etherframe

Ethernet frame receiver with statistics. Supports the Preventive Maintenance Model.

*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
// #include <net/if.h>
// #include <linux/in.h>
#include <linux/if_ether.h>
#include <ifaddrs.h>
#include <linux/wireless.h>


#define ETHERFRAME_VERSION "0.5"

/* ***** INVARIANTS ***** */
/** @brief 1500 is the max length.*/
#define ETH_FRAME_LENGTH 1500
/** @brief Ethernet header length*/
#define ETH_HEADER_LENGTH 14
#define IP_HEADER_POS 35
#define TCPUDP_HEADER_POS 44
#define FCS_LENGTH 4


/** @brief Mark for 10/100/1000 MBit switch*/
#define __ETH_PROTOCOL_SWITCH__     0x05DC
/** @brief IPv4 guard value*/
#define __IPV4_GUARD__              0x45
#define __MAX_COP__                 1.0
#define __MIN_COP__                 0.0
/** @brief I have improved the resolution of ROP to six digits after the dot, so that we can see the smallest variations. Currently the ROP resolution is in excess of what we expect to be able to test here in the lab. in order to actually trigger the ROP check. I expect that the minimum required resolution will vary depending on the cable type and test conditions.*/
#define __DEFAULT_ROP__             0.999999

/* Global Constants */
/** @brief Activate NIC promiscuous mode*/
#define ENABLE_PROMISC  1
/** @brief Deactivate NIC promiscuous mode*/
#define DISABLE_PROMISC 0

/* Protocol signatures */
#include "signatures.h"

    int frmbytes = 0;           // Number of bytes in a frame

/** @brief Prints error strings*/


void printError(char es[160]) {
    printf("Etherframe: %s\n", es);
}

int check_wireless(const char* ifname, char* protocol) {
  int sock = -1;
  struct iwreq pwrq;
  memset(&pwrq, 0, sizeof(pwrq));
  strncpy(pwrq.ifr_name, ifname, IFNAMSIZ);

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    return 0;
  }

  if (ioctl(sock, SIOCGIWNAME, &pwrq) != -1) {
    if (protocol) strncpy(protocol, pwrq.u.name, IFNAMSIZ);
    close(sock);
    return 1;
  }

  close(sock);
  return 0;
}


int listnet() {
  struct ifaddrs *ifaddr, *ifa;

  printf("\nListing network interfaces\n");

  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    return -1;
  }

  /* Walk through linked list, maintaining head pointer so we
     can free list later */
  for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
    char protocol[IFNAMSIZ]  = {0};

    if (ifa->ifa_addr == NULL ||
        ifa->ifa_addr->sa_family != AF_PACKET) continue;

    if (check_wireless(ifa->ifa_name, protocol)) {
      printf("interface %s is wireless: %s\n", ifa->ifa_name, protocol);
    } else {
      printf("interface %s is not wireless\n", ifa->ifa_name);
    }
  }

  freeifaddrs(ifaddr);
  return 0;
}


/** @brief Set NIC mode*/
int set_ethPromisc(char net[8], struct ifreq ethr, int sck, int mode) {
    switch (mode) {
        case ENABLE_PROMISC:
            strncpy(ethr.ifr_name, net, IFNAMSIZ);
            if ( ioctl(sck, SIOCGIFFLAGS, &ethr) == -1) {
                printError("Error in set_ethPromisc ioctl(SIOCGIFFLAGS) while selecting interface.");
                return (-1);
            }
            printf("Selected interface %s\n", net);

            if (!(ethr.ifr_flags & IFF_PROMISC)) {
                ethr.ifr_flags |= IFF_PROMISC;
                if ( ioctl(sck, SIOCSIFFLAGS, &ethr) == -1) {
                    printError("Set promiscuous mode: error in set_ethPromisc ioctl(SIOCSIFFLAGS)");
                    return (-1);
                }
            }
            printf("Promiscuous mode enabled.\n");
            return (0);
            break;

        case DISABLE_PROMISC:
            strncpy(ethr.ifr_name, net, IFNAMSIZ);
            if ( ioctl(sck, SIOCGIFFLAGS, &ethr) == -1) {
                printError("Error in set_ethPromisc ioctl(SIOCGIFFLAGS) while selecting interface.");
                return (-1);
            }
            printf("Selected interface %s\n", net);

            if (ethr.ifr_flags & IFF_PROMISC) {
                ethr.ifr_flags ^= IFF_PROMISC;
                if ( ioctl(sck, SIOCSIFFLAGS, &ethr) == -1) {
                    printError("Unset promiscuous mode: error in set_ethPromisc ioctl(SIOCSIFFLAGS)");
                    return (-1);
                }
            }
            printf("Promiscuous mode disabled.\n");
            return (0);
            break;

        default:
            printError("set_ethPromisc(): Invalid mode, must be ENABLE_PROMISC or DISABLE_PROMISC.");
           return (1);

    } //switch
} //set_ethPromisc()


/** @brief Check FCS */
void fcsDecoder(char fb[1522], int n) {

    unsigned int ffb[FCS_LENGTH];
    int k = n-FCS_LENGTH;

    ffb[0] = fb[n-3];
    ffb[1] = fb[n-2];
    ffb[2] = fb[n-1];
    ffb[3] = fb[n];
    
//    strncat(ffb, &fb[k], FCS_LENGTH);
    printf("FCS=0x%08x", ffb);
}



/** @brief Decode MAC addresses*/
void macDecoder(unsigned char *eframe) {

// Print MAC Addresses in order -
// - destination MAC address
    printf("dMAC=%02x:%02x:%02x:%02x:%02x:%02x",
        eframe[0],eframe[1],eframe[2],
        eframe[3],eframe[4],eframe[5]);
// - source MAC address
    printf(", sMAC=%02x:%02x:%02x:%02x:%02x:%02x",
        eframe[6],eframe[7],eframe[8],
        eframe[9],eframe[10],eframe[11]);
} // macDecoder()


/** @brief Decode frame type*/
void frameTypeDecoder(int b) {
    if (b <= __ETH_PROTOCOL_SWITCH__) {
        // brand = 0..1500 decimal --> length field of IEEE 802.3
        // 10Mbit/sec
        printf(", 10baseT   LF=0x%08x ", b);
    }
    else {
        // brand > 1500 decimal --> type field of Ethernet II
        // 100Mbit/sec
        printf(", 1000baseT TF=0x%08x ", b);
    }
} // frameTypeDecoder()


/** @brief Bare protocol decoder*/
// WARNING: Version with IPv4, ARP and other protocol decoding.

void protocolDecoder(int b, unsigned char *protohead, unsigned char fb[ETH_FRAME_LENGTH]) {
    switch(b) {
        case SIGN_IPV4:
            // OPEN ISSUE 1: Make the routine portable, or optimize for space.
            // OPEN ISSUE 2: Move the following line out in the main()
            protohead = fb + ETH_HEADER_LENGTH; // Skip Ethernet header
            // Double check for IPv4
            if (*protohead == __IPV4_GUARD__) {
                // Decode IP protocol
                printf("IPv4");
                // Display IP source address with port.
                printf(", SRC=%d.%d.%d.%d:%d",
                       protohead[12], protohead[13],
                       protohead[14], protohead[15],
                       (protohead[20]<<8) + protohead[21]);
                    // (protohead[20]<<8) + protohead[21] is source port

                // Display IP destination address with port.
                printf(", DST=%d.%d.%d.%d:%d",
                       protohead[16], protohead[17],
                       protohead[18], protohead[19],
                       (protohead[22]<<8) + protohead[23]);
                    // (protohead[22]<<8) + protohead[23] is destination port

                printf(", P=%d",protohead[9]);  // Level 4 protocol number
                // In future...Further decode Level 4 protocol.
            } // if (*protohead == __IPV4_GUARD__)
            else {
                // Initial provision for IPv4 diagnostics
                printf("NOT IPv4 or Malformed packet");
            }
            break;
        case SIGN_ARP:
        /* Address Resolution Protocol */
            printf("ARP");
            break;

        case 0x86dd:
        /* IPv6 */
            printf("IPv6");
            break;

        case 0x0027:
        /* TP++ Transport Protocol */
            printf("TP++");
            break;

        default:
            printf("FIELD=%4i", b);
            break;
    }

    printf("\n");
} //protocolDecoder()


/** @brief Main*/
int main(int argc, char *argv[]) {

    /* Declare and initialize variables */
    unsigned char *ethframe, *prothead;
    unsigned char frmbuf[ETH_FRAME_LENGTH];
    int brand = 0;
    int sock = 0;

    int totfrm = 0;        // Total number of frames
    int complfrm = 0;      // Number of frames with complete headers
    int incomplfrm = 0;    // Number of frames with incomplete headers
    int i, j = 0;
    char *interface = "eth0";
    int promisc_mode = 1;
    struct ifreq ethreq;

    printf("Initializing Etherframe %s ...\n", ETHERFRAME_VERSION);
    printf("DISCLAIMER: IT IS ADVISED TO NOT USE THIS PROGRAM YET AS IT IS WORK IN PROGRESS.\n");
    printf("THIS PROGRAM IS BEST USED IN CONJUNCTION WITH THE ETHTOOL PROGRAM,\n");
    printf("WHICH PROVIDES MEANS TO MANIPULATE NIC FEATURE CONFIGURATION BITS.\n");
    printf("Copyright (c) 2018, Valerio Bellizzomi\n");
    printf("Etherframe is free software and comes with ABSOLUTELY NO WARRANTY. See Makefile for details.\n");
    printf("Warning! Usage requires root user.\n");
    printf("Usage: %s [ <interface name> [0|1] ]\n", argv[0]);


    switch (argc) {
        case 1:
            j = listnet();
            return j;
            break;
        case 2:
            interface = argv[1];
            break;
        case 3:
            interface = argv[1];
            promisc_mode = atoi(argv[2]);
            break;

    }

        /* Setup section */

        // open raw socket for all eth frames
        if ((sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0) {
            printError("Cannot open socket.");
            return (1);
        }
        else {
            printf("Socket opened (%i).\n", sock);
        }

        // Open socket in promisc. mode.
        // Topmost error processing.
        switch (set_ethPromisc(interface, ethreq, sock, promisc_mode)) {
            case 0:
                printf("Ready.\n");
                break;
            case -1:
                printError("set_ethPromisc(): Internal error.");
                return (1);
                break;
            case 1:
                printError("set_ethPromisc(): Fatal error.");
                return (1);
        }


        /** @brief Main loop */
        while (1) {
    float CUR_COP =  __MAX_COP__;   // Current COP. Assume we have a good line
    float LOST_COP = __MIN_COP__;   // Missing COP. Assume we have a good line

            frmbytes = recvfrom(sock, frmbuf, 1522, 0, NULL, NULL);

                /*
                CHECK TO SEE IF THE FRAME CONTAINS AT LEAST COMPLETE HEADERS:
                    * (a) Ethernet (14 bytes), pos 1-14,
                    * (b) IP (20 bytes), pos 15-35.
                    * (c) TCP/UDP/etc. (8 bytes), pos 36-44.
                    * (d) Frame Check Sequence (4 bytes), pos length-4 when receiving fcs field
               */



            if (frmbytes > 0) {
                totfrm = totfrm + 1;   // increment total frame count

                /* INCOMPLETE ETHERNET FRAME */
                if (frmbytes <= ETH_HEADER_LENGTH) {
                    // we have received an incomplete frame header.
                    incomplfrm = incomplfrm + 1;

                    // Print all raw data from incomplete frames.

                    /* INCOMPLETE HEADER */
                    if (frmbytes < ETH_HEADER_LENGTH) {
                        printf(" INCOMPL ETH FRM (ERRNO=%05i) (FB=%i) (DATA=", errno, frmbytes);

                        for (i = 0; i < (frmbytes - 1); i++) { printf("%02x ", frmbuf[i]); };
                        printf(")\n");
                    }

                    /* COMPLETE ETHERNET HEADER AND EMPTY PAYLOAD */
                    /*  The minimum packet length should be 46 if there are incapsulated protocols */
                    if (frmbytes == ETH_HEADER_LENGTH) {
                        printf(" COMPL ETH HDR -NO PAYLOAD- (ERRNO=%05i) (FB=%i) (DATA=", errno, frmbytes);

                        for (i = 0; i < (frmbytes - 1); i++) { printf("%02x ", frmbuf[i]); };
                        printf(")\n");
                    }

                } //if (frmbytes < ETH_HEADER_LENGTH)


                /* COMPLETE FRAME WITH PAYLOAD */
                if (frmbytes > ETH_HEADER_LENGTH) {
                    complfrm = complfrm + 1;
                    ethframe = frmbuf;
                    macDecoder(ethframe);
                    printf(", FB=%i, ", frmbytes);
                    brand = (ethframe[12]<<8) + ethframe[13]; // length field or type field
                    // (ethframe[12]<<8)+ethframe[13] is the field.

                    /*
                Field mode :
                    <= 1500 decimal = length field = IEEE 802.3 = 10Mbps,
                    > 1500 decimal = type field = Ethernet II = 100Mbps/1000Mbps.
                */
                    fcsDecoder(ethframe,frmbytes);
                    frameTypeDecoder(brand);
                    protocolDecoder(brand, prothead, ethframe);

                    /* Display also packet payload data */
                    for (i = 0; i < (frmbytes - 1); i++) { printf("%02x ", ethframe[i]); };
                    printf("\n");

                } //if (frmbytes > ETH_HEADER_LENGTH)
            } //if (frmbytes > 0)

            CUR_COP = (complfrm + 1) / (totfrm + 1);
            LOST_COP = (incomplfrm + 1) / (totfrm + 1);

            // Display full statistics report. Introduced for support of Preventive Maintenance Model.
            if (CUR_COP >= __DEFAULT_ROP__) {
                printf("  T=%d C=%d I=%d COP=%08f LOST=%08f ROP=%08f\n", totfrm, complfrm, incomplfrm, CUR_COP, LOST_COP, __DEFAULT_ROP__);
            }
            else {
                printf("  T=%d C=%d I=%d COP=%08f LOST=%08f ROP=%08f *NO-ROP*\n", totfrm, complfrm, incomplfrm, CUR_COP, LOST_COP, __DEFAULT_ROP__);
            }


        }
}

