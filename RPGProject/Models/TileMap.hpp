//
//  TileMap.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef TileMap_hpp
#define TileMap_hpp

#include <SFML/Graphics.hpp>
#include <algorithm>

#include "Player.hpp"

class TileMap : public sf::Drawable, public sf::Transformable {

private:
    sf::VertexArray vertices1;
    sf::VertexArray vertices2;
    sf::VertexArray vertices3;
    sf::Texture tileset;
    sf::View view;
    Player player;
    
public:
    TileMap();
    
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles1, const int* tiles2, const int* tiles3, unsigned int width, unsigned int height);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(float deltaTime);

};

#endif /* TileMap_hpp */
