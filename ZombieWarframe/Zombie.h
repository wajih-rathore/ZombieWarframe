#pragma once
#include"SFML\Graphics.hpp"
using namespace sf;
class Zombie
{
protected:
	int zombieHealth;
	float zombieSpeed;
	int positionX;
	int positionY;
	int damage;
	int zombieState;	// 0 for dead, 1 for existing, 2 for damaged
	Sprite sprite;
	Texture zombieTexture;
public:
	Zombie();
	virtual void moveZombie();
	virtual void updateSprite();
	void attackPlant();
	void takeDamage(int);
	void checkZombieBounds();
	Sprite getsprite();
};