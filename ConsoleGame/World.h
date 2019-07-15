#pragma once
#include <vector>
#include "GameManager.h"
class Prop {
	int x;
	int y;
	Tile type;
public:
	Prop();
	Prop(int, int);
	void setX(int);
	void setY(int);
	void setXY(int, int);
	void setType(Tile);
	int getX();
	int getY();
	Tile getType();
};

class World {
	int sizeX;
	int sizeY;
	std::vector<Prop*> propList;
public:
	World();
	World(int, int);
	int getSizeX();
	int getSizeY();
	void addProp(Prop *p);
	int** getRenderData();
};

