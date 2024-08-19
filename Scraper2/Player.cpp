#include "Player.h"
#include <vector>
#include <chrono>
#include "WindowHelper.h"
#include <iostream>

Player::Player(const char* textureFileName)
    : attackCooldown(0.3f), lastAttackTime(0.0f), m_hp(5),m_damage(5)

{
    if (!m_texture.loadFromFile(textureFileName))
    {
        std::cerr << "Error loading player texture" << std::endl;
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setScale({ 0.05f,0.05f });
    if (!m_font.loadFromFile("ComicSansMS.ttf")) 
    {
        std::cerr << "Error loading font" << std::endl;
    }
    m_hpText.setFont(m_font);
    m_hpText.setCharacterSize(24); 
    m_hpText.setFillColor(sf::Color::White);
    m_hpText.setPosition(10, 10); 

    updateHPText();

}

void Player::reset()
{
    m_hp = 6;
}

void Player::handleMovemenent(float deltaTime)
{
    sf::Vector2f position = m_sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        position.x -= m_speed * deltaTime;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        position.x += m_speed * deltaTime;
        m_sprite.setScale(-0.05f, 0.05f);
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
        projectiles.push_back(Projectile(m_sprite.getPosition().x, m_sprite.getPosition().y, direction, ProjectileType::Normal, ProjectileOwner::Player));
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

void Player::update(float deltaTime,bool isPaused)
{
    if (isPaused) return;
    handleMovemenent(deltaTime);
    attack(deltaTime);
    for (auto& projectile : projectiles)
    {
        if (projectile.isActive()) 
        {
            projectile.update(deltaTime);
        }
    }
    if (colorChanged && colorTimer.getElapsedTime().asSeconds() > 0.3f)
    {
        setColor(sf::Color::White);
        colorChanged = false;
    }
    projectiles.erase(
        std::remove_if(projectiles.begin(), projectiles.end(), [](const Projectile& p) { return !p.isActive(); }),
        projectiles.end()
    );

}

void Player::render(sf::RenderWindow& window)
{
    window.draw(m_sprite);
    for (auto& projectile : projectiles)
    {
        projectile.render(window);
    }
    window.draw(m_hpText);
}

std::vector<Projectile>& Player::getProjectiles()
{
    return projectiles;
}

void Player::setColor(const sf::Color& color)
{
    m_sprite.setColor(color);
}

sf::FloatRect Player::getBounds() const
{
    return m_sprite.getGlobalBounds();
}

int Player::getHP() const 
{
    return m_hp;
}

void Player::takeDamage(int damage)
{
    m_hp -= damage;
    if (m_hp < 0)
    {
        m_hp = 0;
        m_sprite.setScale(m_sprite.getScale() / 2.0f);
        m_sprite.setColor(sf::Color::Transparent);
    }
    updateHPText();

}

void Player::updateHPText()
{
    m_hpText.setString("HP: " + std::to_string(m_hp));
}
