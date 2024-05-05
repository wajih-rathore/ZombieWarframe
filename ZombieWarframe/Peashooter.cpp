#include "Peashooter.h"

Peashooter::Peashooter()
{
	plantTexture.loadFromFile("Images/pea-shooter.png");
	plantSprite.setTexture(plantTexture);
	plantSprite.setPosition(200, 200);
	plantSprite.setScale(1.3f, 1.3f);
}

void Peashooter::draw(RenderWindow& window)
{
	window.draw(plantSprite);
}

void movePea()
{


}