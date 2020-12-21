//
//  Player.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include <cmath>

#include "ResourcePath.hpp"
#include "MapData.hpp"
#include "Move.hpp"

class Player : public sf::Drawable {

private:
    sf::Vector2f location;
    sf::Texture texture;
    sf::Texture texture_animated;
    sf::RectangleShape shape;
    
    Move* move;
    
    int direction;
    bool animated;
    int animation_part;
    int animation_step;
    float animation_time;
    
public:
    Player();
    ~Player();
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(float deltaTime, MapData &map, bool canStartMoving);
    void forceStopAnimation();
    
    friend class TileMap;
    
};

#endif /* Player_hpp */
