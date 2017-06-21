//Run Away (Term 2 Coursework)
//
//Enemies.cpp
//
//Created by Adam M Bader 19.03.2017

#include "Enemies.h"
#include "Bullets.h"

Enemies::Enemies(float& x, float& y) : Entity(x, y, 90, 60, 40, points)
{
	//enemies at direction 2 for x and 3 for y
	xDir = 2;
	yDir = 3;

	//enemies at random speed
	xSpeed = ofRandom(1, 2);
	ySpeed = ofRandom(-1, 1);

}

Enemies::~Enemies() {

}

void Enemies::setup()
{
	//loads evil boy image from the bin
	evilBoy.load("images/enemy/enemyBoy.png");
}


void Enemies::draw() {

	ofSetColor(255);
	evilBoy.draw(pos.x, pos.y, boundingBox->width, boundingBox->height);
	move();

}


void Enemies::move() {

	//drawing enemies that will bounce and try taking health from the player
	pos.x -= xDir * xSpeed;
	pos.y += yDir * ySpeed;
	boundingBox->x = pos.x;
	boundingBox->y = pos.y;

	if (pos.x + boundingBox->width<0 || pos.x + boundingBox->width>ofGetWidth()) {
		xDir = xDir * -1;

	}
	else if (pos.y + boundingBox->height<0 || pos.y + boundingBox->height>500) {
		yDir = xDir * -1;

	}
}

bool Enemies::isAlive() {
	if (health <= 0) {
		return false;
	}
	else {

		return true;
	}
}

void Enemies::collisionResponse(inGameObjects *other) {

	//if bullet hits enemy, it dies
	Bullets *b = dynamic_cast<Bullets *>(other);
	if (b) {

		cout << points << endl;
		health -= 1;

		other->health -= 1;

	}
	
}
