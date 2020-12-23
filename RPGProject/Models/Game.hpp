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
#include "TitleScreen.hpp"
#include "MapScreen.hpp"
#include "MapData.hpp"

class Game {

private:
    int currentScreenID = 0;
    TitleScreen titleScreen;
    MapScreen mapScreen;
    
    TileSet* tilesets;
    MapData* maps;
    
public:
    Game();
    
    Screen* getCurrentScreen();
    void unloadCurrentScreen();
    void loadNextScreen();
    
    void draw(sf::RenderTarget& target);
    void update(float deltaTime);
    void resize(sf::RenderWindow &window);
    void handle(sf::Keyboard::Key key);
    
};

#endif /* Game_hpp */
