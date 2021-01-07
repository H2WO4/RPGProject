//
//  Game.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "Game.hpp"

const int maps_count = 2;
const int tilesets_count = 1;

Game::Game() {
    // Load tilesets
    tilesets = new TileSet[tilesets_count] {
        TileSet("tileset")
    };
    
    // Load maps
    maps = new MapData[maps_count] {
        MapData("PopolTown", &tilesets[0]),
        MapData("Route1", &tilesets[0])
    };
    
    // Give to map screen maps
    mapScreen.setMaps(maps);
    loadNextScreen();
}

Screen* Game::getCurrentScreen() {
    // Return current shown screen
    if (currentScreenID == 0) {
        // Title screen
        return &titleScreen;
    } else if (currentScreenID == 1) {
        // Map screen
        return &mapScreen;
    }
    return nullptr;
}

void Game::unloadCurrentScreen() {
    // Check current shown screen
    if (currentScreenID == 0) {
        // Title screen: stop music
        titleScreen.unload();
    } else if (currentScreenID == 1) {
        // Map screen: load default map
        mapScreen.loadMap(0);
    }
}

void Game::loadNextScreen() {
    // Check current shown screen
    if (currentScreenID == 0) {
        // Title screen: start music
        titleScreen.load();
    } else if (currentScreenID == 1) {
        // Map screen: load default map
        mapScreen.loadMap(0);
    }
}

void Game::draw(sf::RenderTarget &target) {
    // Draw the screen
    target.draw(*getCurrentScreen());
}

void Game::update(float deltaTime) {
    // Start by checking if screen should be changed
    if (getCurrentScreen()->shouldChangeScreen()) {
        // Unload current screen
        unloadCurrentScreen();
        
        // Change screen
        currentScreenID = getCurrentScreen()->getNextScreenID();
        
        // Load it
        loadNextScreen();
    }
    
    // Send update to screen
    getCurrentScreen()->update(deltaTime);
}

void Game::resize(sf::RenderWindow &window) {
    // Send resize to screen
    getCurrentScreen()->resize(window);
}

void Game::handle(sf::Keyboard::Key key) {
    // Send handle to screen
    getCurrentScreen()->handle(key);
}
