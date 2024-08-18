#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

class CollisionHandler
{
public:
    static void handleProjectileCollision(Projectile& projectile, Player& player, Enemy& enemy);
};
