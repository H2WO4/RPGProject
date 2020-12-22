//
//  Game.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <string>

#include "ResourcePath.hpp"
#include "MapScreen.hpp"
#include "MapData.hpp"

class Game {

private:
    MapScreen screen;
    TileSet* tilesets;
    MapData* maps;
    
public:
    Game();
    
    void draw(sf::RenderTarget& target);
    void update(float deltaTime);
    void resize(sf::RenderWindow &window);
    void handle(sf::Keyboard::Key key);
    
    MapData* getMapByName(std::string name);
    
};

#endif /* Game_hpp */
