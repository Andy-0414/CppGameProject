#pragma once
#include "GameManager.h"
class Prop {
	int x;
	int y;
	bool isWorldOut = false;
	bool isWorldOutRemove = false;
	double velocityX;
	double velocityY;
	double friction = 1;
	Tile type = Tile::AIR;
public:
	Prop();
	Prop(int, int);
	bool isWorldOutCheck();
	void setWorldOutRemove();
	void setX(int);
	void setY(int);
	void setXY(int, int);
	void setVelocityX(double);
	void setVelocityY(double);
	void setVelocityXY(double, double);
	void setFriction(double);
	void setType(Tile);
	void moveX(int);
	void moveY(int);
	void moveXY(int, int);
	void applyVelocityX(double);
	void applyVelocityY(double);
	void applyVelocityXY(double, double);
	void physicsTIck();
	int getX();
	int getY();
	double getVelocityX();
	double getVelocityY();
	double getFriction();
	Tile getType();
	std::string text = "";
	std::string getString();
	void setString(std::string);
};
