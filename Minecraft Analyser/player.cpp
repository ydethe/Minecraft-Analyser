//
//  player.cpp
//  Minecraft Analyser
//
//  Created by Yann Blaudin de Thé on 19/02/12.
//  Copyright (c) 2012 EADS Astrium ST - P2010 - MAE. All rights reserved.
//

#include "player.h"

Player::Player() {}

Player::~Player() {}


void Player::dispPosition() const {
    std::cout << x << ", " << y << ", " << z << std::endl;
}

void Player::dispLook() const {
    std::cout << yaw << ", " << pitch << std::endl;
}
