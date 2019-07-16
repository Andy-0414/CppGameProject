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
void Prop::setX(int x) {
	if (x < 0)
		this->x = 0;
	else if (x > worldX)
		this->x = worldX;
	else
		this->x = x;
}
void Prop::setY(int y) {
	if (x < 0)
		this->y = 0;
	else if (x > worldY)
		this->y = worldY;
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
	if (this->x + x < 0)
		this->x = 0;
	else if (this->x + x > worldX - 1)
		this->x = worldX - 1;
	else
		this->x += x;
}
void Prop::moveY(int y) {
	if (this->y + y < 0)
		this->y = 0;
	else if (this->y + y > worldY - 1)
		this->y = worldY - 1;
	else
		this->y += y;
}
void Prop::moveXY(int x, int y) {
	this->moveX(x);
	this->moveY(y);
}
void Prop::applyVelocityX(double x) {
	this->velocityX += (x-this->velocityX) / friction/4;
}
void Prop::applyVelocityY(double y) {
	this->velocityY += (y-this->velocityY) / friction/4;
}
void Prop::applyVelocityXY(double x, double y) {
	this->applyVelocityX(x);
	this->applyVelocityY(y);
}
void Prop::physicsTIck() {
	this->moveX((int)this->velocityX);
	this->moveY((int)this->velocityY);
	if (this->velocityX < 0.5 && this->velocityX > -0.5)
		this->velocityX = 0;
	if (this->velocityY < 0.5 && this->velocityY > -0.5)
		this->velocityY = 0;
	this->velocityX -= this->velocityX / friction/10;
	this->velocityY -= this->velocityY / friction/10;
	//cout <<"("<<floor(this->velocityX) << "," << floor(this->velocityY)<<")"<<endl;
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

string TextView::getString() {
	return text;
}
void TextView::setString(string text) {
	this->text = text;
}