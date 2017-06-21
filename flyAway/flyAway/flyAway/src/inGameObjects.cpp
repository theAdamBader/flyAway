//Run Away (Term 2 Coursework)
//
//inGameObjects.cpp
//
//Created by Adam M Bader 19.03.2017

#include "inGameObjects.h"

inGameObjects::inGameObjects(float& x, float& y, float w, float h) :pos(ofVec2f(x, y))
{
	boundingBox = new ofRectangle(x, y, w, h);
}

inGameObjects::~inGameObjects()
{

}



void inGameObjects::collide(inGameObjects *other)
{
	// check for collision if boundingbox intersects

	if (boundingBox->intersects(*other->boundingBox)) {

		this->collisionResponse(other);

	}
}

bool inGameObjects::isAlive() {
	if (health <= 0) {
		return false;
	}
	else {
		return true;
	}
}
