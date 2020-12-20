//
//  MapScreen.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "MapScreen.hpp"
#include "MapData.hpp"
#include "ResourcePath.hpp"

void MapScreen::loadMap(MapData data) {
    // Load the tileset to display
    map.load(resourcePath() + "tileset.png", sf::Vector2u(16, 16), data.layer1, data.layer2, data.layer3, 50, 50);
    
    // Load a music to play
    if (music.openFromFile(resourcePath() + data.name + ".ogg")) {
        // Play the music
        music.setLoop(true);
        music.play();
    }
}

void MapScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(map, states);
}

void MapScreen::update(float deltaTime) {
    // Send update to map
    map.update(deltaTime);
}
