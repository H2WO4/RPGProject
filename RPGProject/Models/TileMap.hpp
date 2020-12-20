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
#include <SFML/Audio.hpp>
#include <algorithm>

#include "MapData.hpp"
#include "Player.hpp"

class TileMap : public sf::Drawable, public sf::Transformable {

private:
    sf::VertexArray vertices1;
    sf::VertexArray vertices2;
    sf::VertexArray vertices3;
    sf::Texture tileset;
    sf::View view;
    sf::Music music;
    
    MapData* maps;
    Player player;
    int currentMap;
    
public:
    TileMap();
    
    void setMaps(MapData* maps);
    bool load(int index);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(float deltaTime);
    void initTeleport(TeleportObject* teleport);
    
    void resize(sf::RenderWindow &window);

};

#endif /* TileMap_hpp */
