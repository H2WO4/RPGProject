//
//  Player.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "Player.hpp"

Player::Player() : Entity("player") {}

void Player::update(float deltaTime, MapData &map, bool canStartMoving) {
    // Detect a move
    if (canStartMoving && !isMoving()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
            initMove(1, map);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
            initMove(2, map);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            initMove(3, map);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            initMove(0, map);
        }
    }
    
    // Send to entity
    Entity::update(deltaTime);
}
