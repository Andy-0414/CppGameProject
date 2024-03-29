#pragma once
#include <iostream>
#include <string>

typedef enum Tile {
	AIR,
	PLAYER,
	PLAYER_BULLET,
	MONSTER,
	MONSTER_BULLET,
	TEXTVIEW
} Tile;

class GameManager {
	const int sizeX = 100;
	const int sizeY = 50;
	bool stop = false;
	int **currentScreen;
public:
	static GameManager& getGameManager();
	static GameManager* gameManager;

	GameManager();
	int getSizeX();
	int getSizeY();
	std::string findTIleString(int id);
	void renderScreen(int **nextScreen);
	bool getStop();
};