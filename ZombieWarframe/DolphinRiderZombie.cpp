#include "DolphinRiderZombie.h"

DolphinRiderZombie::DolphinRiderZombie()
{
	zombieTexture.loadFromFile("../Images/img1.png");//add dolphinriderzombie sprite later
	sprite.setTexture(zombieTexture);
	sprite.setPosition(positionX, positionY);
	zombieHealth = 100;
	zombieSpeed = 0.3f;
}
void DolphinRiderZombie::moveZombie()
{
	positionX -= 1 * zombieSpeed;
	sprite.setPosition(positionX, positionY);
	//paani main hilao issay what?
}
void DolphinRiderZombie::updateSprite()
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
