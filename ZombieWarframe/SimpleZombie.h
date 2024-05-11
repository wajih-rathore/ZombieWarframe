#pragma once
#include "Zombies.h"
class SimpleZombie :
    public Zombies
{
//private:
//    Texture simpleZombieTexture;
//    Sprite simpleZombieSprite;
public:
    SimpleZombie();
    void moveZombie();
    void updateSprite();
};

