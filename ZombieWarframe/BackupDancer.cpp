#include "BackupDancer.h"

BackupDancer::BackupDancer()
{
	zombieTexture.loadFromFile("../Images/backupdancer.png");//add zombie sprite later
	sprite.setTexture(zombieTexture);
	sprite.setPosition(positionX, positionY);
	zombieHealth = 90;
	zombieSpeed = 0.15f;
	sprite.setScale(0.5f, 0.5f);
}

void BackupDancer::moveZombie()
{
	Zombies::moveZombie();
}

void BackupDancer::updateSprite()
{
	if (zombieState && zombieHealth <= 50)
	{
		zombieTexture.loadFromFile("../Images/img2.png");	//loses arm
		sprite.setTexture(zombieTexture);
		zombieState = 2;
	}
	if (zombieHealth == 0)
	{
		zombieState = 0;
	}
}
