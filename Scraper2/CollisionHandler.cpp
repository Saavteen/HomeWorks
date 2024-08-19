#include "CollisionHandler.h"
#include "Projectile.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

void CollisionHandler::handleProjectileCollision(Projectile& projectile, Player& player, Enemy& enemy)
{
    if (projectile.getOwnerType() == ProjectileOwner::Enemy && projectile.checkCollision(player.getBounds()))
    {
        player.setColor(sf::Color::Red);
        player.takeDamage(enemy.getDamage());
        std::cout << player.getHP() << std::endl;
        projectile.deactivate();
        player.colorTimer.restart(); 
        player.colorChanged = true;
    }
    else if (projectile.getOwnerType() == ProjectileOwner::Player && projectile.checkCollision(enemy.getBounds()))
    {
        enemy.setColor(sf::Color::Red);
        enemy.takeDamage(player.getDamage());
        std::cout << enemy.getHP()<<std::endl;
        projectile.deactivate();
        enemy.colorTimer.restart(); 
        enemy.colorChanged = true;

    }
}


