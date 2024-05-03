#pragma once
#include "Zombie.h"
class FootballZombie :
    public Zombie
{
public:
    FootballZombie();
    void moveZombie();
    void updateSprite();
};

