//Run Away (Term 2 Coursework)
//
//Player.cpp
//
//Created by Adam M Bader 19.03.2017

#include "Player.h"

Player::Player(float &x, float &y): Entity(x, y, 187 / 2, 122 / 2, 40, points) {
	health = 10;
}

Player::~Player() {
}

void Player::setup()
{
	boy.load("images/player/boy.png");
}

void Player::draw() {
	//draws the player
	ofSetColor(255);
	boy.draw(boundingBox->x, boundingBox->y, boundingBox->width, boundingBox->height);

	//draws energy bar
	ofSetColor(255);
	ofDrawBitmapString("HEALTH", 10, 760);
	ofSetColor(0, 255, 0);
	ofDrawRectangle(80, 740, ofMap(health, 0, 5, 0, 200), 20);

	move();
}



void Player::keyPressed(int key) {


}

void Player::move() {

	boundingBox->x = pos.x;
	boundingBox->y = pos.y;

	//easing for the player movement
	float easing = 0.1;
	float targetX = ofGetMouseX();
	float ex = targetX - pos.x;
	pos.x += ex * easing;
	float targetY = ofGetMouseY();
	float ey = targetY - pos.y;
	pos.y += ey * easing;


}


bool Player::isAlive() {
	if (health <= 0) {

		return false;

	}
	else {

		return true;
	}
}

void Player::collisionResponse(inGameObjects *other) {
	Enemies *e = dynamic_cast<Enemies *>(other);

	if (e) {

		health -= 1;
		other->health -= 1;
	
	}
}