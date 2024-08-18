#pragma once
#include <SFML/Graphics.hpp>
#include "ProjectileType.h"


class Projectile
{
public:
    Projectile(float x, float y, float direction, ProjectileType type,ProjectileOwner ownerType);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    bool checkCollision(sf::FloatRect& bounds);
    sf::FloatRect getBounds() const;
    ProjectileOwner getOwnerType() const;

private:
    sf::Sprite m_sprite;
    static sf::Texture m_normalTexture;
    static sf::Texture m_fastAndLargeTexture;
    static sf::Texture m_cosPathTexture;
    static sf::Texture m_spiralPathTexture;
    ProjectileType m_type;
    ProjectileOwner m_ownerType;

    float m_speed;
    float m_direction;
    float m_initialX;
    float m_initialY;

    static void loadTextures();
};
