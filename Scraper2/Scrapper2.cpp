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

CollisionHandler collisionHandler;


void handleSystemEvents(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
            break;
        default:
            break;
        }
    }
}
//TO DO 
// Урон босу , плейеру , колізії 
// UI (меню , хп )
// звуки
// доробить enemy and players projectiles 
// смерть персонажа/босса



int main()
{

    srand(static_cast<unsigned int>(time(0)));

    sf::RenderWindow& window = WindowHelper::Instance().GetRenderWindow();

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("back.png"))
    {
        std::cerr << "Error loading background texture" << std::endl;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    window.draw(backgroundSprite);
    
    Player player("wizard.png");
    Enemy boss("boss.png", window.getSize().x - 350, window.getSize().y / 2.8);
    sf::Clock clock;


    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        handleSystemEvents(window);

        player.update(deltaTime);
        boss.update(deltaTime);

        for (auto& projectile : player.getProjectiles()) // Assuming getProjectiles() returns a reference to the projectile list
        {
            collisionHandler.handleProjectileCollision(projectile, player, boss);
        }


        window.clear();
        window.draw(backgroundSprite);

        player.render(window);
        boss.render(window);

        window.display();

    }

    return 0;
}