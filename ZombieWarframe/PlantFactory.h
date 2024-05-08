#pragma once
#include"Peashooter.h"
#include<SFML/Graphics.hpp>
using namespace sf;

class PlantFactory
{
	static int plantCount;
	Peashooter* peashooter[45];
	//Sun flower[45];
public:
	PlantFactory();
	int getPlantCount ();
	~PlantFactory();
	void draw(RenderWindow& window);
	void createPeashooter(int x, int y);
};



