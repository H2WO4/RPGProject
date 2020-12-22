//
//  Teleport.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 22/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "Teleport.hpp"

Teleport::Teleport(int targetMap, int targetX, int targetY) {
    this->targetMap = targetMap;
    this->targetX = targetX;
    this->targetY = targetY;
}
