#include "GameMenu.h"
#include <iostream>

GameMenu::GameMenu(float width, float height) {

    if (!font.loadFromFile("ComicSansMS.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    playButton.setFont(font);
    playButton.setString("Play");
    playButton.setCharacterSize(50);
    playButton.setPosition(width / 2 - 50, height / 2 - 50);

    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(50);
    exitButton.setPosition(width / 2 - 50, height / 2 + 50);
}

void GameMenu::draw(sf::RenderWindow& window) const {

    window.draw(playButton);
    window.draw(exitButton);
}

const sf::Text& GameMenu::getPlayButton() const {
    return playButton;
}

const sf::Text& GameMenu::getExitButton() const {
    return exitButton;
}
