#include "FlyingZombie.h"

FlyingZombie::FlyingZombie()
{
	zombieTexture.loadFromFile("../Images/flyingzombie.png");	//add flyingzombie sprite 

	sf::IntRect frameRect(0, 0, 34, 58);
	sprite.setTextureRect(frameRect);

	sprite.setTexture(zombieTexture);
	sprite.setPosition(positionX,positionY - 40);
	zombieHealth = 90;	
	zombieSpeed = 0.2f;

	sprite.setScale(3.0f, 3.0f);
}

void FlyingZombie::moveZombie()
{
	Zombies::moveZombie();
}

void FlyingZombie::updateSprite()
{
	if (zombieState && zombieHealth <= 100)
	{
		zombieTexture.loadFromFile("../Images/img2.png");	// loses balloon
		sprite.setTexture(zombieTexture);
		zombieState = 1;
	}
	else if (zombieState && zombieHealth <= 50)
	{
		zombieTexture.loadFromFile("../Images/img2.png"); // loses arm
		sprite.setTexture(zombieTexture);
		zombieState = 2;
	}
	if (zombieHealth == 0)
	{
		zombieState = 0;	// dies
	}
}
