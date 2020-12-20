//
//  Game.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "Game.hpp"

Game::Game() {
    // Load resources
    maps = new MapData[1] {
        MapData("default")
    };
    
    // Give to screen the default map
    screen.loadMap(maps[0]);
}

Game::~Game() {
    
}

void Game::draw(sf::RenderTarget &target) {
    // Draw the screen
    target.draw(screen);
}

void Game::update(float deltaTime) {
    // Send update to screen
    screen.update(deltaTime);
}
