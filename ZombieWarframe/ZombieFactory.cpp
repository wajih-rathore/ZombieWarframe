#include "ZombieFactory.h"
#include"Zombies.h"
#include"SimpleZombie.h"
#include"FootballZombie.h"
#include"FlyingZombie.h"
#include"DancingZombie.h"
#include"BackupDancer.h"
int ZombieFactory::zombieCount = 0;

ZombieFactory::ZombieFactory()
{
	srand(time(0));
	int numZombies = 5, i = 0;
	// simple zombies 
	numZombies += (rand() % 10);
	std::cout <<"\nSimple zombies = "<< numZombies;
	for (; i < numZombies; i++)
	{
		levelzombies[i] = new SimpleZombie;
		zombieTypes[i] = "simple";
		zombieCount++;
	}
	
	//football zombies
	numZombies += rand() % 5;
	std::cout << "\nfootball zombies = " << numZombies;
	for (; i < numZombies; i++)
	{
		levelzombies[i] = new FootballZombie;
		zombieTypes[i] = "football";
		zombieCount++;
	}

	//dancing zombies
	numZombies += rand() % 4;
	std::cout << "\ndancing zombies = " << numZombies;
	for (; i < numZombies; i++)
	{
		levelzombies[i] = new DancingZombie;
		zombieTypes[i] = "dancing";
		zombieCount++;
	}

	//flying zombies
	numZombies += rand() % 5;
	std::cout << "\nflying zombies = " << numZombies;
	for (; i < numZombies; i++)
	{
		levelzombies[i] = new FlyingZombie;
		zombieTypes[i] = "flying";
		zombieCount++;
	}

	//initialize the rest to empty string
	for (int i = zombieCount; i < maxZombies; i++)
	{
		levelzombies[i] = 0;
		zombieTypes[i] = "";
	}

	std::cout << "\nzombies: " << zombieCount;
}

int ZombieFactory::getzombieCount()
{
	return zombieCount;
}

void ZombieFactory::createZombies()
{
	for(int i = 0; i<zombieCount;i++)
	{
		if((zombieTypes[i] == "dancing") && (zombieCount <= maxZombies - 2) && (levelzombies[i]->getX() > 500))
		{
			int summonzombies = rand() % 100;
			if (summonzombies <= 10)
			{
				//std::cout << "\ncreating zombies";
				levelzombies[zombieCount] = new BackupDancer;
				//std::cout << "\ndancing zombie x =" << levelzombies[i]->getX() << "\ndancingzombie y =" << levelzombies[i]->getY()<<"\nzombie type"<<zombieTypes[i];
				
				levelzombies[zombieCount]->setX(levelzombies[i]->getX() - 180);
				levelzombies[zombieCount]->setY(levelzombies[i]->getY());

				/*std::cout << "\nzombie x =" << levelzombies[zombieCount]->getX() << "\nzombie y =" << levelzombies[zombieCount]->getY();*/

				zombieTypes[zombieCount] = "backup";	
				zombieCount++;

				levelzombies[zombieCount] = new BackupDancer;
				levelzombies[zombieCount]->setX((levelzombies[i]->getX()) + 180);
				levelzombies[zombieCount]->setY(levelzombies[i]->getY());
				zombieTypes[zombieCount] = "backup";
				zombieCount++;

				/*
				levelzombies[zombieCount] = new BackupDancer;
				levelzombies[zombieCount]->setX(levelzombies[i]->getX());

				if(levelzombies[i]->getY() < 340)
					levelzombies[zombieCount]->setY(levelzombies[i]->getY() + 120);
				else 
					levelzombies[zombieCount]->setY(levelzombies[i]->getY() - 120);

				zombieTypes[zombieCount] = "backup";
				zombieCount++;*/

				//std::cout << "\nZombies:" << zombieCount;

			}
		}
	}
}

void ZombieFactory::moveZombies()
{
	for (int i = 0; i < zombieCount; i++)
	{
		levelzombies[i]->moveZombie();
		//levelzombies[i]->setHealth(levelzombies[i]->getHealth() - 1);

		/*levelzombies[i]->takeDamage(1);
		std::cout << "\nhealth=" << levelzombies[i]->getHealth();*/
	}
}

Zombies** ZombieFactory::getZombies()
{
	return levelzombies;
}

// either this code will run or i will run myself over with a truck
void ZombieFactory::checkHealth()
{
	for (int i = 0; i < zombieCount;)
	{
		if (levelzombies[i]->getHealth() == 0)
		{
			//remove the zombie from the array 
			delete levelzombies[i];
			for (int j = i; j < zombieCount - 1; j++)
			{
				levelzombies[j] = levelzombies[j + 1];
				zombieTypes[j] = zombieTypes[j + 1];
			}

			// jo khaali jaga thee wahan dangling ptr avoid karnay k liyay
			levelzombies[zombieCount - 1] = nullptr;
			zombieTypes[zombieCount - 1] = "";
			//decrement total number of zombies
			zombieCount--;

		}
		else
			i++;
	}
}

ZombieFactory::~ZombieFactory()
{
	for (int i = 0; i<zombieCount; i++)
		delete levelzombies[i];

	delete[] levelzombies;
}
