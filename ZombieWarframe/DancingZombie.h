#pragma once
#include "Zombie.h"
class DancingZombie :
    public Zombie
{
public:
    DancingZombie();
    void moveZombie();
    void updateSprite();
    void summonZombies();

};

