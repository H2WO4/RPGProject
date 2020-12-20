//
//  Player.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "Player.hpp"

const float speed = 128.0f;

Player::Player() {
    // Load textures from files
    texture.loadFromFile(resourcePath() + "player.png");
    texture_animated.loadFromFile(resourcePath() + "player_animated.png");
    
    // Create player shape
    shape.setSize(sf::Vector2f(16.0f, 32.0f));
    shape.setOrigin(0.0f, 16.0f);
    shape.setTexture(&texture);
    
    // Default direction
    direction = 0;
    animated = false;
    animation_step = 0;
    animation_time = 0.0f;
}

sf::Vector2f Player::getLocation() {
    return location;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Draw the player
    target.draw(shape, states);
}

void Player::update(float deltaTime) {
    // Check for a move
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        location.y -= deltaTime * speed;
        direction = 1;
        animated = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        location.x -= deltaTime * speed;
        direction = 2;
        animated = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        location.y += deltaTime * speed;
        direction = 3;
        animated = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        location.x += deltaTime * speed;
        direction = 0;
        animated = true;
    } else {
        animated = false;
    }
    
    // Update shape with direction and location
    if (animated) {
        // Update animation
        animation_time += deltaTime;
        if (animation_time >= 0.2f) {
            animation_time -= 0.2f;
            animation_step++;
            if (animation_step >= 6) {
                animation_step = 0;
            }
        }
        
        // Draw as animated
        shape.setTexture(&texture_animated);
        shape.setTextureRect(sf::IntRect(16.0f * (direction * 6 + animation_step), 0, 16.0f, 32.0f));
    } else {
        // Draw as fix
        shape.setTexture(&texture);
        shape.setTextureRect(sf::IntRect(16.0f * direction, 0, 16.0f, 32.0f));
    }
    shape.setPosition(location);
}
