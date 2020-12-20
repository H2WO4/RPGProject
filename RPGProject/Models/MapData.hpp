//
//  MapData.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 20/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef MapData_hpp
#define MapData_hpp

#include <string>
#include <fstream>

#include "ResourcePath.hpp"

class MapData {

public:
    std::string name;
    int* layer1;
    int* layer2;
    int* layer3;
    
    MapData(std::string name);
    ~MapData();
    
};

#endif /* MapData_hpp */
