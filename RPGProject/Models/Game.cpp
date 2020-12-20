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
    
    // Give to screen the default map
    screen.setMaps(maps);
    screen.loadMap(0);
}

void Game::draw(sf::RenderTarget &target) {
    // Draw the screen
    target.draw(screen);
}

void Game::update(float deltaTime) {
    // Send update to screen
    screen.update(deltaTime);
}

void Game::resize(sf::RenderWindow &window) {
    // Send resize to screen
    screen.resize(window);
}

MapData* Game::getMapByName(std::string name) {
    // Iterate maps
    for (int i = 0; i < maps_count; i++) {
        MapData* map = &maps[i];
        if (map->name == name) {
            return map;
        }
    }
    
    // No map found
    return nullptr;
}
