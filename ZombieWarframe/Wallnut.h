#pragma once
#include "Plant.h"
class Wallnut : public Plant
{
	public:
	Wallnut();
	Wallnut(int x, int y);
	void draw(RenderWindow& window);
	~Wallnut();
};

