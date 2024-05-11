#pragma once
#include"SFML\Graphics.hpp"
#include<iostream>
using namespace sf;
class Zombies
{
protected:
	int zombieHealth;
	float zombieSpeed;
	float positionX;
	float positionY;
	int damage;
	int zombieState;	// 0 for dead, 1 for existing, 2 for damaged
	Sprite sprite;
	Texture zombieTexture;
	Clock clock;
public:
	Zombies();
	virtual void moveZombie();
	virtual void updateSprite() = 0;
	void attackPlant();
	void takeDamage(int);
	void checkZombieBounds();
	Sprite getsprite();
	float getX();
	float getY();
	void setX(int);
	void setY(int);
	int getHealth();
	int getDamage();
	//void setHealth(int h);
};


