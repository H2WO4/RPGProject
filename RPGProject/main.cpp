//
//  main.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"
#include "Game.hpp"

int main(int, char const**) {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(640, 480), "RPG Project");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Create the game object
    Game game;
    
    // Create the clock
    sf::Clock clock;

    // Start the game loop
    while (window.isOpen()) {
        // Calculate delta time
        float deltaTime = clock.restart().asSeconds();
        
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        // Update game
        game.update(deltaTime);

        // Clear screen
        window.clear();

        // Draw
        game.draw(window);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
