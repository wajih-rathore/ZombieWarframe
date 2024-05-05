#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Plant
{
protected:
	Texture plantTexture;
	Sprite plantSprite;
	int health;
	int damage;
	int cost;

public:
	Plant();

	virtual ~Plant();
};

