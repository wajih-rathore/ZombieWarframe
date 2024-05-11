#pragma once
#include "Plant.h"
class Sunflower :
    public Plant
{
protected:

    public:
	Sunflower();
	Sunflower(int x, int y);
	void draw(RenderWindow& draw);
};

