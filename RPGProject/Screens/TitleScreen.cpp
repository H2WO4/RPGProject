//
//  TitleScreen.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 23/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "TitleScreen.hpp"

TitleScreen::TitleScreen() {
    // Load texture
    titleTexture.loadFromFile(resourcePath() + "title.png");
    
    // Create shape
    title.setTexture(&titleTexture);
    title.setPosition(sf::Vector2f(0.0f, 0.0f));
    title.setSize(sf::Vector2f(640.0f, 480.0f));
    
    // Load a music to play
    if (music.openFromFile(resourcePath() + "title.ogg")) {
        // Setup the music
        music.setLoop(true);
    }
}

void TitleScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Draw the map
    target.draw(title);
}

void TitleScreen::update(float deltaTime) {
    // Nothing to update
}

void TitleScreen::resize(sf::RenderWindow &window) {
    // Resize screen
    title.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
}

void TitleScreen::handle(sf::Keyboard::Key key) {
    // Handle
    if (key == sf::Keyboard::Enter) {
        hasPressedEnter = true;
    }
}

void TitleScreen::load() {
    // Play music
    music.play();
}

void TitleScreen::unload() {
    // Stop music
    music.stop();
}

bool TitleScreen::shouldChangeScreen() {
    return hasPressedEnter;
}

int TitleScreen::getNextScreenID() {
    return 1;
}
