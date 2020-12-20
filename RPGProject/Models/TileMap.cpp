//
//  TileMap.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "TileMap.hpp"

TileMap::TileMap(): view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(640.0f, 480.0f)) {
    // Zoom in
    view.zoom(0.5f);
}

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles1, const int* tiles2, const int* tiles3, unsigned int width, unsigned int height) {
    // Load the tileset texture
    if (!this->tileset.loadFromFile(tileset)) {
        return false;
    }
    
    // Resize the vertex array to fit the level size
    vertices1.setPrimitiveType(sf::Quads);
    vertices2.setPrimitiveType(sf::Quads);
    vertices3.setPrimitiveType(sf::Quads);
    vertices1.resize(width * height * 4);
    vertices2.resize(width * height * 4);
    vertices3.resize(width * height * 4);
    
    // Populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j) {
            // Get the current tile number
            int tileNumber1 = std::max(tiles1[i + j * width] - 1, 0);
            int tileNumber2 = std::max(tiles2[i + j * width] - 1, 0);
            int tileNumber3 = std::max(tiles3[i + j * width] - 1, 0);
            
            // Find its position in the tileset texture
            int tu1 = tileNumber1 % (this->tileset.getSize().x / tileSize.x);
            int tv1 = tileNumber1 / (this->tileset.getSize().x / tileSize.x);
            int tu2 = tileNumber2 % (this->tileset.getSize().x / tileSize.x);
            int tv2 = tileNumber2 / (this->tileset.getSize().x / tileSize.x);
            int tu3 = tileNumber3 % (this->tileset.getSize().x / tileSize.x);
            int tv3 = tileNumber3 / (this->tileset.getSize().x / tileSize.x);
            
            // Get a pointer to the current tile's quad
            sf::Vertex* quad1 = &vertices1[(i + j * width) * 4];
            sf::Vertex* quad2 = &vertices2[(i + j * width) * 4];
            sf::Vertex* quad3 = &vertices3[(i + j * width) * 4];
            
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
}

void TileMap::update(float deltaTime) {
    // Ask player to update
    player.update(deltaTime);
    
    // Update view with player position
    view.setCenter(player.getLocation());
}
