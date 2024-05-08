#include "Peashooter.h"

Peashooter::Peashooter()
{
	plantTexture.loadFromFile("Images/peashooter.png");
	plantSprite.setTexture(plantTexture);
	plantSprite.setPosition(-50, -50);
	plantSprite.setScale(0.2f, 0.2f);
	plantSprite.setOrigin(plantSprite.getLocalBounds().width / 2, plantSprite.getLocalBounds().height / 2);
}

void Peashooter::draw(RenderWindow& window)
{
	window.draw(plantSprite);
}

void Peashooter::createPeashooter(int x, int y)
{
	plantSprite.setPosition(x, y);
}

void movePea()
{


}