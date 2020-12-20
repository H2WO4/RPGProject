//
//  MapScreen.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "MapScreen.hpp"

void MapScreen::setMaps(MapData* maps) {
    map.setMaps(maps);
}

void MapScreen::loadMap(int index) {
    // Load the map
    map.load(index);
}

void MapScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Draw the map
    target.draw(map, states);
}

void MapScreen::update(float deltaTime) {
    // Send update to map
    map.update(deltaTime);
}

void MapScreen::resize(sf::RenderWindow &window) {
    // Send resize to map
    map.resize(window);
}
