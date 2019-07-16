#include <iostream>
#include <string>
#include <locale>
#include <Windows.h>

#include "GameManager.h"
#include "ConsoleFunction.h"
#include "World.h"
#include "Prop.h"

using namespace std;

int main() {
	GameManager gm = GameManager::getGameManager();
	World world;

	setlocale(LC_ALL, "korean");
	setCursorType(CursorInvisible);
	setSize(gm.getSizeX(), gm.getSizeY());

	Prop player;
	player.setType(Tile::PLAYER);
	player.setFriction(1.1);

	world.addProp(&player);


	while (true) {
		if (GetKeyState('W') & 0x8000)
			player.applyVelocityY(-4);
		if (GetKeyState('A') & 0x8000)
			player.applyVelocityX(-4);
		if (GetKeyState('S') & 0x8000)
			player.applyVelocityY(4);
		if (GetKeyState('D') & 0x8000)
			player.applyVelocityX(4);
		world.physicsAllTicks();
		gm.renderScreen(world.getRenderData());
		Sleep(1000.0 / 24.0);
	}
}
