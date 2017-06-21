//Run Away (Term 2 Coursework)
//
//Player.h
//
//Created by Adam M Bader 19.03.2017

#ifndef Player_h
#define Player_h

#include "ofMain.h"
#include "Entity.h"
#include "Enemies.h"

class Player : public Entity {
	
public:

	Player(float &x, float &y);

	~Player();

	void setup();

	void draw();

	void keyPressed(int key);
	
	void move();

	bool isAlive();
	void collisionResponse(inGameObjects *other);

	ofImage boy;
};

#endif /* Player_hpp */
