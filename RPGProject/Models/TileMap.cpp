//
//  TileMap.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "TileMap.hpp"

TileMap::TileMap(): view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(320.0f, 240.0f)) {
    freezePlayer = false;
}

void TileMap::setMaps(MapData* maps) {
    this->maps = maps;
}

bool TileMap::load(int index) {
    // Save current map index
    currentMap = index;
    
    sf::Vector2u tileSize(16, 16);
    
    // Load the tileset texture
    tileset.loadFromFile(resourcePath() + maps[currentMap].tileset->name + ".png");
    
    // Resize the vertex array to fit the level size
    vertices1.setPrimitiveType(sf::Quads);
    vertices2.setPrimitiveType(sf::Quads);
    vertices3.setPrimitiveType(sf::Quads);
    vertices1.resize(maps[currentMap].width * maps[currentMap].height * 4);
    vertices2.resize(maps[currentMap].width * maps[currentMap].height * 4);
    vertices3.resize(maps[currentMap].width * maps[currentMap].height * 4);
    
    // Populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < maps[currentMap].width; ++i) {
        for (unsigned int j = 0; j < maps[currentMap].height; ++j) {
            // Get the current tile number
            int tileNumber1 = std::max(maps[currentMap].layer1[i + j * maps[currentMap].width] - 1, 0);
            int tileNumber2 = std::max(maps[currentMap].layer2[i + j * maps[currentMap].width] - 1, 0);
            int tileNumber3 = std::max(maps[currentMap].layer3[i + j * maps[currentMap].width] - 1, 0);
            
            // Find its position in the tileset texture
            int tu1 = tileNumber1 % (this->tileset.getSize().x / tileSize.x);
            int tv1 = tileNumber1 / (this->tileset.getSize().x / tileSize.x);
            int tu2 = tileNumber2 % (this->tileset.getSize().x / tileSize.x);
            int tv2 = tileNumber2 / (this->tileset.getSize().x / tileSize.x);
            int tu3 = tileNumber3 % (this->tileset.getSize().x / tileSize.x);
            int tv3 = tileNumber3 / (this->tileset.getSize().x / tileSize.x);
            
            // Get a pointer to the current tile's quad
            sf::Vertex* quad1 = &vertices1[(i + j * maps[currentMap].width) * 4];
            sf::Vertex* quad2 = &vertices2[(i + j * maps[currentMap].width) * 4];
            sf::Vertex* quad3 = &vertices3[(i + j * maps[currentMap].width) * 4];
            
            // Define its 4 corners
            quad1[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad1[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad1[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad1[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
            quad2[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad2[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad2[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad2[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
            quad3[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad3[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad3[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad3[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
            
            // Define its 4 texture coordinates
            quad1[0].texCoords = sf::Vector2f(tu1 * tileSize.x, tv1 * tileSize.y);
            quad1[1].texCoords = sf::Vector2f((tu1 + 1) * tileSize.x, tv1 * tileSize.y);
            quad1[2].texCoords = sf::Vector2f((tu1 + 1) * tileSize.x, (tv1 + 1) * tileSize.y);
            quad1[3].texCoords = sf::Vector2f(tu1 * tileSize.x, (tv1 + 1) * tileSize.y);
            quad2[0].texCoords = sf::Vector2f(tu2 * tileSize.x, tv2 * tileSize.y);
            quad2[1].texCoords = sf::Vector2f((tu2 + 1) * tileSize.x, tv2 * tileSize.y);
            quad2[2].texCoords = sf::Vector2f((tu2 + 1) * tileSize.x, (tv2 + 1) * tileSize.y);
            quad2[3].texCoords = sf::Vector2f(tu2 * tileSize.x, (tv2 + 1) * tileSize.y);
            quad3[0].texCoords = sf::Vector2f(tu3 * tileSize.x, tv3 * tileSize.y);
            quad3[1].texCoords = sf::Vector2f((tu3 + 1) * tileSize.x, tv3 * tileSize.y);
            quad3[2].texCoords = sf::Vector2f((tu3 + 1) * tileSize.x, (tv3 + 1) * tileSize.y);
            quad3[3].texCoords = sf::Vector2f(tu3 * tileSize.x, (tv3 + 1) * tileSize.y);
        }
    }
    
    // Load a music to play
    if (music.openFromFile(resourcePath() + maps[currentMap].name + ".ogg")) {
        // Play the music
        music.setLoop(true);
        music.setLoopPoints(sf::Music::TimeSpan(sf::seconds(1.0f), sf::seconds(53.0f)));
        music.play();
    }
    
    return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Apply the transform
    states.transform *= getTransform();
    
    // Apply the tileset texture
    states.texture = &tileset;
    
    // Set view
    target.setView(view);
    
    // Draw the vertex array
    target.draw(vertices1, states);
    target.draw(vertices2, states);
    
    // Draw the player
    target.draw(player);
    
    // Draw the vertex array
    target.draw(vertices3, states);
    
    // Draw the text box
    target.draw(textBox);
}

void TileMap::update(float deltaTime) {
    // Ask player to update
    player.update(deltaTime, maps[currentMap], !freezePlayer);
    
    // Send update to textBox
    textBox.update(deltaTime);
    
    // Check for an script at player position
    Object* object = maps[currentMap].getObject(player.location.x, player.location.y);
    if (object != nullptr && !object->isRunning()) {
        // Run script
        object->setRunning();
        
        // Check which kind of object it is
        if (object->getType() == "teleport") {
            // Teleport object
            initTeleport(object);
        }
    }
    
    // Calculate position
    sf::Vector2f viewSize = view.getSize();
    sf::FloatRect mapSize = vertices1.getBounds();
    sf::Vector2f playerPosition = player.shape.getPosition();
    float x = std::min(std::max(float(viewSize.x) / 2.0f, float(playerPosition.x)), float(mapSize.width) - float(viewSize.x) / 2.0f);
    float y = std::min(std::max(float(viewSize.y) / 2.0f, float(playerPosition.y)), float(mapSize.height) - float(viewSize.y) / 2.0f);
    
    // Update view with player position
    view.setCenter(sf::Vector2f(x, y));
    
    // Calculate box position
    float boxWidth = float(viewSize.x);
    float boxHeight = 48.0f;
    float boxX = x - boxWidth / 2.0f;
    float boxY = y + float(viewSize.y) / 2.0f - boxHeight;
    
    // Update text box position
    textBox.setRect(boxX, boxY, boxWidth, boxHeight);
}

void TileMap::initTeleport(Object* teleport) {
    // Fade out current map
    
    // Load new map
    load(teleport->getTeleport()->targetMap);
    player.forceStopAnimation();
    player.location.x = teleport->getTeleport()->targetX;
    player.location.y = teleport->getTeleport()->targetY;
    
    // Clear script
    teleport->finish();
}

void TileMap::initTextBox(std::string text) {
    // Freeze player
    freezePlayer = true;
    
    // Set text
    textBox.setText(text);
}

void TileMap::resize(sf::RenderWindow &window) {
    // Calculate aspect ration
    float ratio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(ratio * 240.0f, 240.0f);
}
