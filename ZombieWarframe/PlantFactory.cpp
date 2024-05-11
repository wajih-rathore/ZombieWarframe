#include "PlantFactory.h"


int PlantFactory::peashooterCount = 0;
int PlantFactory::sunflowerCount = 0;
int PlantFactory::wallnutCount = 0;
int PlantFactory::cherrybombCount = 0;
int PlantFactory::repeaterCount = 0;
int PlantFactory::snowpeaCount = 0;


PlantFactory::PlantFactory()
{
	
}


bool PlantFactory::createPlant(int rows, int cols, int &plantType)
{
	std::cout<<"plantType: "<<plantType<<std::endl;
	if (plantType == 1) 
	{
		sunflower[sunflowerCount] = new Sunflower(rows, cols);
		sunflowerCount++;
		std::cout << "Sunflower created" << std::endl;
		return true;

	}
	else if (plantType == 2)
	{
		peashooter[peashooterCount] = new Peashooter(rows, cols);
		peashooterCount++;
		std::cout << "Peashooter created" << std::endl;
		return true;
	}
	else if (plantType == 3)
	{
		wallnut[wallnutCount] = new Wallnut(rows, cols);
		wallnutCount++;
		std::cout << "Wallnut created" << std::endl;
		return true;
	}
	else if (plantType == 4)
	{
		cherrybomb[cherrybombCount] = new Cherrybomb(rows, cols);
		cherrybombCount++;
		std::cout << "Cherrybomb created" << std::endl;
		return true;
	}
	else if (plantType == 5)
	{
		repeater[repeaterCount] = new Repeater(rows, cols);
		repeaterCount++;
		std::cout << "Repeater created" << std::endl;
		return true;
	}
	else if (plantType == 6)
	{
		snowpea[snowpeaCount] = new Snowpea(rows, cols);
		snowpeaCount++;
		std::cout << "Snowpea created" << std::endl;
		return true;
	}

	return false;

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
	for (int i = 0; i < sunflowerCount; i++)
	{
		delete sunflower[i];
	}

	for (int i = 0; i < wallnutCount; i++)
	{
		delete wallnut[i];
	}

	for (int i = 0; i < cherrybombCount; i++)
	{
		delete cherrybomb[i];
	}

	for (int i = 0; i < repeaterCount; i++)
	{
		delete repeater[i];
	}

	for (int i = 0; i < snowpeaCount; i++)
	{
		delete snowpea[i];
	}


}

void PlantFactory::draw(RenderWindow& window)
{
	for (int i = 0; i < peashooterCount; i++)
	{
		peashooter[i]->draw(window);
	}
	for (int i = 0; i < sunflowerCount; i++)
	{
		sunflower[i]->draw(window);
	}

	for (int i = 0; i < wallnutCount; i++)
	{
		wallnut[i]->draw(window);
	}

	for (int i = 0; i < cherrybombCount; i++)
	{
		cherrybomb[i]->draw(window);
	}

	for (int i = 0; i < repeaterCount; i++)
	{
		repeater[i]->draw(window);
	}

	for (int i = 0; i < snowpeaCount; i++)
	{
		snowpea[i]->draw(window);
	}


}



