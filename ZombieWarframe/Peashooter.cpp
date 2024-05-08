#include "Peashooter.h"

Peashooter::Peashooter()
{
	plantTexture.loadFromFile("Images/peashooter.png");
	plantSprite.setTexture(plantTexture);
	plantSprite.setPosition(-50, -50);
	plantSprite.setScale(0.2f, 0.2f);
	//plantSprite.setOrigin(plantSprite.getLocalBounds().width / 2, plantSprite.getLocalBounds().height / 2);
}

Peashooter::Peashooter(int x, int y)
{

	std::cout<<"Peashooter created"<<std::endl;
	plantTexture.loadFromFile("Images/peashooter.png");
	plantSprite.setTexture(plantTexture);
	int X = ((y - 1) * 90) + 230;
	int Y = ((x - 1) * 110) + 120;
	std::cout<<"X: "<<X<<" Y: "<<Y<<std::endl;
	plantSprite.setPosition(X, Y);
	plantSprite.setScale(0.2f, 0.2f);
	//plantSprite.setOrigin(plantSprite.getLocalBounds().width / 2, plantSprite.getLocalBounds().height / 2);
}

void Peashooter::draw(RenderWindow& window)
{
	window.draw(plantSprite);
}

void movePea()
{


}