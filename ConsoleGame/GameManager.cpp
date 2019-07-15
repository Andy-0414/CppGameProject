#include <iostream>
#include <string>

#include "GameManager.h"
#include "ConsoleFunction.h"

using namespace std;

GameManager* GameManager::gameManager = nullptr;

GameManager& GameManager::getGameManager() {
	if (!gameManager)
		gameManager = new GameManager();
	return *gameManager;
}
GameManager::GameManager() {
	this->currentScreen = new int*[sizeY];
	for (int i = 0; i < sizeY; ++i) {
		this->currentScreen[i] = new int[sizeX];
		memset(this->currentScreen[i], Tile::AIR, sizeof(int)*sizeX);
	}
}
int GameManager::getSizeX() {
	return this->sizeX;
}
int GameManager::getSizeY() {
	return this->sizeY;
}

char GameManager::findTIleString(int id) {
	char s = ' ';
	switch (id) {
	case Tile::AIR: s = ' '; break;
	case Tile::PLAYER: s = 'p'; break;
	case Tile::PLAYER_BULLET: s = 'o'; break;
	case Tile::MONSTER: s = 'm'; break;
	case Tile::MONSTER_BULLET: s = 'x'; break;
	}
	return s;
};

void GameManager::renderScreen(int **nextScreen) {
	for (int y = 0; y < this->sizeY; y++) {
		for (int x = 0; x < this->sizeX; x++) {
			if (this->currentScreen[y][x] != nextScreen[y][x]) {
				gotoxy(x,y);
				cout << this->findTIleString(nextScreen[y][x]);
				this->currentScreen[y][x] = nextScreen[y][x] == NULL ? 0 : nextScreen[y][x];
			}
		}
	}
}