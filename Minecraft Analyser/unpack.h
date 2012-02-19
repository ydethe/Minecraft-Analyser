//
//  unpack.h
//  Minecraft Analyser
//
//  Created by Yann Blaudin de Thé on 18/02/12.
//  Copyright (c) 2012 EADS Astrium ST - P2010 - MAE. All rights reserved.
//

#ifndef Minecraft_Analyser_unpack_h
#define Minecraft_Analyser_unpack_h

double unpack(const unsigned char *p)
{
//    if (double_format == unknown_format) {
//        unsigned char sign;
//        int e;
//        unsigned int fhi, flo;
//        double x;
//        int incr = 1;
//        
//        if (le) {
//            p += 7;
//            incr = -1;
//        }
//        
//        /* First byte */
//        sign = (*p >> 7) & 1;
//        e = (*p & 0x7F) << 4;
//        
//        p += incr;
//        
//        /* Second byte */
//        e |= (*p >> 4) & 0xF;
//        fhi = (*p & 0xF) << 24;
//        p += incr;
//        
//        if (e == 2047) {
//            PyErr_SetString(
//                            PyExc_ValueError,
//                            "can't unpack IEEE 754 special value "
//                            "on non-IEEE platform");
//            return -1.0;
//        }
//        
//        /* Third byte */
//        fhi |= *p << 16;
//        p += incr;
//        
//        /* Fourth byte */
//        fhi |= *p  << 8;
//        p += incr;
//        
//        /* Fifth byte */
//        fhi |= *p;
//        p += incr;
//        
//        /* Sixth byte */
//        flo = *p << 16;
//        p += incr;
//        
//        /* Seventh byte */
//        flo |= *p << 8;
//        p += incr;
//        
//        /* Eighth byte */
//        flo |= *p;
//        
//        x = (double)fhi + (double)flo / 16777216.0; /* 2**24 */
//        x /= 268435456.0; /* 2**28 */
//        
//        if (e == 0)
//            e = -1022;
//        else {
//            x += 1.0;
//            e -= 1023;
//        }
//        x = ldexp(x, e);
//        
//        if (sign)
//            x = -x;
//        
//        return x;
//    }
//    else {
        double x;
        
//        if ((double_format == ieee_little_endian_format && !le)
//            || (double_format == ieee_big_endian_format && le)) {
          if (true) {
            char buf[8];
            char *d = &buf[7];
            int i;
            
            for (i = 0; i < 8; i++) {
                *d-- = *p++;
            }
            memcpy(&x, buf, 8);
        }
        else {
            memcpy(&x, p, 8);
        }
        
        return x;
//    }
}


#endif
