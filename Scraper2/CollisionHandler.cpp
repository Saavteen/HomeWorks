#include "CollisionHandler.h"
#include "Projectile.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

void CollisionHandler::handleProjectileCollision(Projectile& projectile, Player& player, Enemy& enemy)
{
    if (projectile.getOwnerType() == ProjectileOwner::Enemy && projectile.checkCollision(player.getBounds()))
    {
        std::cout << "sosi xui";
    }
    else if (projectile.getOwnerType() == ProjectileOwner::Player && projectile.checkCollision(enemy.getBounds()))
    {
        std::cout << "fuck you";
    }
}


