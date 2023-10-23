#pragma once

#include <raylib.h>
#include <vector>

class Monster {
private:

	Vector2 pos = { -100, -100 };
	Vector2 initialSpeed = { 1, 1 };
	Vector2 speed = { 1, 1 };
	Vector2 size = { 40, 40 };

public:

	Rectangle getRec();
	Vector2 getSpeed();

	void setPos(Vector2 newPos);
	void seekPos(Vector2 pos);
	void draw();
	void move();
	void resetSpeed();

	Vector2 getSizeVec();
	Vector2 getPos();

};

void updateMonsterVector();
void killMonsters();
void handleMonsters();

extern std::vector<Monster> MONSTERS;