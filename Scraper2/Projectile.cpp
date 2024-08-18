#include <iostream>
#include "Projectile.h"
#include "Player.h"
#include "Enemy.h"

sf::Texture Projectile::m_normalTexture;
sf::Texture Projectile::m_fastAndLargeTexture;
sf::Texture Projectile::m_cosPathTexture;
sf::Texture Projectile::m_spiralPathTexture;

void Projectile::loadTextures()
{
    if (!m_normalTexture.loadFromFile("Projectile1.png"))
    {
        std::cerr << "Error loading Projectile1 texture" << std::endl;
    }
    if (!m_fastAndLargeTexture.loadFromFile("Projectile2.png"))
    {
        std::cerr << "Error loading Projectile2 texture" << std::endl;
    }
    if (!m_cosPathTexture.loadFromFile("Projectile3.png"))
    {
        std::cerr << "Error loading Projectile3 texture" << std::endl;
    }
    if (!m_spiralPathTexture.loadFromFile("Projectile4.png"))
    {
        std::cerr << "Error loading Projectile4 texture" << std::endl;
    }
}


Projectile::Projectile(float x, float y, float direction, ProjectileType type)
    : m_speed(500.0f), m_direction(direction), m_type(type), m_initialX(x), m_initialY(y)
{
    static bool texturesLoaded = false;
    if (!texturesLoaded)
    {
        loadTextures();
        texturesLoaded = true;
    }

    switch (m_type)
    {
    case ProjectileType::FastAndLarge:
        m_sprite.setTexture(m_fastAndLargeTexture);
        m_speed *= 2.0f;
        m_sprite.setScale(1.0f, 1.0f);
        break;
    case ProjectileType::CosPath:
        m_sprite.setTexture(m_cosPathTexture);
        break;
    case ProjectileType::SpiralPath:
        m_sprite.setTexture(m_spiralPathTexture);
        break;
    case ProjectileType::Normal:
    default:
        m_sprite.setScale({ 0.8f,0.8f });
        m_sprite.setTexture(m_normalTexture);
        break;
    }

    m_sprite.setPosition(x, y);
}

void Projectile::update(float deltaTime)
{

    if (m_type == ProjectileType::CosPath)
    {
        float x = m_sprite.getPosition().x + m_direction * m_speed * deltaTime;
        float y = 300.0f * std::cos(x / 300.0f);
        m_sprite.setPosition(x, m_initialY + y);
    }
    else if (m_type == ProjectileType::SpiralPath)
    {
        float speedFactor = 5.0f;

        float x = m_initialX + m_direction * m_speed * deltaTime;
        float y = m_initialY + 50.0f + std::sin(x * 0.05f * speedFactor);
        m_sprite.setPosition( x, m_initialX + y);
        m_initialX = x;
    }
    else
    {
        m_sprite.move(m_direction * m_speed * deltaTime, 0);
    }
}

void Projectile::render(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

bool Projectile::checkCollision(sf::FloatRect& bounds)
{
    return m_sprite.getGlobalBounds().intersects(bounds);
}

sf::FloatRect Projectile::getBounds() const
{
    return m_sprite.getGlobalBounds();
}
