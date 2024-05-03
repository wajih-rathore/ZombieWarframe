#include "Zombie.h"


Zombie::Zombie()
{
	srand(time(0));
	positionX = 1100;
	positionY = 300 + (rand() % 5) * 80;
	/*zombieTexture.loadFromFile("../Images/img1.png");
	sprite.setTexture(zombieTexture);
	sprite.setPosition(positionX, positionY);*/
	//zombieSpeed = 0.2f;
	zombieState = 1;
	damage = 5;
	//zombieHealth = 100;
}
void Zombie::moveZombie()
{
	positionX -= 1 * zombieSpeed;
	sprite.setPosition(positionX, positionY);
}
void Zombie::updateSprite()
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
void Zombie::attackPlant()
{
	//reduce plants health and update the sprite to eat the plant 
	// needs to be virtual as each sprite needs to be updated?
}
void Zombie::takeDamage(int plantDamage)
{
	zombieHealth -= plantDamage;
}
void Zombie::checkZombieBounds()
{
	if (positionX <= 160)
		zombieState = 0;
}

Sprite Zombie::getsprite()
{
	return sprite;
}