#include "Zombies.h"
Zombies::Zombies()
{
	
	positionX = 1100 + (rand() % 200)* 4;
	positionY = 10 + (rand() % 4) * 120; 
	/*
	80, 170, 300,
	zombieTexture.loadFromFile("../Images/img1.png");
	sprite.setTexture(zombieTexture);
	sprite.setPosition(positionX, positionY);*/
	//zombieSpeed = 0.2f;
	zombieState = 1;
	damage = 5;
	//zombieHealth = 100;
}
void Zombies::moveZombie()
{
	positionX-=1*zombieSpeed;
	sprite.setPosition(positionX, positionY);
}

void Zombies::attackPlant()
{
	//reduce plants health and update the sprite to eat the plant 
	// needs to be virtual as each sprite needs to be updated?
}

void Zombies::takeDamage(int plantDamage)
{
	zombieHealth -= plantDamage;
}
void Zombies::checkZombieBounds()
{
	if (positionX <= 160)
		zombieState = 0;
}

Sprite Zombies::getsprite()
{
	return sprite;
}

float Zombies::getX()
{
	return positionX;
}

float Zombies::getY()
{
	return positionY;
}

void Zombies::setX(int x)
{
	positionX = x;
}

void Zombies::setY(int y)
{
	positionY = y;
}

int Zombies::getHealth()
{
	return zombieHealth;
}
int Zombies::getDamage()
{
	return damage;
}
//void Zombies::setHealth(int h)
//{
//	zombieHealth = h;
//}
