#include "Player.h"
#include <vector>
#include <chrono>
#include "WindowHelper.h"
#include <iostream>

Player::Player(const char* textureFileName)
    : attackCooldown(0.3f), lastAttackTime(0.0f), m_hp(3),m_damage(5)

{
    if (!m_texture.loadFromFile(textureFileName))
    {
        std::cerr << "Error loading player texture" << std::endl;
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setScale({ 0.05f,0.05f });

}

void Player::handleMovemenent(float deltaTime)
{
    sf::Vector2f position = m_sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        position.x -= m_speed * deltaTime;
        //m_sprite.setScale(0.05f, 0.05f); // Flip Horizontally
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        position.x += m_speed * deltaTime;
        m_sprite.setScale(-0.05f, 0.05f); // Normal Orientation
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        position.y -= m_speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        position.y += m_speed * deltaTime;
    }
    sf::RenderWindow& window = WindowHelper::Instance().GetRenderWindow();
    sf::Vector2u windowSize = window.getSize();

    sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();

    if (position.x < 0) {
        position.x = 0;
    }
    if (position.x + spriteBounds.width > windowSize.x) {
        position.x = windowSize.x - spriteBounds.width;
    }
    if (position.y < 0) {
        position.y = 0;
    }
    if (position.y + spriteBounds.height > windowSize.y) {
        position.y = windowSize.y - spriteBounds.height;
    }
    m_sprite.setPosition(position);
}

void Player::attack(float deltaTime)
{
    float currentTime = std::chrono::duration<float>(std::chrono::steady_clock::now().time_since_epoch()).count();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (currentTime - lastAttackTime >= attackCooldown))
    {
        float direction = (m_sprite.getScale().x > 0) ? -1.0f : 1.0f;
        projectiles.push_back(Projectile(m_sprite.getPosition().x, m_sprite.getPosition().y, direction, ProjectileType::Normal));
        lastAttackTime = currentTime;
    }

    for (auto& projectile : projectiles)
    {
        projectile.update(deltaTime);
    }

    // Del Projectiles
   projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
        [](const Projectile& p) { return p.getBounds().left > 1920 || p.getBounds().left < 0; }),
        projectiles.end());
}

void Player::update(float deltaTime)
{

    handleMovemenent(deltaTime);
    attack(deltaTime);
    for (auto& projectile : projectiles)
    {
        projectile.update(deltaTime);
    }
}

void Player::render(sf::RenderWindow& window)
{
    window.draw(m_sprite);
    for (auto& projectile : projectiles)
    {
        projectile.render(window);
    }
}