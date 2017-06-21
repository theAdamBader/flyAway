//Run Away (Term 2 Coursework)
//
//inGameObjects.h
//
//Created by Adam M Bader 19.03.2017

#ifndef inGameObjects_h
#define inGameObjects_h

#include <stdio.h>
#include "ofMain.h"


class inGameObjects {


public:
	int health = 1;
	int points = 1;
	bool dead = false;
	ofRectangle * boundingBox;
	ofVec2f pos, vel; //takes 2 arguements
	inGameObjects(float& x, float& y, float width, float height);
	virtual ~inGameObjects();

	virtual void move() = 0;


	virtual void draw() = 0;
	virtual void collisionResponse(inGameObjects *other) = 0;
	virtual void collide(inGameObjects *other);

	virtual bool isAlive();

};

#endif /* inGameObjects_hpp */
