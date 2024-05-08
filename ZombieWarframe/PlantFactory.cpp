#include "PlantFactory.h"


int PlantFactory::peashooterCount = 0;


PlantFactory::PlantFactory()
{
	
}
void PlantFactory::createPlant(int rows, int cols)
{
	peashooter[peashooterCount] = new Peashooter(rows, cols);
	peashooterCount++;
}
int PlantFactory::getPlantCount()
{
	return peashooterCount;
}

PlantFactory::~PlantFactory()
{

	for (int i = 0; i < peashooterCount; i++)
	{
		delete peashooter[i];
	}
}

void PlantFactory::draw(RenderWindow& window)
{
	for (int i = 0; i < peashooterCount; i++)
	{
		peashooter[i]->draw(window);
	}
}



