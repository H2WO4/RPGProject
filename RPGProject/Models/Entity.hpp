//
//  Entity.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 22/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>

#include "ResourcePath.hpp"
#include "MapData.hpp"
#include "Move.hpp"

class Entity : public sf::Drawable {
    
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
    Entity(std::string type);
    ~Entity();
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(float deltaTime);
    
    void initMove(int direction, MapData &map);
    bool isMoving();
    void forceStopAnimation();
    
    friend class TileMap;
    
};

#endif /* Entity_hpp */
