#pragma once
#include <raylib.h>

class Player {
private:

	Vector2 speed = { 1, 1 };            //player's normalized speed vector
	Vector2 speedCoefficient = { 5, 5 }; //player's speed multiplier
	Vector2 pos = { 100, 100 };          //player's position on screen
	Vector2 futurePos = {100, 100};      //player's future position considering movement
	Vector2 size = { 40, 40 };           //player's collision box size

public:


	Vector2 getSpeed();             //returns player's speed as Vector2
	Vector2 getPos();               //returns player's pos as Vector2
	Vector2 getSizeVec();           //returns player's size as Vector2
	Rectangle getRec();             //returns a rectangle with the same position and size vectors as player's pos and size
	Rectangle getFutureRec();       //returns a rectangle with the same position and size vectors as player's futurePos and size
	float getSpeedX();              //returns player's horizontal speed
	float getSpeedY();              //returns player's vertical speed
	bool willLeaveScreenX();	    //detects if the player is going to leave the screen on the X axis
	bool willLeaveScreenY();	    //detects if the player is going to leave the screen on the Y axis
	void move();	                //moves the player
	void draw();                    //draws player's texture
	void updateFuturePos();         //updates player's position in the next frame based on the direction it's going

};

void handlePlayer(); //executes every player-related function

extern Player PLAYER;