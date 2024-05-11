#pragma once
#include"Zombies.h"
#include<iostream>
#include<SFML/Graphics.hpp>
class ZombieFactory
{
	//things left: summon zombies, delete a zombie from the array, pause movement when obstructed by a plant and deal damage to the plant

	static int zombieCount;
	//composing zombies so we should use a pointer of type zombies to point to derived types?
	static const int maxZombies = 30;
	Zombies* levelzombies[maxZombies]; //maximum 100 zombies per wave?
	//array to store names of types of zombies string type shayad
	std::string zombieTypes[maxZombies];

public:
	ZombieFactory();
	// move ka aik function ???
	int getzombieCount();
	void createZombies();
	void moveZombies();
	Zombies** getZombies();
	void checkHealth();

	~ZombieFactory();
};

