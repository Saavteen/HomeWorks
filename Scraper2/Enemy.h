#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.h"

class Enemy
{
public:
    Enemy(const char* textureFileName, float x, float y);
    void update(float deltaTime, bool isPaused);
    void render(sf::RenderWindow& window);
    void shootProjectile(std::vector<Projectile>& projectiles);
    sf::FloatRect getBounds() const;
    void setColor(const sf::Color& color);
    std::vector<Projectile>& getProjectiles();
    void reset();
    int getDamage() const { return m_damage; }

    int getHP() const;
    void takeDamage(int damage);

    sf::Clock colorTimer;
    bool colorChanged = false;

    void updateHPText();
private:
    int m_hp = 100; 
    int m_damage = 1;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    float m_shootCooldown;
    float m_moveSpeed;
    float m_direction;
    sf::Font m_font;
    sf::Text m_hpText;

    std::vector<Projectile> m_projectiles;
};

