#pragma once
#include "Plant.h"
#include"PlantFactory.h"

class Peashooter : public Plant
{
public:
	Peashooter();
	void draw(RenderWindow& draw);
	void createPeashooter(int x, int y);
};

