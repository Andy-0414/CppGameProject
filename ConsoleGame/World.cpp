#include <iostream>
#include "World.h"
#include "GameManager.h"
using namespace std;
World::World() :World(GameManager::getGameManager().getSizeX(), GameManager::getGameManager().getSizeX()) {};
World::World(int x,int y) {
	this->sizeX = x;
	this->sizeY = y;
}
int** World::getRenderData() {
	
}