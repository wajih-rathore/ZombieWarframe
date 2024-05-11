#include "DancingZombie.h"


DancingZombie::DancingZombie()
{
	rowchange = 0;
	direction = 1;
	zombieTexture.loadFromFile("../Images/dancingzombie.png");//add dancingzombie sprite later //bg weird hai

	/*sf::IntRect frameRect(0, 0, 42, 71);
	sprite.setTextureRect(frameRect);*/

	sprite.setTexture(zombieTexture);
	sprite.setPosition(positionX, positionY);
	zombieHealth = 90;
	zombieSpeed = 0.25f;

	sprite.setScale(0.4f, 0.4f);
}
void DancingZombie::moveZombie()
{
	//ye badtameezi kar raha hai

	if (direction == 1 && positionY < 450 && rowchange < 450)	
	{
		positionY += zombieSpeed/2.0;
		rowchange += zombieSpeed/2.0;
		/*if (rowchange >= 120)
			direction--;*/
	}
	else if (direction == 0 && positionY > 10 && rowchange > 0)
	{
		positionY -= zombieSpeed/2.0;
		rowchange -= zombieSpeed/2.0;
		/*if (rowchange == 0)
			direction++;*/
	}
	if (positionY >= 450)
		direction = 0;
	else if (positionY == 10)
		direction = 1;
	//updateSprite(); 
	positionX -= 1 * zombieSpeed;
	sprite.setPosition(positionX, positionY);
	//std::cout << "direction: "<<direction<<"\nrowchange: "<<rowchange<<"\nX = " << positionX << "\nY = " << positionY << "\n\n";
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
