//
//  Player.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "Player.hpp"

const float animation_duration = 0.05f;

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
    animation_part = 0;
    animation_step = 0;
    animation_time = 0.0f;
    
    // Default location
    location.x = 12;
    location.y = 15;
}

Player::~Player() {
    // Clear move if needed
    if (move != nullptr) {
        delete move;
    }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Draw the player
    target.draw(shape, states);
}

void Player::update(float deltaTime, MapData &map) {
    // Check for a move
    bool start_move = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) && move == nullptr) {
        move = new Move(location.x, location.x, location.y, location.y - 1);
        direction = 1;
        start_move = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) && move == nullptr) {
        move = new Move(location.x, location.x - 1, location.y, location.y);
        direction = 2;
        start_move = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && move == nullptr) {
        move = new Move(location.x, location.x, location.y, location.y + 1);
        direction = 3;
        start_move = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && move == nullptr) {
        move = new Move(location.x, location.x + 1, location.y, location.y);
        direction = 0;
        start_move = true;
    }
    
    // If a move is initialized
    if (start_move) {
        // Start animation
        animated = true;
        
        // Check if entity can move
        if (!map.isMoveAllowed(*move)) {
            // Cancel if not
            move->cancelMove();
        }
    }
    
    // Update shape with direction and location
    if (animated) {
        // Update animation
        animation_time += deltaTime;
        if (animation_time >= animation_duration) {
            animation_time -= animation_duration;
            animation_step++;
            if (animation_step >= 3) {
                animation_part = animation_part == 0 ? 1 : 0;
                animation_step = 0;
                animated = false;
            }
        }
        
        // Calculate new position
        float progress = animated ? (animation_time + animation_step * animation_duration) / (animation_duration * 3.0f) : 1;
        location.x = move->getX(progress);
        location.y = move->getY(progress);
        
        // If animation stops, clear move
        if (!animated) {
            delete move;
            move = nullptr;
        }
        
        // Draw as animated
        shape.setTexture(&texture_animated);
        shape.setTextureRect(sf::IntRect(16.0f * (direction * 6 + animation_part * 3 + animation_step), 0, 16.0f, 32.0f));
    } else {
        // Draw as fix
        shape.setTexture(&texture);
        shape.setTextureRect(sf::IntRect(16.0f * direction, 0, 16.0f, 32.0f));
    }
    
    // Update shape position
    shape.setPosition(location.x * 16.0f, location.y * 16.0f);
}

void Player::forceStopAnimation() {
    // Stop animation
    animated = false;
    
    // Clear move
    delete move;
    move = nullptr;
}
