#include "Sunflower.h"

Sunflower::Sunflower()
{
}

Sunflower::Sunflower(int x, int y)
{

	plantTexture.loadFromFile("Images/Sunflower.png");
	plantSprite.setTexture(plantTexture);
	int X = ((y - 1) * 90) + 230;
	int Y = ((x - 1) * 110) + 120;
	//std::cout << "X: " << X << " Y: " << Y << std::endl;
	plantSprite.setPosition(X, Y);
	plantSprite.setScale(0.14f, 0.14f);
}

void Sunflower::draw(RenderWindow& window)
{
	window.draw(plantSprite);
}
