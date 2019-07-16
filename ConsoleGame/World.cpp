#include <iostream>
#include <vector>
#include <algorithm>

#include "World.h"
#include "GameManager.h"

using namespace std;

World::World() :World(GameManager::getGameManager().getSizeX(), GameManager::getGameManager().getSizeY()) {};
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
void World::physicsAllTicks() {
	for (Prop* prop : propList) {
		prop->physicsTIck();
	}
}