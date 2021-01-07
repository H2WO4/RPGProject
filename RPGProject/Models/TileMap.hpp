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
#include "TextBox.hpp"

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
    TextBox textBox;
    int currentMap;
    bool freezePlayer;
    
public:
    TileMap();
    
    void setMaps(MapData* maps);
    bool load(int index);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void resize(sf::RenderWindow &window);
    
    void handle(sf::Keyboard::Key key);
    void update(float deltaTime);
    void initTeleport(Object* teleport);
    void initScript(Object* script);
    void initTextBox(std::string text);

};

#endif /* TileMap_hpp */
