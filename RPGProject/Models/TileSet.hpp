//
//  TileSet.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 20/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef TileSet_hpp
#define TileSet_hpp

#include <SFML/Graphics.hpp>
#include <string>

#include "ResourcePath.hpp"

class TileSet {

private:
    std::string name;
    sf::Texture texture;
    
public:
    TileSet(std::string name);
    
    bool isMoveAllowed(int tile);
    
    friend class TileMap;

};

#endif /* TileSet_hpp */
