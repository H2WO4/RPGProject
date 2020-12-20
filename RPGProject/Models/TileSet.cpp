//
//  TileSet.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 20/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "TileSet.hpp"

TileSet::TileSet(std::string name) {
    // Store name
    this->name = name;
    
    // Load texture
    texture.loadFromFile(resourcePath() + name + ".png");
    
    // Load collision data
    // TODO
}

bool TileSet::isMoveAllowed(int tile) {
    // Empty tile, ok
    if (tile == 0) {
        return true;
    }
    
    // Check if tile is allowed
    if (tile == 5 || tile == 25 || tile == 27 || tile == 29 || tile == 42 || tile == 44 || tile == 45 || tile == 48 || tile == 49 || tile == 64 || tile == 65 || tile == 269) {
        return true;
    }
    
    // Move not allowed
    return false;
}
