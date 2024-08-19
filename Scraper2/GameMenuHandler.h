#pragma once
#include <SFML/Graphics.hpp>
#include "GameMenu.h"

bool handleGameMenu(sf::RenderWindow& window, GameMenu& menu, bool& isGameRunning, bool& isGamePaused) {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            return false;
        case sf::Event::MouseButtonPressed:
            if (isGamePaused) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (menu.getPlayButton().getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    isGamePaused = false;
                    return true;
                }
                else if (menu.getExitButton().getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    window.close();
                    return false;
                }
            }
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                if (!isGameRunning) {
                    isGamePaused = !isGamePaused;
                }
            }
            break;
        default:
            break;
        }
    }
    return false;
}
