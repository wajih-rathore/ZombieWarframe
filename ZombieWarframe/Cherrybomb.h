#pragma once
#include "Plant.h"
class Cherrybomb :
    public Plant
{
public:
    Cherrybomb();
    Cherrybomb(int x, int y);
    void draw(RenderWindow& draw);
    //void explode();
    //void explode(int x, int y);
    //void explode(int x, int y, int damage);
    ~Cherrybomb();
};

