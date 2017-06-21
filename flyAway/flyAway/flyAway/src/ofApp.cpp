//Run Away (Term 2 Coursework)
//
//ofApp.cpp
//
//Created by Adam M Bader 19.03.2017

#include "ofApp.h"

using namespace std;

//--------------------------------------------------------------------------------------------

void ofApp::setup() {

	//sets welcome screen
	gameState = "start";

	//assign the player's positions
	posX = ofGetMouseX();
	posY = ofGetMouseY();

	//creating a player
	player = new Player(posX, posY);
	player->setup();
	objects.push_back(player);


	//creating enemies
	for (int i = 0; i < numEnemies; i++) {
		xEnemiesPosition = ofRandom(50, 2 * ofGetWidth());
		yEnemiesPosition = ofRandom(0, ofGetHeight());
		Enemies *enemy = new Enemies(xEnemiesPosition, yEnemiesPosition);
		objects.push_back(enemy);
		enemy->setup();
	}
}

//--------------------------------------------------------------------------------------------

void ofApp::update() {

	//the algorithm to remove objects has been adapted from Marco's shooting inheritance example
	if (gameState == "game") {

		for (int i = 0; i < objects.size() - 1; i++) {
			for (int j = i + 1; j < objects.size(); j++) {

				objects[i]->collide((objects[j]));//allows array of objects to collide
			}
		}

		auto toRemove = remove_if(objects.begin(), objects.end(), [](inGameObjects *ob) {
			
			bool dead = !ob->isAlive();	//dead is true if the object is not alive
			if (dead) {

				delete ob; //this deletes the game objects

			}

			return dead;

		});

		objects.erase(toRemove, objects.end());
	}

}

//--------------------------------------------------------------------------------------------

void ofApp::draw() {

	//gets us to different states of the game
	if (gameState == "start") {
		ofBackground(0);

		ofDrawBitmapString("Press any key to start except ESC!", ofGetWidth()/2 - 50, ofGetHeight()/2);
		ofDrawBitmapString("MOUSE to Move", ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 30);
		ofDrawBitmapString("SPACE to Shoot", ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 60);
	}

	if (gameState == "game") {
		ofSetBackgroundColor(0);
		
		//Draws the objects
		for (inGameObjects *ob : objects) {
			ob->draw();
		}
	}

}

//--------------------------------------------------------------------------------------------

void ofApp::keyPressed(int key) {
	gameState = "game";

	if (key == ' ') {
		xBullet = player->pos.x + 40;
		yBullet = player->pos.y + 30;
		bullet = new Bullets(xBullet, yBullet, 15, 5);
		objects.push_back(bullet);
	}
}

//--------------------------------------------------------------------------------------------

void ofApp::keyReleased(int key) {
	
}

/*

References:
http://openframeworks.cc/ofBook/chapters/OOPs!.html
http://openframeworks.cc/learning/02_graphics/how_to_load_and_display_an_image/
https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
https://learn.gold.ac.uk/course/view.php?id=6639&section=15 
https://learn.gold.ac.uk/course/view.php?id=6639&section=14

Some code taken from Marco's Example: Shooter Inheritance Example
*/