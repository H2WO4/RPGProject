//
//  MapData.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 20/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "MapData.hpp"

MapData::MapData(std::string name) {
    // Save name
    this->name = name;
    
    // Read data from file
    std::ifstream infile(resourcePath() + name + ".map");
    
    // Extract header
    int width, height, layers;
    infile >> width >> height >> layers;
    
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
    
    // Read extra data
    // TODO
}

MapData::~MapData() {
    // Clear pointers
    delete layer1;
    delete layer2;
    delete layer3;
}
