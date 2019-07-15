#pragma once
#include <iostream>
#include <string>

typedef enum Tile {
	AIR,
	PLAYER,
	PLAYER_BULLET,
	MONSTER,
	MONSTER_BULLET,
} Tile;

class GameManager {
	const int sizeX = 60;
	const int sizeY = 20;
	int **currentScreen;
public:
	static GameManager& getGameManager();
	static GameManager* gameManager;

	GameManager();
	int getSizeX();
	int getSizeY();
	char findTIleString(int id);
	void renderScreen(int **nextScreen);
};