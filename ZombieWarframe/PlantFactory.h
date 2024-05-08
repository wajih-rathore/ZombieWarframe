#pragma once
#include"Peashooter.h"
#include<SFML/Graphics.hpp>
using namespace sf;

class PlantFactory
{
	static int peashooterCount;
	Peashooter* peashooter[45];
	//Sun flower[45];
public:
	PlantFactory();
	int getPlantCount ();
	~PlantFactory();
	void draw(RenderWindow& window);
	void createPlant(int x, int y);
};



