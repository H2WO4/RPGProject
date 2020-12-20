//
//  MapScreen.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef MapScreen_hpp
#define MapScreen_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>

#include "MapData.hpp"
#include "TileMap.hpp"

class MapScreen : public sf::Drawable {

private:
    TileMap map;
    sf::Music music;
    
public:
    void loadMap(MapData data);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(float deltaTime);
    
};

#endif /* MapScreen_hpp */
