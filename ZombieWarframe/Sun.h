#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Sun
{
private:
	Texture sunTexture;
	Sprite sunSprite;
	int sunCount;

public:
	Sun();
	void moveSun();
	int getSunCount();
	void draw(RenderWindow& draw);
	~Sun();
};

