#pragma once
#include "Plant.h"
#include<iostream>
class Peashooter : public Plant
{
public:
	Peashooter();
	Peashooter(int x, int y);
	void draw(RenderWindow& draw);

};

