#pragma once
#include "Zombies.h"
class FootballZombie :
    public Zombies
{
public:
    FootballZombie();
    void moveZombie();
    void updateSprite();
};

