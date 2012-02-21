//
//  player.h
//  Minecraft Analyser
//
//  Created by Yann Blaudin de Thé on 19/02/12.
//  Copyright (c) 2012 EADS Astrium ST - P2010 - MAE. All rights reserved.
//

#ifndef Minecraft_Analyser_player_h
#define Minecraft_Analyser_player_h

#include <iostream>

class Player {
public:
    double x, y, z;
    float yaw, pitch;
    
public:
    Player();
    ~Player();
    
    void dispPosition() const;
    void dispLook() const;
};

#endif
