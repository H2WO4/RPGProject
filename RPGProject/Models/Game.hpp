//
//  Game.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "ResourcePath.hpp"
#include "MapScreen.hpp"
#include "MapData.hpp"

class Game {

private:
    MapScreen screen;
    MapData* maps;
    
public:
    Game();
    ~Game();
    
    void draw(sf::RenderTarget& target);
    void update(float deltaTime);
};

#endif /* Game_hpp */
