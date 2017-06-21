//Run Away (Term 2 Coursework)
//
//Bullets.h
//
//Created by Adam M Bader 05.04.2017

#ifndef Bullets_h
#define Bullets_h

#include <stdio.h>
#include "inGameObjects.h"

class Bullets : public inGameObjects {
public:

	Bullets(float &x, float &y, float width, float height);

	~Bullets();

	void draw();
	void move();

	void collisionResponse(inGameObjects *other);

	float width, height;

};

#endif /* Bullets_hpp */