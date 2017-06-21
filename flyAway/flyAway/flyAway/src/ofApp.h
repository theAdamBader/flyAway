//Run Away (Term 2 Coursework)
//
//ofApp.h
//
//Created by Adam M Bader 19.03.2017

#include "ofMain.h"
#include "Player.h"
#include "Enemies.h"
#include "Bullets.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();


	void keyPressed(int key);
	void keyReleased(int key);

	Player *player;
	Enemies *enemy;
	Bullets *bullet;
	vector<inGameObjects *> objects;

	int numEnemies = 50;
	
	float //creating floats of the positions and bullets
		posX, 
		posY, 
		xEnemiesPosition, 
		yEnemiesPosition, 
		xBullet, 
		yBullet;
	
	int points = 0;

	string gameState;



};

