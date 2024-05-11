#include "FootballZombie.h"
FootballZombie::FootballZombie()
{
	zombieTexture.loadFromFile("../Images/footballzombie.png");//add footballzombie sprite later
	sprite.setTexture(zombieTexture);
	sprite.setPosition(positionX, positionY);
	zombieHealth = 180;
	zombieSpeed = 0.2f;

	sprite.setScale(0.45f, 0.45f);
}
void FootballZombie::moveZombie()
{
	int LorR = (rand() % 1000);
	if (LorR < 3 && positionY < 450)	// ta k 50 50 chance hou ya left move karay ya right
		positionY += 120;
	else if (LorR < 3 && positionY > 120)
		positionY -= 120;
	//updateSprite(); //yahan clock ki basis pe sprite ko bhee update karna
	positionX -= 1 * zombieSpeed;
	sprite.setPosition(positionX, positionY);
	/*zombieHealth--;*/
	//std::cout << "X = " << positionX << "\nY = " << positionY << "\n\n";

}

void FootballZombie::updateSprite()
{
	if (zombieState && zombieHealth <= 100)
	{
		zombieTexture.loadFromFile("../Images/img2.jpg");	//loses helmet
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