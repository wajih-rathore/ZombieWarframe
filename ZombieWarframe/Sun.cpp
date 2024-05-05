#include "Sun.h"

Sun::Sun()
{
	sunTexture.loadFromFile("Images/icon.png");
	sunSprite.setTexture(sunTexture);
	sunSprite.setPosition(700, 0);
	sunCount = 0;
}

void Sun::moveSun()
{
	sunSprite.move(0, 10.f);

}

int Sun::getSunCount()
{
	return sunCount;
}

void Sun::draw(RenderWindow& window)
{
	window.draw(sunSprite);
}

Sun::~Sun()
{

}
