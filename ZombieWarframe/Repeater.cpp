#include "Repeater.h"

Repeater::Repeater()
{

}

Repeater::Repeater(int x, int y)
{
	plantTexture.loadFromFile("Images/Repeater.png");
	plantSprite.setTexture(plantTexture);
	int X = ((y - 1) * 90) + 230;
	int Y = ((x - 1) * 110) + 120;
	plantSprite.setPosition(X, Y);
	plantSprite.setScale(0.14f, 0.14f);
	//plantSprite.setOrigin(plantSprite.getLocalBounds().width / 2, plantSprite.getLocalBounds().height / 2);
}

void Repeater::draw(RenderWindow& window)
{
	window.draw(plantSprite);
}

Repeater::~Repeater()
{
}