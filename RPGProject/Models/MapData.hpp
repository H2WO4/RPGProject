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
#include "Move.hpp"
#include "TileSet.hpp"
#include "Object.hpp"

class MapData {
    
private:
    std::string name;
    int width;
    int height;
    
    TileSet * tileset;
    
    int* layer1;
    int* layer2;
    int* layer3;
    
    std::vector<Object> objects;

public:
    MapData(std::string name, TileSet * tileset);
    ~MapData();
    
    bool isMoveAllowed(Move &move);
    Object* getObject(int x, int y);
    
    friend class TileMap;
    friend class MapScreen;
    friend class Game;
    
};

#endif /* MapData_hpp */
