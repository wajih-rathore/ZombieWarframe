#pragma once
#include"Plant.h"
#include"Peashooter.h"
#include<SFML/Graphics.hpp>
using namespace sf;

class PlantFactory
{
	static int plantCount;
	Plant** plant;

public:
	PlantFactory();
	int getPlantCount ();
	~PlantFactory();

	void createPeashooter(int x, int y);
};



