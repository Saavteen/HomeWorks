#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <thread>

#include "WindowHelper.h"
#include "Player.h"
#include "Enemy.h"
#include "ProjectileType.h"
#include "CollisionHandler.h"
#include "GameMenu.h"

CollisionHandler collisionHandler;

void handleSystemEvents(sf::RenderWindow& window, bool& isGameRunning, bool& isGamePaused, GameMenu& menu)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            std::cout << "Closed" << std::endl;
            window.close();
            break;
        case sf::Event::KeyPressed:
            std::cout << "Escape" << std::endl;
            if (event.key.code == sf::Keyboard::Escape)
            {
                isGamePaused = !isGamePaused;
                if (isGamePaused) 
                {
                    menu.draw(window);
                }
            }
            break;
        case sf::Event::MouseButtonPressed:
            std::cout << "Mouse" << std::endl;
            if (isGamePaused)
            {
                std::cout << "MouseIf" << std::endl;
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (menu.getPlayButton().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                {
                    std::cout << "MouseIfTouched" << std::endl;
                    isGamePaused = false;
                }
                else if (menu.getExitButton().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                {
                    window.close();
                }
            }
            break;
        default:
            break;
        }
    }
}


int main()
{
    srand(static_cast<unsigned int>(time(0)));

    sf::RenderWindow& window = WindowHelper::Instance().GetRenderWindow();
    GameMenu menu(window.getSize().x, window.getSize().y);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("back.png"))
    {
        std::cerr << "Error loading background texture" << std::endl;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    Player player("wizard.png");
    Enemy boss("boss.png", window.getSize().x - 350, window.getSize().y / 2.8);
    sf::Clock clock;

    bool isGameRunning = false;
    bool isGamePaused = true;
    bool playerWon = false;
    bool gameOver = false;
    bool resetGame = false;
    sf::Clock gameOverClock;

    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("ComicSansMS.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
    }

    sf::Text endText;
    endText.setFont(font);
    endText.setCharacterSize(50);
    endText.setFillColor(sf::Color::White);
    endText.setPosition(window.getSize().x / 4, window.getSize().y / 3);

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        if (gameOver)
        {
            if (!resetGame)
            {
                gameOverClock.restart();
                resetGame = true;
            }

            if (gameOverClock.getElapsedTime().asSeconds() >= 2)
            {
                window.clear();
                menu.draw(window);
                window.display();

                playerWon = false;
                gameOver = false;

                player.reset();
                boss.reset();

                isGamePaused = true;

                handleSystemEvents(window, isGameRunning, isGamePaused, menu);
                continue;
            }
            else
            {
                window.clear();
                window.draw(backgroundSprite);
                window.draw(endText);
                window.display();

                handleSystemEvents(window, isGameRunning, isGamePaused, menu);
                continue;
            }
        }

        if (isGamePaused) 
        {
            window.clear();
            menu.draw(window);
            window.display();
            handleSystemEvents(window, isGameRunning, isGamePaused, menu);
            continue; 
        }

        player.update(deltaTime, isGamePaused);
        boss.update(deltaTime, isGamePaused);

        for (auto& projectile : player.getProjectiles())
        {
            collisionHandler.handleProjectileCollision(projectile, player, boss);
        }
        for (auto& projectile : boss.getProjectiles())
        {
            collisionHandler.handleProjectileCollision(projectile, player, boss);
        }

        if (player.getHP() <= 0 || boss.getHP() <= 0)
        {
            if (player.getHP() <= 0) {
                gameOver = true;
                endText.setString("You Lost! Try Again Later");
            }
            else if (boss.getHP() <= 0)
            {
                playerWon = true;
                gameOver = true;
                endText.setString("You Win! Good Job");
            }
            resetGame = false; 
        }

        window.clear();
        window.draw(backgroundSprite);

        player.render(window);
        boss.render(window);

        window.display();
    }

    return 0;
}
