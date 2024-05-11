#include "SimpleZombie.h"

SimpleZombie::SimpleZombie():Zombies()
{
	zombieTexture.loadFromFile("../Images/Zombie_0.png");//add zombie sprite later
	sprite.setTexture(zombieTexture);
	sprite.setPosition(positionX, positionY);
	zombieHealth = 90;
	zombieSpeed = 0.15f;
	sprite.setScale(1.2f, 1.2f);
}
void SimpleZombie::moveZombie()
{
	Zombies::moveZombie();
}
void SimpleZombie::updateSprite()
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
