//
//  Entity.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 22/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "Entity.hpp"

const float animation_duration = 0.05f;

Entity::Entity(std::string type) {
    // Load textures from files
    texture.loadFromFile(resourcePath() + type + ".png");
    texture_animated.loadFromFile(resourcePath() + type + "_animated.png");
    
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

Entity::~Entity() {
    // Clear move if needed
    if (move != nullptr) {
        delete move;
    }
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Draw the player
    target.draw(shape, states);
}

void Entity::update(float deltaTime) {
    // Update shape with direction and location
    if (animated) {
        // Update animation
        animation_time += deltaTime;
        while (animation_time >= animation_duration) {
            animation_time -= animation_duration;
            animation_step++;
        }
        if (animation_step >= 3) {
            animation_part = animation_part == 0 ? 1 : 0;
            animation_step = 0;
            animated = false;
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

void Entity::initMove(int direction, MapData &map) {
    // Check not already moving
    if (isMoving()) {
        return;
    }
    
    // Start a move
    bool start_move = false;
    if (direction == 1) {
        move = new Move(location.x, location.x, location.y, location.y - 1);
        this->direction = 1;
        start_move = true;
    } else if (direction == 2) {
        move = new Move(location.x, location.x - 1, location.y, location.y);
        this->direction = 2;
        start_move = true;
    } else if (direction == 3) {
        move = new Move(location.x, location.x, location.y, location.y + 1);
        this->direction = 3;
        start_move = true;
    } else if (direction == 0) {
        move = new Move(location.x, location.x + 1, location.y, location.y);
       this-> direction = 0;
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
}

bool Entity::isMoving() {
    return move != nullptr;
}

void Entity::forceStopAnimation() {
    // Stop animation
    animated = false;
    
    // Clear move
    delete move;
    move = nullptr;
}
