//
//  TitleScreen.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 23/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef TitleScreen_hpp
#define TitleScreen_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Screen.hpp"
#include "ResourcePath.hpp"

class TitleScreen : public Screen {
    
private:
    sf::Texture titleTexture;
    sf::RectangleShape title;
    sf::Music music;
    
    bool hasPressedEnter = false;
    
public:
    TitleScreen();
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(float deltaTime);
    void resize(sf::RenderWindow &window);
    void handle(sf::Keyboard::Key key);
    
    void load();
    void unload();
    
    bool shouldChangeScreen();
    int getNextScreenID();
    
};

#endif /* TitleScreen_hpp */
