#pragma once
#include "Zombies.h"
class FlyingZombie :
    public Zombies
{

    //collision detection would vary, animation for balloon popping in update sprite
public:
    FlyingZombie();
    void moveZombie();  //move the zombie after the balloon is popped
    void flyOver(); //move the zombie over plants
    void updateSprite();
};

