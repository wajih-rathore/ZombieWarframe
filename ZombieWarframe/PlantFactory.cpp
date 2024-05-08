#include "PlantFactory.h"


int PlantFactory::plantCount = 0;


PlantFactory::PlantFactory()
{
	plant = new Plant*[45];
	for (int i = 0; i < 45; i++)
	{
		plant[i] = NULL;
	}
	++plantCount;

	plant[plantCount] = new Peashooter();

}
void PlantFactory::createPeashooter(int x, int y)
{
	
}
int PlantFactory::getPlantCount()
{
	return plantCount;
}

PlantFactory::~PlantFactory()
{

	--plantCount;
}



