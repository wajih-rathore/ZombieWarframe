#include "FootballZombie.h"
FootballZombie::FootballZombie()
{
	zombieTexture.loadFromFile("../Images/img1.png");//add footballzombie sprite later
	sprite.setTexture(zombieTexture);
	sprite.setPosition(positionX, positionY);
	zombieHealth = 200;
	zombieSpeed = 0.3f;
}
void FootballZombie::moveZombie()
{
	//decide whether to move left or right ????? when
	positionX -= 1 * zombieSpeed;
	sprite.setPosition(positionX, positionY);
}
void FootballZombie::updateSprite()
{
	if (zombieState && zombieHealth <= 100)
	{
		zombieTexture.loadFromFile("../Images/img2.png");	//loses helmet
		sprite.setTexture(zombieTexture);
		zombieState = 1;
	}
	else if (zombieState && zombieHealth <= 50)
	{
		zombieTexture.loadFromFile("../Images/img2.png"); //loses arm
		sprite.setTexture(zombieTexture);
		zombieState = 2;
	}
	if (zombieHealth == 0)
	{
		zombieState = 0;	//dies
	}
}