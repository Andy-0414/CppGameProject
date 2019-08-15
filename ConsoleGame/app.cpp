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

	Prop player(world.getSizeX()/2, world.getSizeY()/2);
	player.setType(Tile::PLAYER);
	player.setFriction(1.3);
	world.addProp(&player);

	Prop text,slow(0,world.getSizeY()-1);
	text.setType(Tile::TEXTVIEW);
	text.setString("score : 1");
	world.addProp(&text);

	slow.setType(Tile::TEXTVIEW);
	slow.setString("Slow Power []");
	world.addProp(&slow);

	int monsterSpawn = 0;
	double difficulty = 1, slowPower = 20;
	int time = 30;
	int speed = 4;

	while (true) {
		if (GetKeyState('W') & 0x8000)
			player.applyVelocityY(-speed);
		if (GetKeyState('A') & 0x8000)
			player.applyVelocityX(-speed);
		if (GetKeyState('S') & 0x8000)
			player.applyVelocityY(speed);
		if (GetKeyState('D') & 0x8000)
			player.applyVelocityX(speed);
		if (GetKeyState(VK_SPACE) & 0x8000 && slowPower > 0) {
			slowPower -= 1;
			time = 10;
			speed = 6;
		}
		else {
			if(slowPower < 20 && !(GetKeyState(VK_SPACE) & 0x8000))slowPower += 0.25;
			time = 30;
			speed = 4;
		}
		string bar = "";
		for (int i = 0; i < 20; i++) {
			if(i >= slowPower)
				bar += " ";
			else
				bar += "=";
		}
		slow.setString("Slow Power ["+bar+"]");
		if (monsterSpawn++ > 15/difficulty) {
			difficulty += 0.1;
			monsterSpawn = 0;
			text.setString("score : " + to_string(difficulty));

			int x = rand() % world.getSizeX();
			int y = (int)(rand() % 2) * world.getSizeY();
			Prop* bullet = new Prop(x, y);
			double velX = cos(atan2((player.getY() - y), (player.getX() - x))) * 2;
			double velY = sin(atan2((player.getY() - y), (player.getX() - x))) * 2;
			bullet->setVelocityXY(velX, velY);
			bullet->setType(Tile::MONSTER);
			bullet->setFriction(0);
			bullet->setWorldOutRemove();
			world.addProp(bullet);
		}

		world.physicsAllTicks();
		gm.renderScreen(world.getRenderData());
		if (gm.getStop()) {
			gotoxy(0, 0);
			setSize(20, 5);
			cout << "Score :" + to_string(difficulty);
			Sleep(3000);
			break;
		}
		Sleep(1000.0 / time);
	}
}
