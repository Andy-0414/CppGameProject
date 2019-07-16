#include <iostream>
#include <string>
#include <locale>
#include <Windows.h>
#include <cmath>

#include "GameManager.h"
#include "ConsoleFunction.h"
#include "World.h"
#include "Prop.h"

#define PI 3.14159265
using namespace std;

int main() {
	GameManager gm = GameManager::getGameManager();
	World world;

	setlocale(LC_ALL, "korean");
	setCursorType(CursorInvisible);
	setSize(gm.getSizeX(), gm.getSizeY());

	Prop player;
	player.setType(Tile::PLAYER);
	player.setFriction(1.3);
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
		if (GetKeyState(VK_SPACE) & 0x8000) {
			Prop* bullet= new Prop(player.getX(), player.getY());
			bullet->setVelocityY(-4);
			bullet->setType(Tile::PLAYER_BULLET);
			bullet->setFriction(0);
			bullet->setWorldOutRemove();
			world.addProp(bullet);
		}

		world.physicsAllTicks();
		gm.renderScreen(world.getRenderData());
		Sleep(1000.0 / 30.0);
	}
}
