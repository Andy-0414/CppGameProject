#include <iostream>
#include <string>
#include <locale>

#include "GameManager.h"
#include "ConsoleFunction.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "korean");

	GameManager gm = GameManager::getGameManager();
	int **arr = new int*[60];
	for (int i = 0; i < 60; i++) {
		arr[i] = new int[60];
		for (int j = 0; j < 60; j++) {
			arr[i][j] = Tile::PLAYER_BULLET;
		}
	}
	gm.renderScreen(arr);
}