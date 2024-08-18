#include <iostream>
#include "Enemy.h"
#include "WindowHelper.h"

Enemy::Enemy(const char* textureFileName, float x, float y)
    : m_hp(100), m_shootCooldown(0.5f), m_moveSpeed(200.0f), m_direction(1.0f)
{
    if (!m_texture.loadFromFile(textureFileName))
    {
        std::cerr << "Error loading enemy texture" << std::endl;
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(x, y);
    m_sprite.setScale({ 1.5f,1.5f });

}

void Enemy::update(float deltaTime)
{
    sf::Vector2f position = m_sprite.getPosition();
    position.y += m_direction * m_moveSpeed * deltaTime;


    sf::RenderWindow& window = WindowHelper::Instance().GetRenderWindow();
    sf::Vector2u windowSize = window.getSize();

    if (position.y < 0 || position.y + m_sprite.getGlobalBounds().height > windowSize.y)
    {
        m_direction *= -1;
    }

    m_sprite.setPosition(position);

    m_shootCooldown -= deltaTime;
    if (m_shootCooldown <= 0.0f)
    {
        shootProjectile(m_projectiles);
        m_shootCooldown = 0.5f;
    }

    for (auto& projectile : m_projectiles)
    {
        projectile.update(deltaTime);
    }
}

void Enemy::render(sf::RenderWindow& window)
{
    window.draw(m_sprite);
    for (auto& projectile : m_projectiles)
    {
        projectile.render(window);
    }

}


void Enemy::shootProjectile(std::vector<Projectile>& projectiles)
{
    float startX = m_sprite.getPosition().x + m_sprite.getGlobalBounds().width / 2;
    float startY = m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2;

    int projectileType = rand() % 3;
    switch (projectileType)
    {
    case 0:
        projectiles.push_back(Projectile(startX, startY, -1.0f, ProjectileType::FastAndLarge, ProjectileOwner::Enemy));
        break;
    case 1:
        projectiles.push_back(Projectile(startX, startY, -1.0f, ProjectileType::CosPath, ProjectileOwner::Enemy));
    case 2:
        projectiles.push_back(Projectile(startX, startY, -1.0f, ProjectileType::SpiralPath,ProjectileOwner::Enemy));
        break;
    }
}

sf::FloatRect Enemy::getBounds() const
{
    return m_sprite.getGlobalBounds();
}