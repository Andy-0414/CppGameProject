#include <iostream>
#include <string>
#include <locale>

#include "GameManager.h"
#include "ConsoleFunction.h"
#include "World.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "korean");

	GameManager gm = GameManager::getGameManager();
	World world;
	Prop p(2,2);
	p.setType(Tile::PLAYER);
	world.addProp(&p);
	
	gm.renderScreen(world.getRenderData());
}