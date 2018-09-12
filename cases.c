#ifndef __CASES_C__
#define __CASES_C__

/*
 * Copyright (c) 2007, Valerio Bellizzomi
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

/** @file
 * @brief Signature cases for inclusion in etherframe.c */

/* ONLY REGISTERED SIGNATURES */

        case SIGN_XEROX_PUP:
        /* Conflicts with length field of IEEE 802.3 */
            printf("Alleged XEROX PUP");
            break;

        case SIGN_XEROX_PUP_AT:
        /* Conflicts with length field of IEEE 802.3 */
            printf("Alleged XEROX PUP Address Trans.");
            break;

        case SIGN_NIXDORF:
        /* Conflicts with length field of IEEE 802.3 */
            printf("Alleged NIXDORF");
            break;

        case SIGN_XEROX_NS_IDP:
            printf("XEROX NS IDP");
            break;

        case SIGN_XNS_AT:
            printf("XNS Address Translation");
            break;

        case SIGN_IPV4:
            // OPEN ISSUE 1: Make the routine portable, or optimize for space.
            // OPEN ISSUE 2: Move the following line out in the main()
            protohead = fb + __ETH_HEADER_LENGTH__; // Skip Ethernet header
            // Double check for IPv4
            if (*protohead == __IPV4_GUARD__) {
                // Decode DOD IP protocol
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
                printf("Malformed IPv4");
            }
            break;

        case SIGN_X75:
            printf("X.75");
            break;

        case SIGN_NBS:
            printf("NBS");
            break;

        case SIGN_ECMA:
            printf("ECMA");
            break;

        case SIGN_CHAOSNET:
            printf("CHAOSNET");
            break;

        case SIGN_X25:
            printf("X.25 Level 3");
            break;

        case SIGN_ARP:
        /* Address Resolution Protocol */
            printf("ARP");
            break;

        case SIGN_XNS_COMPAT:
            printf("XNS Compatible");
            break;

        case SIGN_SYMBOLICS_PRIVATE_081C:
            printf("Symbolics Private 081C");
            break;

        case SIGN_XYPLEX_0888:
            printf("XYPLEX 0888");
            break;

        case SIGN_XYPLEX_0889:
            printf("XYPLEX 0889");
            break;

        case SIGN_XYPLEX_088A:
            printf("XYPLEX 088A");
            break;


        case SIGN_UNGERMANN_BASS:
            printf("Ungermann-Bass");
            break;


        case SIGN_XEROX_IEEE_PUP:
            printf("XEROX IEEE PUP");
            break;

        case SIGN_XEROX_IEEE_PUP_AT:
            printf("XEROX IEEE PUP Address Trans.");
            break;


        case SIGN_BANYAN_SYSTEMS:
            printf("Banyan Systems");
            break;

        case SIGN_BANYAN_VINES_ECHO:
            printf("Banyan VINES Echo");
            break;


        case SIGN_BERKELEY_TRAILER_NEGOT:
            printf("Berkeley Trailer Negotiation");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_1001:
            printf("Berkeley Trailer Encapsulation 1001");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_1002:
            printf("Berkeley Trailer Encapsulation 1002");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_1003:
            printf("Berkeley Trailer Encapsulation 1003");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_1004:
            printf("Berkeley Trailer Encapsulation 1004");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_1005:
            printf("Berkeley Trailer Encapsulation 1005");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_1006:
            printf("Berkeley Trailer Encapsulation 1006");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_1007:
            printf("Berkeley Trailer Encapsulation 1007");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_1008:
            printf("Berkeley Trailer Encapsulation 1008");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_1009:
            printf("Berkeley Trailer Encapsulation 1009");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_100A:
            printf("Berkeley Trailer Encapsulation 100A");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_100B:
            printf("Berkeley Trailer Encapsulation 100B");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_100C:
            printf("Berkeley Trailer Encapsulation 100C");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_100D:
            printf("Berkeley Trailer Encapsulation 100D");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_100E:
            printf("Berkeley Trailer Encapsulation 100E");
            break;

        case SIGN_BERKELEY_TRAILER_ENCAP_100F:
            printf("Berkeley Trailer Encapsulation 100F");
            break;

        case SIGN_DCA_MULTICAST:
            printf("DCA Multicast");
            break;

        case SIGN_VALID_SYSTEM_PROTOCOL:
            printf("VALID System Protocol");
            break;

        case SIGN_ARTIFICIAL_HORIZONS:
            printf("Artificial Horizons");
            break;

        case SIGN_DATAPOINT_CORP:
            printf("DataPoint Corp.");
            break;

        case SIGN_PCS_BASIC_BLOCK_PROT:
            printf("PCS Basic Block Protocol");
            break;

        case SIGN_LITTLE_BIG_LAN_DIAGNOSTIC:
            printf("Little Big LAN Diagnostic");
            break;

        case SIGN_THD_DIDDLE:
            printf("THD Diddle");
            break;

        case SIGN_LITTLE_BIG_LAN:
            printf("Little Big LAN");
            break;

        case SIGN_BBN_SIMNET_PRIVATE:
            printf("BBN Symnet Private");
            break;

        case SIGN_DECNET_EXPERIMENTAL:
            printf("DECnet Experimental");
            break;

        case SIGN_DECNET_MOP_ASSISTANCE:
            printf("DECnet MOP Assistance");
            break;

        case SIGN_DECNET_MOP_CONSOLE:
            printf("DECnet MOP Console");
            break;

        case SIGN_DECNET_PHASE_IV:
            printf("DECnet Phase IV");
            break;

        case SIGN_DEC_LAT:
            printf("DEC LAT");
            break;

        case SIGN_DEC_DIAGNOSTIC_PROT:
            printf("DEC Diagnostic Protocol");
            break;

        case SIGN_DEC_CUSTOMER_PROT:
            printf("DEC Customer Protocol");
            break;

        case SIGN_DEC_VAX_CLUSTER:
            printf("DEC VAX Cluster");
            break;

        case SIGN_DEC_AMBER:
            printf("DEC AMBER");
            break;

        case SIGN_DEC_MUMPS:
            printf("DEC MUMPS");
            break;

        case SIGN_3COM_CORP_6010:
            printf("3Com Corp. 6010");
            break;

        case SIGN_3COM_CORP_6011:
            printf("3Com Corp. 6011");
            break;

        case SIGN_3COM_CORP_6012:
            printf("3Com Corp. 6012");
            break;

        case SIGN_3COM_CORP_6013:
            printf("3Com Corp. 6013");
            break;

        case SIGN_3COM_CORP_6014:
            printf("3Com Corp. 6014");
            break;

        /* Ungermann-Bass */
        case SIGN_UB_DOWNLOAD:
            printf("Ungermann-Bass Download");
            break;

        case SIGN_UB_NIU:
            printf("Ungermann-Bass NIU");
            break;

        case SIGN_UB_DIAGNOSTIC:
            printf("Ungermann-Bass Diagnostic");
            break;

        case SIGN_UB_BRIDGE_NMC:
            printf("Ungermann-Bass Bridge NMC");
            break;

        case SIGN_UB_BRIDGE_SPANNING_TREE:
            printf("Ungermann-Bass Bridge Spanning-Tree");
            break;

        case SIGN_OS9_MICROWARE:
            printf("OS/9 Microware");
            break;

        case SIGN_OS9_NET:
            printf("OS/9 Net");
            break;

        case SIGN_SINTROM_7020:
            printf("Sintrom 7020");
            break;

        case SIGN_SINTROM_7021:
            printf("Sintrom 7021");
            break;

        case SIGN_SINTROM_7022:
            printf("Sintrom 7022");
            break;

        case SIGN_SINTROM_7023:
            printf("Sintrom 7023");
            break;

        case SIGN_SINTROM_7024:
            printf("Sintrom 7024");
            break;

        case SIGN_SINTROM_7025:
            printf("Sintrom 7025");
            break;

        case SIGN_SINTROM_7026:
            printf("Sintrom 7026");
            break;

        case SIGN_SINTROM_7027:
            printf("Sintrom 7027");
            break;

        case SIGN_SINTROM_7028:
            printf("Sintrom 7028");
            break;

        case SIGN_SINTROM_7029:
            printf("Sintrom 7029");
            break;

        case SIGN_RACAL_INTERLAN:
            printf("RACAL Interlan");
            break;

        case SIGN_PRIME_NTS:
            printf("Prime NTS");
            break;

        case SIGN_CABLETRON:
            printf("Cabletron");
            break;

        case SIGN_CRONUS_VLN:
            printf("Cronus VLN");
            break;

        case SIGN_CRONUS_DIRECT:
            printf("Cronus Direct");
            break;

        case SIGN_HP_PROBE_PROTOCOL:
            printf("HO Probe Protocol");
            break;

        case SIGN_NESTAR:
            printf("Nestar");
            break;

        case SIGN_ATT_STANFORD_UNIV:
            printf("AT&T Stanford University");
            break;

        case SIGN_EXCELAN:
            printf("ExceLAN");
            break;

        case SIGN_SGI_DIAGNOSTIC:
            printf("SGI Diagnostic");
            break;

        case SIGN_SGI_NETWORK_GAMES:
            printf("SGI Network Games");
            break;

        case SIGN_SGI_RESERVED:
            printf("SGI Reserved");
            break;

        case SIGN_SGI_XNS_NAMESERVER:
            printf("SGI XNS Nameserver");
            break;

        case SIGN_APOLLO_DOMAIN:
            printf("Apollo Domain");
            break;

        case SIGN_TYMSHARE:
            printf("Tymshare, Inc.");
            break;

        case SIGN_TIGAN:
        /* Tigan, Inc. */
            printf("Tigan, Inc.");
            break;

        case SIGN_RARP:
        /* Reverse Address Resolution Protocol */
            printf("RARP");
            break;

        case SIGN_AEONIC_SYSTEMS:
            printf("Aeonic Systems");
            break;

        case SIGN_IPX:
        /* IPX */
            printf("IPX");
            break;

        case SIGN_DEC_LANBRIDGE_MANAGEMENT:
            printf("DEC Lanbridge Management");
            break;

        case SIGN_DEC_DSM_DDP:
            printf("DEC DSM DDP");
            break;

        case SIGN_DEC_ARGONAUT_CONSOLE:
            printf("DEC Argonaut console");
            break;

        case SIGN_DEC_VAXELN:
            printf("DEC VAX ELN");
            break;

        case SIGN_DEC_DNS:
            printf("DEC DNS");
            break;

        case SIGN_DEC_ETHERNET_ENCRYPTION_PROTOCOL:
            printf("DEC Ethernet Encryption Protocol");
            break;

        case SIGN_DEC_DISTRIBUTED_TIME_SERVICE:
            printf("DEC Distributed Time Service");
            break;

        case SIGN_DEC_LAN_TRAFFIC_MONITOR:
            printf("DEC LAN Traffic Monitor");
            break;

        case SIGN_DEC_PATHWORKS_DECNET_NETBIOS_EMULATION:
            printf("DEC PATHWORKS DECnet NetBIOS Emulation");
            break;

        case SIGN_DEC_LOCAL_AREA_SYSTEM_TRANSPORT:
            printf("DEC Local Area System Transport");
            break;

        case SIGN_PLANNING_RESEARCH_CORP:
            printf("Planning Research Corp.");
            break;

        case SIGN_ATT_8046:
            printf("AT&T 8046");
            break;

        case SIGN_ATT_8047:
            printf("AT&T 8047");
            break;

        case SIGN_EXPERTDATA:
            printf("ExpertData");
            break;

        case SIGN_STANFORD_VMTP:
            printf("Stanford VMTP");
            break;

        case SIGN_STANFORD_V_KERNEL:
            printf("Stanford V Kernel");
            break;

        case SIGN_EVANS_SUTHERLAND:
            printf("Evans & Sutherland");
            break;

        case SIGN_LITTLE_MACHINES:
            printf("Little Machines");
            break;

        case SIGN_COUNTERPOINT_COMPUTERS_8062:
            printf("Counterpoint Computers 8062");
            break;

        case SIGN_UNIV_OF_MASS_8065:
            printf("University of Mass. 8065");
            break;

        case SIGN_UNIV_OF_MASS_8066:
            printf("University of Mass. 8066");
            break;

        case SIGN_VEECO_INTEGRATED_AUTOMATION:
            printf("VEECO Integrated Automation");
            break;

        case SIGN_GENERAL_DYNAMICS:
            printf("General Dynamics");
            break;

        case SIGN_ATT_8069:
            printf("AT&T 8069");
            break;

        case SIGN_AUTOPHON:
            printf("Autophon");
            break;

        case SIGN_COMDESIGN:
            printf("ComDesign");
            break;

        case SIGN_COMPUGRAPHIC_CORP:
            printf("Compugraphic Corp.");
            break;

        case SIGN_LANDMARK_GRAPHICS_CORP_806E:
            printf("Landmark Graphics Corp. 806E");
            break;

        case SIGN_LANDMARK_GRAPHICS_CORP_806F:
            printf("Landmark Graphics Corp. 806F");
            break;

        case SIGN_LANDMARK_GRAPHICS_CORP_8071:
            printf("Landmark Graphics Corp. 8071");
            break;

        case SIGN_LANDMARK_GRAPHICS_CORP_8072:
            printf("Landmark Graphics Corp. 8072");
            break;

        case SIGN_LANDMARK_GRAPHICS_CORP_8073:
            printf("Landmark Graphics Corp. 8073");
            break;

        case SIGN_LANDMARK_GRAPHICS_CORP_8074:
            printf("Landmark Graphics Corp. 8074");
            break;

        case SIGN_LANDMARK_GRAPHICS_CORP_8075:
            printf("Landmark Graphics Corp. 8075");
            break;

        case SIGN_LANDMARK_GRAPHICS_CORP_8076:
            printf("Landmark Graphics Corp. 8076");
            break;

        case SIGN_LANDMARK_GRAPHICS_CORP_8077:
            printf("Landmark Graphics Corp. 8077");
            break;

        case SIGN_MATRA:
            printf("Matra");
            break;

        case SIGN_DANSK_DATA_ELEKTRONIK:
            printf("Dansk Data Elektronik");
            break;

        case SIGN_MERIT_INTERNODAL:
        /* or Univ. of Michigan? */
            printf("Merit Internodal");
            break;

        case SIGN_VITALINK_COMMUNICATIONS_807D:
            printf("Vitalink Communications 807D");
            break;

        case SIGN_VITALINK_COMMUNICATIONS_807E:
            printf("Vitalink Communications 807E");
            break;

        case SIGN_VITALINK_COMMUNICATIONS_807F:
            printf("Vitalink Communications 807F");
            break;

        case SIGN_VITALINK_TRANSLAN_III_MANAGEMENT:
            printf("Vitalink TransLAN III Management");
            break;

        case SIGN_COUNTERPOINT_COMPUTERS_8081:
            printf("Counterpoint Computers 8081");
            break;

        case SIGN_COUNTERPOINT_COMPUTERS_8082:
            printf("Counterpoint Computers 8082");
            break;

        case SIGN_COUNTERPOINT_COMPUTERS_8083:
            printf("Counterpoint Computers 8083");
            break;

        case SIGN_XYPLEX_8088:
            printf("XYPLEX 8088");
            break;

        case SIGN_APPLETALK:
        /* AppleTalk over Ethernet - EtherTalk */
            printf("AppleTalk");
            break;

        case SIGN_DATABILITY_809C:
            printf("Datability 809C");
            break;

        case SIGN_SPIDER_SYSTEMS:
            printf("Spider Systems");
            break;

        case SIGN_NIXDORF_COMPUTERS:
            printf("Nixdorf Computers");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80A4:
            printf("Siemens Gammasonics 80A4");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80A5:
            printf("Siemens Gammasonics 80A5");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80A6:
            printf("Siemens Gammasonics 80A6");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80A7:
            printf("Siemens Gammasonics 80A7");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80A8:
            printf("Siemens Gammasonics 80A8");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80A9:
            printf("Siemens Gammasonics 80A9");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80AA:
            printf("Siemens Gammasonics 80AA");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80AB:
            printf("Siemens Gammasonics 80AB");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80AC:
            printf("Siemens Gammasonics 80AC");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80AD:
            printf("Siemens Gammasonics 80AD");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80AE:
            printf("Siemens Gammasonics 80AE");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80AF:
            printf("Siemens Gammasonics 80AF");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80B1:
            printf("Siemens Gammasonics 80B1");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80B2:
            printf("Siemens Gammasonics 80B2");
            break;

        case SIGN_SIEMENS_GAMMASONICS_80B3:
            printf("Siemens Gammasonics 80B3");
            break;

        case SIGN_DCA_DATA_EXCHANGE_CLUSTER_80C0:
            printf("DCA Data Exchange Cluster 80C0");
            break;

        case SIGN_DCA_DATA_EXCHANGE_CLUSTER_80C1:
            printf("DCA Data Exchange Cluster 80C1");
            break;

        case SIGN_DCA_DATA_EXCHANGE_CLUSTER_80C2:
            printf("DCA Data Exchange Cluster 80C2");
            break;

        case SIGN_DCA_DATA_EXCHANGE_CLUSTER_80C3:
            printf("DCA Data Exchange Cluster 80C3");
            break;

        case SIGN_PACER_SOFTWARE:
            printf("Pacer Software");
            break;

        case SIGN_APPLITEK_CORP:
            printf("Applitek Corp.");
            break;

        case SIGN_INTERGRAPH_CORP_80C8:
            printf("Intergraph Corp. 80C8");
            break;

        case SIGN_INTERGRAPH_CORP_80C9:
            printf("Intergraph Corp. 80C9");
            break;

        case SIGN_INTERGRAPH_CORP_80CA:
            printf("Intergraph Corp. 80CA");
            break;

        case SIGN_INTERGRAPH_CORP_80CB:
            printf("Intergraph Corp. 80CB");
            break;

        case SIGN_INTERGRAPH_CORP_80CC:
            printf("Intergraph Corp. 80CC");
            break;

        case SIGN_HARRIS_CORP_80CD:
            printf("Harris Corp. 80CD");
            break;

        case SIGN_HARRIS_CORP_80CE:
            printf("Harris Corp. 80CE");
            break;

        case SIGN_TAYLOR_INSTRUMENT_80CF:
            printf("Taylor Instrument 80CF");
            break;

        case SIGN_TAYLOR_INSTRUMENT_80D1:
            printf("Taylor Instrument 80D1");
            break;

        case SIGN_TAYLOR_INSTRUMENT_80D2:
            printf("Taylor Instrument 80D2");
            break;

        case SIGN_ROSEMOUNT_CORP_80D3:
            printf("Rosemount Corp. 80D3");
            break;

        case SIGN_ROSEMOUNT_CORP_80D4:
            printf("Rosemount Corp. 80D4");
            break;

        case SIGN_IBM_SNA:
        /* IBM SNA */
            printf("IBM SNA");
            break;

        case SIGN_VARIAN_ASSOCIATES:
            printf("Varian Associates");
            break;

        case SIGN_INTEGRATED_SOLUTIONS_TRFS_80DE:
            printf("Integrated Solutions TRFS 80DE");
            break;

        case SIGN_INTEGRATED_SOLUTIONS_TRFS_80DF:
            printf("Integrated Solutions TRFS 80DF");
            break;

/*   *DUPLICATE SIGNATURES*
     Conflicts with Datability

        case SIGN_ALLEN_BRADLEY_80E0:
            // Duplicate encoding
            printf("Allen Bradley 80E0");
            break;

        case SIGN_ALLEN_BRADLEY_80E1:
            // Duplicate encoding
            printf("Allen Bradley 80E1");
            break;

        case SIGN_ALLEN_BRADLEY_80E2:
            // Duplicate encoding
            printf("Allen Bradley 80E2");
            break;

        case SIGN_ALLEN_BRADLEY_80E3:
            // Duplicate encoding
            printf("Allen Bradley 80E3");
            break;
*/

        case SIGN_DATABILITY_80E0:
            printf("Datability 80E0");
            break;

        case SIGN_DATABILITY_80E1:
            printf("Datability 80E1");
            break;

        case SIGN_DATABILITY_80E2:
            printf("Datability 80E2");
            break;

        case SIGN_DATABILITY_80E3:
            printf("Datability 80E3");
            break;

        case SIGN_DATABILITY_80E4:
            printf("Datability 80E4");
            break;

        case SIGN_DATABILITY_80E5:
            printf("Datability 80E5");
            break;

        case SIGN_DATABILITY_80E6:
            printf("Datability 80E6");
            break;

        case SIGN_DATABILITY_80E7:
            printf("Datability 80E7");
            break;

        case SIGN_DATABILITY_80E8:
            printf("Datability 80E8");
            break;

        case SIGN_DATABILITY_80E9:
            printf("Datability 80E9");
            break;

        case SIGN_DATABILITY_80EA:
            printf("Datability 80EA");
            break;

        case SIGN_DATABILITY_80EB:
            printf("Datability 80EB");
            break;

        case SIGN_DATABILITY_80EC:
            printf("Datability 80EC");
            break;

        case SIGN_DATABILITY_80ED:
            printf("Datability 80ED");
            break;

        case SIGN_DATABILITY_80EE:
            printf("Datability 80EE");
            break;

        case SIGN_DATABILITY_80EF:
            printf("Datability 80EF");
            break;

        case SIGN_DATABILITY_80F0:
            printf("Datability 80F0");
            break;

        case SIGN_RETIX:
            printf("Retix");
            break;

        case SIGN_APPLETALK_ARP:
        /* AppleTalk ARP */
            printf("AppleTalk ARP");
            break;

        case SIGN_KINETICS_80F4:
            printf("Kinetics 80F4");
            break;

        case SIGN_KINETICS_80F5:
            printf("Kinetics 80F5");
            break;

        case SIGN_APOLLO_COMPUTER:
            printf("Apollo Computer");
            break;

        case SIGN_WELLFLEET_COMMUNICATIONS_80FF:
            printf("Wellfleet Communications 80FF");
            break;

        case SIGN_WELLFLEET_COMMUNICATIONS_8100:
            printf("Wellfleet Communications 8100");
            break;

        case SIGN_WELLFLEET_COMMUNICATIONS_8101:
            printf("Wellfleet Communications 8101");
            break;

        case SIGN_WELLFLEET_BOFL:
            printf("Wellfleet BOFL");
            break;

        case SIGN_WELLFLEET_COMMUNICATIONS_8103:
            printf("Wellfleet Communications 8103");
            break;

        case SIGN_SYMBOLICS_PRIVATE_8107:
            printf("Symbolics Private 8107");
            break;

        case SIGN_SYMBOLICS_PRIVATE_8108:
            printf("Symbolics Private 8108");
            break;

        case SIGN_SYMBOLICS_PRIVATE_8109:
            printf("Symbolics Private 8109");
            break;

        case SIGN_TALARIS:
            printf("Talaris");
            break;

        case SIGN_WATERLOO_MICROSYSTEMS:
            printf("Waterloo Microsystems");
            break;

        case SIGN_VG_LABORATORY_SYSTEMS:
            printf("VG Laboratory Systems");
            break;

        case SIGN_NETWARE:
            printf("Netware IPX/SPX (old)");
            break;

        case SIGN_NOVELL:
            printf("Novell IPX");
            break;

        case SIGN_KTI_8139:
            printf("KTI 8139");
            break;

        case SIGN_KTI_813A:
            printf("KTI 813A");
            break;

        case SIGN_KTI_813B:
            printf("KTI 813B");
            break;

        case SIGN_KTI_813C:
            printf("KTI 813C");
            break;

        case SIGN_KTI_813D:
            printf("KTI 813D");
            break;

        case SIGN_M_MUMPS:
            printf("M MUMPS");
            break;

        case SIGN_VRIJE_UNIV_AMOEBA4_RPC:
            printf("Vrije Univ. Amoeba 4 RPC");
            break;

        case SIGN_VRIJE_UNIV_FLIP:
            printf("Vrije Univ. FLIP");
            break;

        case SIGN_VRIJE_UNIV_RESERVED:
            printf("Vrije Univ. Reserved");
            break;

        case SIGN_SNMP:
        /* SNMP over Ethernet, RFC1089 */
            printf("SNMP RFC1089");
            break;

        case SIGN_TECHNICALLY_ELITE_CONCEPTS:
            printf("Technically Elite Concepts");
            break;

        case SIGN_NETBIOS:
        /* Also PowerLAN */
            printf("NetBIOS/NetBEUI (PC)");
            break;

        case SIGN_XTP:
            printf("XTP");
            break;

        case SIGN_ARTISOFT_LANTASTIC_81D6:
            printf("Artisoft Lantastic 81D6");
            break;

        case SIGN_ARTISOFT_LANTASTIC_81D7:
            printf("Artisoft Lantastic 81D7");
            break;

        case SIGN_QNX_SOFTWARE_SYSTEMS_8203:
            printf("QNX Software Systems 8203");
            break;

        case SIGN_QNX_SOFTWARE_SYSTEMS_8204:
            printf("QNX Software Systems 8204");
            break;

        case SIGN_QNX_SOFTWARE_SYSTEMS_8205:
            printf("QNX Software Systems 8205");
            break;

        case SIGN_TALARIS_MULTICAST:
            printf("Talaris Multicast");
            break;

        case SIGN_KALPANA:
            printf("Kalpana");
            break;

        case SIGN_IPV6:
        /* IPv6 */
            printf("IPv6");
            break;

        case SIGN_CONTROL_TECHNOLOGY_RDP:
            printf("Control Technology RDP");
            break;

        case SIGN_CONTROL_TECHNOLOGY_MCAST:
            printf("Control Technology MCAST");
            break;

        case SIGN_HITACHI_CABLE:
            printf("Hitachi Cable");
            break;

        case SIGN_AXIS_COMMUNICATIONS_AB:
            printf("Axis Communications AB");
            break;

        case SIGN_HP_LANPROBE:
            /* ? */
            printf("HP Lanprobe ?");
            break;

        case SIGN_LOOPBACK:
        /* Configuration Test Protocol */
            printf("Loopback");
            break;

        case SIGN_3COM_XNS:
            printf("3Com XNS");
            break;

        case SIGN_3COM_TCPIP:
            printf("3Com TCPIP");
            break;

        case SIGN_3COM_LOOPBACK_DETECTION:
            printf("3Com Loopback Detection");
            break;

        case SIGN_DECNET:
        /* Used by VAX 6220 DEBNI */
            printf("DECnet VAX 6220 DEBNI");
            break;

        case SIGN_SONIC_ARPEGGIO:
            printf("Sonic Arpeggio");
            break;

        case SIGN_BBN_VITAL_LANBRIDGE_CACHE_WAKEUPS:
            printf("BBN Vital Lanbridge Cache Wakeups");
            break;

#endif
//__CASES_C__
