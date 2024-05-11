#include "Cherrybomb.h"


Cherrybomb::Cherrybomb()
{
	plantTexture.loadFromFile("Images/Cherrybomb.png");
	plantSprite.setTexture(plantTexture);
	plantSprite.setPosition(-50, -50);
	plantSprite.setScale(0.18f, 0.18f);
	//plantSprite.setOrigin(plantSprite.getLocalBounds().width / 2, plantSprite.getLocalBounds().height / 2);
}

Cherrybomb::Cherrybomb(int x, int y)
{
	plantTexture.loadFromFile("Images/Cherrybomb.png");
	plantSprite.setTexture(plantTexture);
	int X = ((y - 1) * 90) + 230;
	int Y = ((x - 1) * 110) + 120;
	plantSprite.setPosition(X, Y);
	plantSprite.setScale(0.16f, 0.16f);
	//plantSprite.setOrigin(plantSprite.getLocalBounds().width / 2, plantSprite.getLocalBounds().height / 2);
}

void Cherrybomb::draw(RenderWindow& window)
{
	window.draw(plantSprite);
}

Cherrybomb::~Cherrybomb()
{
}
