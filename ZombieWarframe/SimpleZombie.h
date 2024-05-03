#pragma once
#include "Zombie.h"
class SimpleZombie :
    public Zombie
{
    //private:
    //    Texture simpleZombieTexture;
    //    Sprite simpleZombieSprite;
public:
    SimpleZombie();
    void moveZombie();
    void updateSprite();
};