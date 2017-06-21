//Run Away (Term 2 Coursework)
//
//Bullets.cpp
//
//Created by Adam M Bader 05.04.2017

#include "Bullets.h"
#include "Player.h"


Bullets::Bullets(float &x, float &y, float width, float height) : inGameObjects (x, y, width, height)
{
	vel.x = 5;
}



Bullets::~Bullets() {

}

void Bullets::draw() {
	ofSetColor(0, 200, 255);
	ofDrawRectangle(pos.x, pos.y, boundingBox->width, boundingBox->height);
	move();
}

void Bullets::move() {
	pos += vel;
	boundingBox->x = pos.x;
	boundingBox->y = pos.y;
	if (pos.x>ofGetWindowWidth()) {
		health = 0;
	};

}

void Bullets::collisionResponse(inGameObjects *other) {

}
