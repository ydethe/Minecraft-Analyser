//
//  decomp.cpp
//  Minecraft Analyser
//
//  Created by Yann Blaudin de Thé on 21/02/12.
//  Copyright (c) 2012 EADS Astrium ST - P2010 - MAE. All rights reserved.
//

#include <iostream>
#include <zlib.h>

bool inflate(int len, char* in, char* out) {
    //int len = net.recvInt();
    //char *in = new char[len];
    //net.recvByteArray(in, len);

    //Output memory is at most 16*16*128*2.5 bytes
    //char *out = new char[100000];

    int ret;
    z_stream strm;

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;
    ret = inflateInit(&strm);

    if (ret != Z_OK){
        std::cerr << "Zlib error: inflateInit() failed" << std::endl;
        return -1;
        }
        
        strm.avail_in = len;
        strm.next_in = (Bytef*)in; 
        strm.avail_out = 100000;
        strm.next_out = (Bytef*)out; 
        
        ret = inflate(&strm, Z_NO_FLUSH);
        
        switch (ret) {
            case Z_NEED_DICT:
                ret = Z_DATA_ERROR;   
            case Z_DATA_ERROR:
            case Z_MEM_ERROR:
                std::cerr << "Zlib error: inflate()" << std::endl;
                return ret;
        }               
        inflateEnd(&strm);    
        delete []in;
        //Data is now in "out" buffer
}

