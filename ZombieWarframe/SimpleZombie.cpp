#include "SimpleZombie.h"
#include"Zombie.h"

SimpleZombie::SimpleZombie():Zombie()
{
	zombieTexture.loadFromFile("../Images/img1.png");//add zombie sprite later
	sprite.setTexture(zombieTexture);
	sprite.setPosition(positionX, positionY);
	zombieHealth = 100;
	zombieSpeed = 0.2f;
}
void SimpleZombie::moveZombie()
{
	Zombie::moveZombie();
}
void SimpleZombie::updateSprite()
{
	Zombie::updateSprite();
}
