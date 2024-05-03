#include "FlyingZombie.h"
#include"Zombie.h"

FlyingZombie::FlyingZombie()
{
	zombieTexture.loadFromFile("../Images/img1.png");//add flyingzombie sprite later
	sprite.setTexture(zombieTexture);
	sprite.setPosition(positionX, positionY);
	zombieHealth = 120;	//20 for the ballooon
	zombieSpeed = 0.3f;
}

void FlyingZombie::moveZombie()
{
	Zombie::moveZombie();
}

void FlyingZombie::flyOver()
{

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
