#ifndef _SIGNATURES_H_
#define _SIGNATURES_H_

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
 * @brief Protocol signatures for etherframe.c

 ONLY REGISTERED SIGNATURES

 All defined signatures are checked,
 except commented signatures of Allen-Bradley
 that conflict with Datability.
*/

/*
Syntax:
#define (SIGNATURE) (ENCODING)
*/

/** @brief Conflicts with length field of IEEE 802.3 */
#define SIGN_XEROX_PUP                              0x0200

/** @brief Conflicts with length field of IEEE 802.3 */
#define SIGN_XEROX_PUP_AT                           0x0201

/** @brief Conflicts with length field of IEEE 802.3 */
#define SIGN_NIXDORF                                0x0400

#define SIGN_XEROX_NS_IDP                           0x0600
#define SIGN_XNS_AT                                 0x0601

/** @brief IPv4 */
#define SIGN_IPV4                                   0x0800

#define SIGN_X75                                    0x0801
#define SIGN_NBS                                    0x0802
#define SIGN_ECMA                                   0x0803
#define SIGN_CHAOSNET                               0x0804
#define SIGN_X25                                    0x0805

/** @brief Address Resolution Protocol */
#define SIGN_ARP                                    0x0806

#define SIGN_XNS_COMPAT                             0x0807
#define SIGN_SYMBOLICS_PRIVATE_081C                 0x081C

#define SIGN_XYPLEX_0888                            0x0888
#define SIGN_XYPLEX_0889                            0x0889
#define SIGN_XYPLEX_088A                            0x088A

#define SIGN_UNGERMANN_BASS                         0x0900

#define SIGN_XEROX_IEEE_PUP                         0x0A00
#define SIGN_XEROX_IEEE_PUP_AT                      0x0A01

#define SIGN_BANYAN_SYSTEMS                         0x0BAD
#define SIGN_BANYAN_VINES_ECHO                      0x0BAF

#define SIGN_BERKELEY_TRAILER_NEGOT                 0x1000
#define SIGN_BERKELEY_TRAILER_ENCAP_1001            0x1001
#define SIGN_BERKELEY_TRAILER_ENCAP_1002            0x1002
#define SIGN_BERKELEY_TRAILER_ENCAP_1003            0x1003
#define SIGN_BERKELEY_TRAILER_ENCAP_1004            0x1004
#define SIGN_BERKELEY_TRAILER_ENCAP_1005            0x1005
#define SIGN_BERKELEY_TRAILER_ENCAP_1006            0x1006
#define SIGN_BERKELEY_TRAILER_ENCAP_1007            0x1007
#define SIGN_BERKELEY_TRAILER_ENCAP_1008            0x1008
#define SIGN_BERKELEY_TRAILER_ENCAP_1009            0x1009
#define SIGN_BERKELEY_TRAILER_ENCAP_100A            0x100A
#define SIGN_BERKELEY_TRAILER_ENCAP_100B            0x100B
#define SIGN_BERKELEY_TRAILER_ENCAP_100C            0x100C
#define SIGN_BERKELEY_TRAILER_ENCAP_100D            0x100D
#define SIGN_BERKELEY_TRAILER_ENCAP_100E            0x100E
#define SIGN_BERKELEY_TRAILER_ENCAP_100F            0x100F

#define SIGN_DCA_MULTICAST                          0x1234
#define SIGN_VALID_SYSTEM_PROTOCOL                  0x1600
#define SIGN_ARTIFICIAL_HORIZONS                    0x1989
#define SIGN_DATAPOINT_CORP                         0x1995
#define SIGN_PCS_BASIC_BLOCK_PROT                   0x4242
#define SIGN_LITTLE_BIG_LAN_DIAGNOSTIC              0x424C
#define SIGN_THD_DIDDLE                             0x4321
#define SIGN_LITTLE_BIG_LAN                         0x4C42
#define SIGN_BBN_SIMNET_PRIVATE                     0x5208

#define SIGN_DECNET_EXPERIMENTAL                    0x6000
#define SIGN_DECNET_MOP_ASSISTANCE                  0x6001
#define SIGN_DECNET_MOP_CONSOLE                     0x6002
#define SIGN_DECNET_PHASE_IV                        0x6003

#define SIGN_DEC_LAT                                0x6004
#define SIGN_DEC_DIAGNOSTIC_PROT                    0x6005
#define SIGN_DEC_CUSTOMER_PROT                      0x6006
#define SIGN_DEC_VAX_CLUSTER                        0x6007
#define SIGN_DEC_AMBER                              0x6008
#define SIGN_DEC_MUMPS                              0x6009

#define SIGN_3COM_CORP_6010                         0x6010
#define SIGN_3COM_CORP_6011                         0x6011
#define SIGN_3COM_CORP_6012                         0x6012
#define SIGN_3COM_CORP_6013                         0x6013
#define SIGN_3COM_CORP_6014                         0x6014

/** @brief Ungermann-Bass */
#define SIGN_UB_DOWNLOAD                            0x7000
#define SIGN_UB_NIU                                 0x7001
#define SIGN_UB_DIAGNOSTIC                          0x7002
#define SIGN_UB_BRIDGE_NMC                          0x7003
#define SIGN_UB_BRIDGE_SPANNING_TREE                0x7005
#define SIGN_OS9_MICROWARE                          0x7007
#define SIGN_OS9_NET                                0x7009

#define SIGN_SINTROM_7020                           0x7020
#define SIGN_SINTROM_7021                           0x7021
#define SIGN_SINTROM_7022                           0x7022
#define SIGN_SINTROM_7023                           0x7023
#define SIGN_SINTROM_7024                           0x7024
#define SIGN_SINTROM_7025                           0x7025
#define SIGN_SINTROM_7026                           0x7026
#define SIGN_SINTROM_7027                           0x7027
#define SIGN_SINTROM_7028                           0x7028
#define SIGN_SINTROM_7029                           0x7029

#define SIGN_RACAL_INTERLAN                         0x7030
#define SIGN_PRIME_NTS                              0x7031
#define SIGN_CABLETRON                              0x7034

#define SIGN_CRONUS_VLN                             0x8003
#define SIGN_CRONUS_DIRECT                          0x8004

#define SIGN_HP_PROBE_PROTOCOL                      0x8005
#define SIGN_NESTAR                                 0x8006
#define SIGN_ATT_STANFORD_UNIV                      0x8008
#define SIGN_EXCELAN                                0x8010

#define SIGN_SGI_DIAGNOSTIC                         0x8013
#define SIGN_SGI_NETWORK_GAMES                      0x8014
#define SIGN_SGI_RESERVED                           0x8015
#define SIGN_SGI_XNS_NAMESERVER                     0x8016

#define SIGN_APOLLO_DOMAIN                          0x8019

/** @brief Tymshare, Inc. */
#define SIGN_TYMSHARE                               0x802E

/** @brief Tigan, Inc. */
#define SIGN_TIGAN                                  0x802F

/** @brief Reverse Address Resolution Protocol */
#define SIGN_RARP                                   0x8035

#define SIGN_AEONIC_SYSTEMS                         0x8036

/** @brief IPX */
#define SIGN_IPX                                    0x8037

#define SIGN_DEC_LANBRIDGE_MANAGEMENT               0x8038
#define SIGN_DEC_DSM_DDP                            0x8039
#define SIGN_DEC_ARGONAUT_CONSOLE                   0x803A
#define SIGN_DEC_VAXELN                             0x803B
#define SIGN_DEC_DNS                                0x803C
#define SIGN_DEC_ETHERNET_ENCRYPTION_PROTOCOL       0x803D
#define SIGN_DEC_DISTRIBUTED_TIME_SERVICE           0x803E
#define SIGN_DEC_LAN_TRAFFIC_MONITOR                0x803F
#define SIGN_DEC_PATHWORKS_DECNET_NETBIOS_EMULATION 0x8040
#define SIGN_DEC_LOCAL_AREA_SYSTEM_TRANSPORT        0x8041

#define SIGN_PLANNING_RESEARCH_CORP                 0x8044

#define SIGN_ATT_8046                               0x8046
#define SIGN_ATT_8047                               0x8047

#define SIGN_EXPERTDATA                             0x8049

#define SIGN_STANFORD_VMTP                          0x805B
#define SIGN_STANFORD_V_KERNEL                      0x805C

#define SIGN_EVANS_SUTHERLAND                       0x805D
#define SIGN_LITTLE_MACHINES                        0x8060
#define SIGN_COUNTERPOINT_COMPUTERS_8062            0x8062

#define SIGN_UNIV_OF_MASS_8065                      0x8065
#define SIGN_UNIV_OF_MASS_8066                      0x8066

#define SIGN_VEECO_INTEGRATED_AUTOMATION            0x8067
#define SIGN_GENERAL_DYNAMICS                       0x8068
#define SIGN_ATT_8069                               0x8069
#define SIGN_AUTOPHON                               0x806A
#define SIGN_COMDESIGN                              0x806C
#define SIGN_COMPUGRAPHIC_CORP                      0x806D

#define SIGN_LANDMARK_GRAPHICS_CORP_806E            0x806E
#define SIGN_LANDMARK_GRAPHICS_CORP_806F            0x806F
#define SIGN_LANDMARK_GRAPHICS_CORP_8071            0x8071
#define SIGN_LANDMARK_GRAPHICS_CORP_8072            0x8072
#define SIGN_LANDMARK_GRAPHICS_CORP_8073            0x8073
#define SIGN_LANDMARK_GRAPHICS_CORP_8074            0x8074
#define SIGN_LANDMARK_GRAPHICS_CORP_8075            0x8075
#define SIGN_LANDMARK_GRAPHICS_CORP_8076            0x8076
#define SIGN_LANDMARK_GRAPHICS_CORP_8077            0x8077

#define SIGN_MATRA                                  0x807A
#define SIGN_DANSK_DATA_ELEKTRONIK                  0x807B

/** @brief or Univ. of Michigan? */
#define SIGN_MERIT_INTERNODAL                       0x807C

#define SIGN_VITALINK_COMMUNICATIONS_807D           0x807D
#define SIGN_VITALINK_COMMUNICATIONS_807E           0x807E
#define SIGN_VITALINK_COMMUNICATIONS_807F           0x807F
#define SIGN_VITALINK_TRANSLAN_III_MANAGEMENT       0x8080

#define SIGN_COUNTERPOINT_COMPUTERS_8081            0x8081
#define SIGN_COUNTERPOINT_COMPUTERS_8082            0x8082
#define SIGN_COUNTERPOINT_COMPUTERS_8083            0x8083

#define SIGN_XYPLEX_8088                            0x8088

/** @brief AppleTalk over Ethernet: EtherTalk */
#define SIGN_APPLETALK                              0x809B

#define SIGN_DATABILITY_809C                        0x809C
#define SIGN_SPIDER_SYSTEMS                         0x809F
#define SIGN_NIXDORF_COMPUTERS                      0x80A3

#define SIGN_SIEMENS_GAMMASONICS_80A4               0x80A4
#define SIGN_SIEMENS_GAMMASONICS_80A5               0x80A5
#define SIGN_SIEMENS_GAMMASONICS_80A6               0x80A6
#define SIGN_SIEMENS_GAMMASONICS_80A7               0x80A7
#define SIGN_SIEMENS_GAMMASONICS_80A8               0x80A8
#define SIGN_SIEMENS_GAMMASONICS_80A9               0x80A9
#define SIGN_SIEMENS_GAMMASONICS_80AA               0x80AA
#define SIGN_SIEMENS_GAMMASONICS_80AB               0x80AB
#define SIGN_SIEMENS_GAMMASONICS_80AC               0x80AC
#define SIGN_SIEMENS_GAMMASONICS_80AD               0x80AD
#define SIGN_SIEMENS_GAMMASONICS_80AE               0x80AE
#define SIGN_SIEMENS_GAMMASONICS_80AF               0x80AF
#define SIGN_SIEMENS_GAMMASONICS_80B1               0x80B1
#define SIGN_SIEMENS_GAMMASONICS_80B2               0x80B2
#define SIGN_SIEMENS_GAMMASONICS_80B3               0x80B3

#define SIGN_DCA_DATA_EXCHANGE_CLUSTER_80C0         0x80C0
#define SIGN_DCA_DATA_EXCHANGE_CLUSTER_80C1         0x80C1
#define SIGN_DCA_DATA_EXCHANGE_CLUSTER_80C2         0x80C2
#define SIGN_DCA_DATA_EXCHANGE_CLUSTER_80C3         0x80C3

#define SIGN_PACER_SOFTWARE                         0x80C6
#define SIGN_APPLITEK_CORP                          0x80C7

#define SIGN_INTERGRAPH_CORP_80C8                   0x80C8
#define SIGN_INTERGRAPH_CORP_80C9                   0x80C9
#define SIGN_INTERGRAPH_CORP_80CA                   0x80CA
#define SIGN_INTERGRAPH_CORP_80CB                   0x80CB
#define SIGN_INTERGRAPH_CORP_80CC                   0x80CC

#define SIGN_HARRIS_CORP_80CD                       0x80CD
#define SIGN_HARRIS_CORP_80CE                       0x80CE

#define SIGN_TAYLOR_INSTRUMENT_80CF                 0x80CF
#define SIGN_TAYLOR_INSTRUMENT_80D1                 0x80D1
#define SIGN_TAYLOR_INSTRUMENT_80D2                 0x80D2

#define SIGN_ROSEMOUNT_CORP_80D3                    0x80D3
#define SIGN_ROSEMOUNT_CORP_80D4                    0x80D4

/** @brief IBM SNA */
#define SIGN_IBM_SNA                                0x80D5

#define SIGN_VARIAN_ASSOCIATES                      0x80DD

#define SIGN_INTEGRATED_SOLUTIONS_TRFS_80DE         0x80DE
#define SIGN_INTEGRATED_SOLUTIONS_TRFS_80DF         0x80DF

/*   *DUPLICATE SIGNATURES*
     Conflicts with Datability

#define SIGN_ALLEN_BRADLEY_80E0                     0x80E0
        // Duplicate
#define SIGN_ALLEN_BRADLEY_80E1                     0x80E1
        // Duplicate
#define SIGN_ALLEN_BRADLEY_80E2                     0x80E2
        // Duplicate
#define SIGN_ALLEN_BRADLEY_80E3                     0x80E3
        // Duplicate
*/

#define SIGN_DATABILITY_80E0                        0x80E0
#define SIGN_DATABILITY_80E1                        0x80E1
#define SIGN_DATABILITY_80E2                        0x80E2
#define SIGN_DATABILITY_80E3                        0x80E3
#define SIGN_DATABILITY_80E4                        0x80E4
#define SIGN_DATABILITY_80E5                        0x80E5
#define SIGN_DATABILITY_80E6                        0x80E6
#define SIGN_DATABILITY_80E7                        0x80E7
#define SIGN_DATABILITY_80E8                        0x80E8
#define SIGN_DATABILITY_80E9                        0x80E9
#define SIGN_DATABILITY_80EA                        0x80EA
#define SIGN_DATABILITY_80EB                        0x80EB
#define SIGN_DATABILITY_80EC                        0x80EC
#define SIGN_DATABILITY_80ED                        0x80ED
#define SIGN_DATABILITY_80EE                        0x80EE
#define SIGN_DATABILITY_80EF                        0x80EF
#define SIGN_DATABILITY_80F0                        0x80F0

#define SIGN_RETIX                                  0x80F2

/** @brief AppleTalk ARP */
#define SIGN_APPLETALK_ARP                          0x80F3

#define SIGN_KINETICS_80F4                          0x80F4
#define SIGN_KINETICS_80F5                          0x80F5

#define SIGN_APOLLO_COMPUTER                        0x80F7

#define SIGN_WELLFLEET_COMMUNICATIONS_80FF          0x80FF
#define SIGN_WELLFLEET_COMMUNICATIONS_8100          0x8100
#define SIGN_WELLFLEET_COMMUNICATIONS_8101          0x8101
#define SIGN_WELLFLEET_BOFL                         0x8102
#define SIGN_WELLFLEET_COMMUNICATIONS_8103          0x8103

#define SIGN_SYMBOLICS_PRIVATE_8107                 0x8107
#define SIGN_SYMBOLICS_PRIVATE_8108                 0x8108
#define SIGN_SYMBOLICS_PRIVATE_8109                 0x8109

#define SIGN_TALARIS                                0x812B
#define SIGN_WATERLOO_MICROSYSTEMS                  0x8130
#define SIGN_VG_LABORATORY_SYSTEMS                  0x8131

#define SIGN_NETWARE                                0x8137
#define SIGN_NOVELL                                 0x8138

#define SIGN_KTI_8139                               0x8139
#define SIGN_KTI_813A                               0x813A
#define SIGN_KTI_813B                               0x813B
#define SIGN_KTI_813C                               0x813C
#define SIGN_KTI_813D                               0x813D

#define SIGN_M_MUMPS                                0x813F

/** @brief Amoeba 4 Remote Procedure Call */
#define SIGN_VRIJE_UNIV_AMOEBA4_RPC                 0x8145
/** @brief Fast Local Internet Protocol */
#define SIGN_VRIJE_UNIV_FLIP                        0x8146
#define SIGN_VRIJE_UNIV_RESERVED                    0x8147

/** @brief SNMP over Ethernet, RFC1089 */
#define SIGN_SNMP                                   0x814C

#define SIGN_TECHNICALLY_ELITE_CONCEPTS             0x814F

/** @brief NetBIOS and also PowerLAN */
#define SIGN_NETBIOS                                0x8191

#define SIGN_XTP                                    0x817D

#define SIGN_ARTISOFT_LANTASTIC_81D6                0x81D6
#define SIGN_ARTISOFT_LANTASTIC_81D7                0x81D7

#define SIGN_QNX_SOFTWARE_SYSTEMS_8203              0x8203
#define SIGN_QNX_SOFTWARE_SYSTEMS_8204              0x8204
#define SIGN_QNX_SOFTWARE_SYSTEMS_8205              0x8205

#define SIGN_TALARIS_MULTICAST                      0x852B
#define SIGN_KALPANA                                0x8582

/** @brief IPv6 */
#define SIGN_IPV6                                   0x86DD

#define SIGN_CONTROL_TECHNOLOGY_RDP                 0x8739
#define SIGN_CONTROL_TECHNOLOGY_MCAST               0x873A

#define SIGN_HITACHI_CABLE                          0x8820
#define SIGN_AXIS_COMMUNICATIONS_AB                 0x8856

/** @brief ? */
#define SIGN_HP_LANPROBE                            0x8888

/** @brief Configuration Test Protocol */
#define SIGN_LOOPBACK                               0x9000

#define SIGN_3COM_XNS                               0x9001
#define SIGN_3COM_TCPIP                             0x9002
#define SIGN_3COM_LOOPBACK_DETECTION                0x9003

/** @brief DECnet: Used by VAX 6220 DEBNI */
#define SIGN_DECNET                                 0xAAAA

#define SIGN_SONIC_ARPEGGIO                         0xFAF5
#define SIGN_BBN_VITAL_LANBRIDGE_CACHE_WAKEUPS      0xFF00


#endif
//_SIGNATURES_H_
