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

string GameManager::findTIleString(int id) {
	string s = " ";
	switch (id) {
	case Tile::AIR: s = " "; break;
	case Tile::PLAYER: s = "O"; break;
	case Tile::PLAYER_BULLET: s = "*"; break;
	case Tile::MONSTER: s = "X"; break;
	case Tile::MONSTER_BULLET: s = "o"; break;
	default: s = id;
	}
	return s;
};

void GameManager::renderScreen(int **nextScreen) {
	for (int y = 0; y < this->sizeY; y++) {
		for (int x = 0; x < this->sizeX; x++) {
			if (this->currentScreen[y][x] != nextScreen[y][x]) {
				gotoxy(x, y);
				cout << this->findTIleString(nextScreen[y][x]);
				if (this->currentScreen[y][x] == Tile::PLAYER && nextScreen[y][x] == Tile::MONSTER) {
					this->stop = true;
				}
				this->currentScreen[y][x] = nextScreen[y][x] == Tile::AIR ? Tile::AIR : nextScreen[y][x];
			}
		}
	}
}
bool GameManager::getStop() {
	return stop;
}