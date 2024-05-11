#pragma once
#include "Zombies.h"
class DancingZombie :
    public Zombies
{
    int direction;
    float rowchange;
public:
    DancingZombie();
    void moveZombie();
    void updateSprite();

};

