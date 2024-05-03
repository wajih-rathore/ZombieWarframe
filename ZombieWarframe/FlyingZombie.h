#pragma once
#include "Zombie.h"
class FlyingZombie :
    public Zombie
{
    //collision detection would vary, animation for balloon popping in update sprite
public:
    FlyingZombie();
    void moveZombie();  //move the zombie after the balloon is popped
    void flyOver(); //move the zombie over plants
    void updateSprite();
};

