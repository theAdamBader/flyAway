//Run Away (Term 2 Coursework)
//
//Enemies.h
//
//Created by Adam M Bader 19.03.2017

#ifndef Enemies_h
#define Enemies_h

#include "Entity.h"
#include "ofMain.h"

class Enemies : public Entity {

public:
	Enemies(float& x, float& y);

	~Enemies();

	void setup();

	void draw();

	void move();

	void collisionResponse(inGameObjects *other);

	float //creating directions and speed for the enemy
		xDir,
		yDir,
		xSpeed,
		ySpeed;

	bool isAlive();

	ofImage evilBoy;
};


#endif /* Enemy_hpp */
