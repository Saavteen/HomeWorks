#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Projectile.h"

class Player
{
public:
	Player(const char* textureFileName);
	void update(float deltaTime ,bool isPaused);
	void render(sf::RenderWindow& window);
	sf::FloatRect getBounds() const;
	void setColor(const sf::Color& color);
	std::vector<Projectile>& getProjectiles();
	int getHP() const;
	void takeDamage(int damage);
	sf::Clock colorTimer;
	bool colorChanged = false;
	void reset();
	int getDamage() const { return m_damage; }

	void updateHPText();

private:
	void handleMovemenent(float deltaTime);
	void attack(float deltaTime);

private:
	int m_hp = 5;
	int m_damage = 5;
	float m_speed = 1000.0f;
	float attackCooldown;
	float lastAttackTime;


protected:
	sf::Font m_font;
	sf::Text m_hpText;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	std::vector<Projectile> projectiles;

};