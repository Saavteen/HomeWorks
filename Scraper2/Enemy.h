#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.h"

class Enemy
{
public:
    Enemy(const char* textureFileName, float x, float y);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    void shootProjectile(std::vector<Projectile>& projectiles);
    sf::FloatRect getBounds() const;
private:
    int m_hp;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    float m_shootCooldown;
    float m_moveSpeed;
    float m_direction;

    std::vector<Projectile> m_projectiles;
};

