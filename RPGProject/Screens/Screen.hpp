//
//  Screen.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 23/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"

class Screen : public sf::Drawable {
    
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual void update(float deltaTime) = 0;
    virtual void resize(sf::RenderWindow &window) = 0;
    virtual void handle(sf::Keyboard::Key key) = 0;
    
    virtual bool shouldChangeScreen() = 0;
    virtual int getNextScreenID() = 0;
    
};

#endif /* Screen_hpp */
