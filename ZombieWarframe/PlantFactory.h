#pragma once
#include"Peashooter.h"
#include"Sunflower.h"
#include"Wallnut.h"
#include"Cherrybomb.h"
#include"Repeater.h"
#include"Snowpea.h"

#include<SFML/Graphics.hpp>
using namespace sf;

class PlantFactory
{
	static int sunflowerCount;
	Sunflower* sunflower[45];

	static int peashooterCount;
	Peashooter* peashooter[45];

	static int wallnutCount;
	Wallnut* wallnut[45];

	static int cherrybombCount;
	Cherrybomb* cherrybomb[45];

	static int repeaterCount;
	Repeater* repeater[45];

	static int snowpeaCount;
	Snowpea* snowpea[45];


public:
	PlantFactory();
	int getPlantCount ();
	~PlantFactory();
	void draw(RenderWindow& window);
	bool createPlant(int x, int y, int& type);

};



