#include "PlantFactory.h"

int PlantFactory::plantCount = 0;


PlantFactory::PlantFactory()
{
	plant = new Plant;
	++plantCount;

}

int PlantFactory::getPlantCount()
{
	return plantCount;
}

PlantFactory::~PlantFactory()
{
	delete plant;
	--plantCount;
}



