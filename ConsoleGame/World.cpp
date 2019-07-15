#include <iostream>
#include <vector>
#include <algorithm>

#include "World.h"
#include "GameManager.h"
using namespace std;
World::World() :World(GameManager::getGameManager().getSizeX(), GameManager::getGameManager().getSizeX()) {};
World::World(int x, int y) {
	this->sizeX = x;
	this->sizeY = y;
}
int World::getSizeX() {
	return sizeX;
}
int World::getSizeY() {
	return sizeY;
}
void World::addProp(Prop *p) {
	propList.push_back(p);
}
int** World::getRenderData() {
	int **arr = new int*[this->sizeX];
	for (int i = 0; i < this->sizeY; i++) {
		arr[i] = new int[this->sizeX];
		for (int j = 0; j < this->sizeX; j++) {
			arr[i][j] = Tile::AIR;
		}
	}
	for (auto prop : propList) {
		Prop p = *prop;
		arr[p.getY()][p.getX()] = p.getType();
	}

	return arr;
}

Prop::Prop() :Prop(0, 0) {};
Prop::Prop(int x, int y) {
	this->x = x;
	this->y = y;
}
void Prop::setX(int x) {
	this->x = x;
}
void Prop::setY(int y) {
	this->y = y;
}
void Prop::setXY(int x, int y) {
	this->x = x;
	this->y = y;
}
void Prop::setType(Tile type) {
	this->type = type;
}
int Prop::getX() {
	return x;
}
int Prop::getY() {
	return x;
}
Tile Prop::getType() {
	return type;
}