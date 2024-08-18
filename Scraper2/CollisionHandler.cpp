//#include "CollisionHandler.h"
//#include "Projectile.h"
//#include "Player.h"
//#include "Enemy.h"
//
//void CollisionHandler::handleProjectileCollision(Projectile& projectile, Player& player, Enemy& enemy)
//{
//    if (projectile.getOwnerType() == ProjectileOwner::Enemy && projectile.checkCollision(player.getBounds()))
//    {
//        player.setColor(sf::Color::Red);  // Change color to red
//        // Handle other collision logic, like dealing damage to player
//    }
//    else if (projectile.getOwnerType() == ProjectileOwner::Player && projectile.checkCollision(enemy.getBounds()))
//    {
//        enemy.setColor(sf::Color::Red);  // Change color to red
//        // Handle other collision logic, like dealing damage to enemy
//    }
//}
