//
//  TeleportObject.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 20/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "TeleportObject.hpp"

TeleportObject::TeleportObject(int x, int y, int targetMap, int targetX, int targetY) {
    this->x = x;
    this->y = y;
    this->targetMap = targetMap;
    this->targetX = targetX;
    this->targetY = targetY;
}

bool TeleportObject::isRunning() {
    return running;
}

void TeleportObject::setRunning() {
    running = true;
}

void TeleportObject::finish() {
    running = false;
}
