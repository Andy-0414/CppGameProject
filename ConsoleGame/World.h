#pragma once
#include <iostream>
#include <list>
#include "Prop.h"

class World {
	int sizeX;
	int sizeY;
	std::list<Prop*> propList;
public:
	World();
	World(int, int);
	int getSizeX();
	int getSizeY();
	void addProp(Prop *p);
	void physicsAllTicks();
	int** getRenderData();
};

