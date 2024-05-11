#include "Wallnut.h"

Wallnut::Wallnut()
{
}

Wallnut::Wallnut(int x, int y)
{
	//std::cout<<"Wallnut created"<<std::endl;
	plantTexture.loadFromFile("Images/wallnut.png");
	plantSprite.setTexture(plantTexture);
	int X = ((y - 1) * 90) + 230;
	int Y = ((x - 1) * 110) + 120;
	//std::cout<<"X: "<<X<<" Y: "<<Y<<std::endl;
	plantSprite.setPosition(X, Y);
	plantSprite.setScale(0.17f, 0.17f);
	//plantSprite.setOrigin(plantSprite.getLocalBounds().width / 2, plantSprite.getLocalBounds().height / 2);
}


void Wallnut::draw(RenderWindow& window)
{
	window.draw(this->plantSprite);
}

Wallnut::~Wallnut()
{
}