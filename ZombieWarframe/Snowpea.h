#pragma once
#include "Plant.h"
class Snowpea :
    public Plant
{
public:

	Snowpea();
	Snowpea(int x, int y);
	void draw(RenderWindow& draw);
	~Snowpea();
};

