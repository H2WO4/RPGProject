//
//  MapData.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 20/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "MapData.hpp"

MapData::MapData(std::string name, TileSet * tileset) {
    // Save name
    this->name = name;
    
    // Save reference of tileset
    this->tileset = tileset;
    
    // Read data from file
    std::ifstream infile(resourcePath() + name + ".map");
    
    // Extract header
    int layers, objectsCount;
    infile >> width >> height >> layers >> objectsCount;
    
    // Create pointers
    layer1 = new int [width * height];
    layer2 = new int [width * height];
    layer3 = new int [width * height];
    
    // Read layers
    if (layers >= 1) {
        for (int i = 0; i < width * height; i++) {
            infile >> layer1[i];
        }
    } else {
        for (int i = 0; i < width * height; i++) {
            layer1[i] = 0;
        }
    }
    if (layers >= 2) {
        for (int i = 0; i < width * height; i++) {
            infile >> layer2[i];
        }
    } else {
        for (int i = 0; i < width * height; i++) {
            layer2[i] = 0;
        }
    }
    if (layers >= 3) {
        for (int i = 0; i < width * height; i++) {
            infile >> layer3[i];
        }
    } else {
        for (int i = 0; i < width * height; i++) {
            layer3[i] = 0;
        }
    }
    
    // Read objects
    for (int i = 0; i < objectsCount; i++) {
        // Get type
        std::string type;
        infile >> type;
        
        // Check it to create object
        if (type == "teleport") {
            int x, y, targetMap, targetX, targetY;
            infile >> x >> y >> targetMap >> targetX >> targetY;
            objects.push_back(Object(x, y, Teleport(targetMap, targetX, targetY)));
        }
    }
}

MapData::~MapData() {
    // Clear pointers
    delete layer1;
    delete layer2;
    delete layer3;
}

bool MapData::isMoveAllowed(Move &move) {
    // Get distination x and y
    int x = move.getX(1.0f);
    int y = move.getY(1.0f);
    
    // Check if it is in map area (don't allow to go outside)
    if (x < 0 || y < 0 || x >= width || y >= height) {
        return false;
    }
    
    // Get tiles for this location
    int tile1 = layer1[x + y * width];
    int tile2 = layer2[x + y * width];
    
    // Check if tiles are allowed for move
    return tileset->isMoveAllowed(tile1) && tileset->isMoveAllowed(tile2);
}

Object* MapData::getObject(int x, int y) {
    // Iterate objects to find corresponding one
    for (int i = 0; i < objects.size(); i++) {
        Object * object = &objects[i];
        if (object->getX() == x && object->getY() == y) {
            return object;
        }
    }
    
    // No object found
    return nullptr;
}
