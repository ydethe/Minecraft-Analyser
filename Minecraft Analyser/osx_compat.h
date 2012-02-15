//
//  osx_compat.h
//  Minecraft Analyser
//
//  Created by Yann Blaudin de Thé on 15/02/12.
//  Copyright (c) 2012 EADS Astrium ST - P2010 - MAE. All rights reserved.
//

#ifndef Minecraft_Analyser_osx_compat_h
#define Minecraft_Analyser_osx_compat_h

#include <limits.h>
#include <unistd.h>
#include <inttypes.h>

typedef unsigned char   u_char;
typedef unsigned short  u_short;
typedef unsigned int    u_int;
typedef uint16_t u_int16_t;
typedef uint32_t u_int32_t;
typedef uint8_t u_int8_t;
typedef unsigned int    u_int_32t;
typedef unsigned long   u_long;
typedef unsigned short  ushort;

struct iphdr 
{ 
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned int ihl:4;
    unsigned int version:4;
#elif __BYTE_ORDER == __BIG_ENDIAN
    unsigned int version:4;
    unsigned int ihl:4;
#else
# error  "Please fix <bits/endian.h>"
#endif
    u_int8_t tos;
    u_int16_t tot_len;
    u_int16_t id;
    u_int16_t frag_off;
    u_int8_t ttl;
    u_int8_t protocol;
    u_int16_t check;
    u_int32_t saddr;
    u_int32_t daddr;
    /*The options start here. */
};

#endif
