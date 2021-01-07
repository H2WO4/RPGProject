//
//  TextBox.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 21/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef TextBox_hpp
#define TextBox_hpp

#include <string>
#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"

class TextBox : public sf::Drawable {

private:
    sf::Font sfFont;
    sf::Text sfText;
    sf::RectangleShape background;
    sf::RectangleShape cursor;
    sf::Texture backgroundTexture;
    sf::Texture cursorTexture;
    
    std::string text;
    bool animated;
    int progress;
    float animation_time;
    
public:
    TextBox();
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(float deltaTime);
    void setRect(float x, float y, float width, float height);
    void setText(std::string newText);
    void clearText();
    bool pressEnter();
    
};

#endif /* TextBox_hpp */
