#pragma once
#include <raylib.h>

class Player {
private:

	//velocity: changes speed's direction, stays in the interval {0 ,1}
	//speed: pixels moved per frame

	Vector2 velocity = { 1, 1 };         //player's normalized speed vector
	Vector2 speed = { 5, 5 };			 //player's speed multiplier
	Vector2 pos = { 100, 100 };          //player's position on screen
	Vector2 futurePos = { 100, 100 };
	Vector2 size = { 40, 40 };           //player's collision box size

public:

	Vector2 getSpeed();             //returns player's speed as Vector2
	Vector2 getVelocity();          //returns player's velocity as Vector2
	Vector2 getPos();               //returns player's pos as Vector2
	Vector2 getSizeVec();           //returns player's size as Vector2
	Rectangle getRec();             //returns a rectangle with the same position and size vectors as player's pos and siz
	float getSpeedX();              //returns player's horizontal speed
	float getSpeedY();              //returns player's vertical speed
	bool willLeaveScreen();
	void move();	                //moves the player
	void draw();                    //draws player's texture
	void resetVelocity();
	void shoot();


};

enum Direction : unsigned char {

	UP = 'w', LEFT = 'a', DOWN = 's', RIGHT = 'd', NONE = ' '

};

enum Axis : unsigned char {

	X = 'x', Y = 'y'

};

void handlePlayer(); //executes every player-related function

extern Player PLAYER;