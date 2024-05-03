#include "DancingZombie.h"

DancingZombie::DancingZombie()
{
	zombieTexture.loadFromFile("../Images/img1.png");//add dancingzombie sprite later
	sprite.setTexture(zombieTexture);
	sprite.setPosition(positionX, positionY);
	zombieHealth = 100;
	zombieSpeed = 0.3f;
}
void DancingZombie::moveZombie()
{
	//iss ko upar neechay hilao
}
void DancingZombie::updateSprite()
{
	if (zombieState && zombieHealth <= 50)
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
void DancingZombie::summonZombies()
{
	//hell if i know
}