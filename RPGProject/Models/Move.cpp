//
//  Move.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 20/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "Move.hpp"

float Move::interpolation(int start, int end, float progress) {
    // To smoothly update the location between two points
    return (end - start) * progress * progress + start;
}

Move::Move(int fromX, int toX, int fromY, int toY) {
    // Set coordinates
    this->fromX = fromX;
    this->toX = toX;
    this->fromY = fromY;
    this->toY = toY;
}

float Move::getX(float progress) {
    return interpolation(fromX, toX, progress);
}

float Move::getY(float progress) {
    return interpolation(fromY, toY, progress);
}

void Move::cancelMove() {
    toX = fromX;
    toY = fromY;
}
