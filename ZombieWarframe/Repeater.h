#pragma once
#include "Plant.h"
class Repeater :
    public Plant
{
public:
    Repeater();
	Repeater(int x, int y);
	void draw(RenderWindow& draw);
	~Repeater();
};

