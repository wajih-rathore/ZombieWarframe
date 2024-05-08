#include "PlantFactory.h"


int PlantFactory::plantCount = 0;


PlantFactory::PlantFactory()
{
	plantCount = 0;
}
void PlantFactory::createPeashooter(int rows, int cols)
{
	peashooter[plantCount] = new Peashooter(rows, cols);
	plantCount++;
}
int PlantFactory::getPlantCount()
{
	return plantCount;
}

PlantFactory::~PlantFactory()
{

	for (int i = 0; i < plantCount; i++)
	{
		delete peashooter[i];
	}
}

void PlantFactory::draw(RenderWindow& window)
{
	for (int i = 0; i < plantCount; i++)
	{
		peashooter[i]->draw(window);
	}
}



