//
//  unpack.cpp
//  Minecraft Analyser
//
//  Created by Yann Blaudin de Thé on 19/02/12.
//  Copyright (c) 2012 EADS Astrium ST - P2010 - MAE. All rights reserved.
//

#include <iostream>

#include "unpack.h"

double unpack_double(const unsigned char *p) {
    double x;
    
    char buf[8];
    char *d = &buf[7];
    int i;
    
    for (i = 0; i < 8; i++) {
        *d-- = *p++;
    }
    memcpy(&x, buf, 8);
    return x;
}

float unpack_float(const unsigned char *p) {
    float x;
    char buf[4];
    char *d = &buf[3];
    int i;
    
    for (i = 0; i < 4; i++) {
        *d-- = *p++;
    }
    memcpy(&x, buf, 4);

    return x;
}

int unpack_int(const unsigned char *p) {
    int x;
    char buf[4];
    char *d = &buf[3];
    int i;
    
    for (i = 0; i < 4; i++) {
        *d-- = *p++;
    }
    memcpy(&x, buf, 4);
    
    return x;
}

short unpack_short(const unsigned char *p) {
    short x;
    
    char buf[2];
    char *d = &buf[1];
    int i;
    
    for (i = 0; i < 2; i++) {
        *d-- = *p++;
    }
    memcpy(&x, buf, 2);
    
    return x;
}

uint8_t unpack_byte(const unsigned char *p) {
    uint8_t x;
    
    x = (uint8_t)(*p);
    
    return x;
}



