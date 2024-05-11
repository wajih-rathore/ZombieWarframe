#include "Snowpea.h"

Snowpea::Snowpea()
{
}

Snowpea::Snowpea(int x, int y)
{
	plantTexture.loadFromFile("images/snowpea.png");
	plantSprite.setTexture(plantTexture);
	int X = ((y - 1) * 90) + 230;
	int Y = ((x - 1) * 110) + 120;
	plantSprite.setPosition(X, Y);
	plantSprite.setScale(0.14f, 0.14f);
	
}

void Snowpea::draw(RenderWindow& window)
{
	window.draw(plantSprite);
}

Snowpea::~Snowpea()
{
}