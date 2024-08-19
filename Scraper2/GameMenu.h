#pragma once
#include <SFML/Graphics.hpp>

class GameMenu 
{
public:
    GameMenu(float width, float height);
    void draw(sf::RenderWindow& window) const ;
    const sf::Text& getPlayButton() const;
    const sf::Text& getExitButton() const; 

private:
    sf::Text playButton;
    sf::Text exitButton;
    sf::Font font;

};