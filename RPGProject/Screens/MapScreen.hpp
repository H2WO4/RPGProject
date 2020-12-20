//
//  MapScreen.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef MapScreen_hpp
#define MapScreen_hpp

#include "MapData.hpp"
#include "TileMap.hpp"
#include "ResourcePath.hpp"

class MapScreen : public sf::Drawable {

private:
    TileMap map;
    
public:
    void setMaps(MapData* maps);
    void loadMap(int index);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(float deltaTime);
    void resize(sf::RenderWindow &window);
    
};

#endif /* MapScreen_hpp */
