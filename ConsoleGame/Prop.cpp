#include <iostream>
#include <cmath>

#include "Prop.h"
#include "GameManager.h"

using namespace std;

int worldX = GameManager::getGameManager().getSizeX();
int worldY = GameManager::getGameManager().getSizeY();

Prop::Prop() :Prop(0, 0) {};
Prop::Prop(int x, int y) {
	this->x = x;
	this->y = y;
	this->velocityX = 0;
	this->velocityY = 0;
}

bool Prop::isWorldOutCheck() {
	return isWorldOut && isWorldOutRemove;
}
void Prop::setWorldOutRemove() {
	isWorldOutRemove = true;
}
void Prop::setX(int x) {
	if (x < 0) {
		this->x = 0;
		this->isWorldOut = true;
	}
	else if (x > worldX - 1) {
		this->x = worldX - 1;
		this->isWorldOut = true;
	}
	else
		this->x = x;
}
void Prop::setY(int y) {
	if (y < 0) {
		this->y = 0;
		this->isWorldOut = true;
	}
	else if (y > worldY - 1) {
		this->y = worldY - 1;
		this->isWorldOut = true;
	}
	else
		this->y = y;
}
void Prop::setXY(int x, int y) {
	this->setX(x);
	this->setY(y);
}
void Prop::setVelocityX(double x) {
	this->velocityX = x;
}
void Prop::setVelocityY(double y) {
	this->velocityY = y;
}
void Prop::setVelocityXY(double x, double y) {
	this->setVelocityX(x);
	this->setVelocityY(y);
}
void Prop::setFriction(double friction) {
	this->friction = friction;
}
void Prop::setType(Tile type) {
	this->type = type;
}
void Prop::moveX(int x) {
	this->setX(this->getX() + x);
}
void Prop::moveY(int y) {
	this->setY(this->getY() + y);

}
void Prop::moveXY(int x, int y) {
	this->moveX(x);
	this->moveY(y);
}
void Prop::applyVelocityX(double x) {
	this->velocityX += (x - this->velocityX) / friction / 5;
}
void Prop::applyVelocityY(double y) {
	this->velocityY += (y - this->velocityY) / friction / 5;
}
void Prop::applyVelocityXY(double x, double y) {
	this->applyVelocityX(x);
	this->applyVelocityY(y);
}
void Prop::physicsTIck() {
	this->moveX((int)this->velocityX);
	this->moveY((int)this->velocityY);
	if (this->velocityX < 0.1 && this->velocityX > -0.1)
		this->velocityX = 0;
	if (this->velocityY < 0.1 && this->velocityY > -0.1)
		this->velocityY = 0;
	if (friction) {
		this->velocityY -= this->velocityY / friction / 10;
		this->velocityX -= this->velocityX / friction / 10;
	}
}
int Prop::getX() {
	return x;
}
int Prop::getY() {
	return y;
}
double Prop::getVelocityX() {
	return velocityX;
}
double Prop::getVelocityY() {
	return velocityY;
}
double Prop::getFriction() {
	return friction;
}
Tile Prop::getType() {
	return type;
}

string Prop::getString() {
	return text;
}
void Prop::setString(string text) {
	this->text = text;
}