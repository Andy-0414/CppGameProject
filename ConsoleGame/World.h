#pragma once

class World {
	int sizeX;
	int sizeY;
	World();
	World(int, int);
	int** getRenderData();
};