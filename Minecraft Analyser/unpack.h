//
//  unpack.h
//  Minecraft Analyser
//
//  Created by Yann Blaudin de Thé on 18/02/12.
//  Copyright (c) 2012 EADS Astrium ST - P2010 - MAE. All rights reserved.
//

#ifndef Minecraft_Analyser_unpack_h
#define Minecraft_Analyser_unpack_h

double unpack_double(const unsigned char *p);
float unpack_float(const unsigned char *p);

int unpack_int(const unsigned char *p);
short unpack_short(const unsigned char *p);
uint8_t unpack_byte(const unsigned char *p);

#endif
