#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Projectile.h"

class Player
{
public:
	Player(const char* textureFileName);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
	sf::FloatRect getBounds() const;
private:
	void handleMovemenent(float deltaTime);
	void attack(float deltaTime);

private:
	float m_speed = 1000.0f;
	float attackCooldown;
	float lastAttackTime;
	int m_hp;
	int m_damage;

protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	std::vector<Projectile> projectiles;

};