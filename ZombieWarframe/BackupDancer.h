#pragma once
#include "Zombies.h"
class BackupDancer :
    public Zombies
{
public:
    BackupDancer();
    void moveZombie();
    void updateSprite();
};

