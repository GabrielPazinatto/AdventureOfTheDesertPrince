#pragma once
#include <vector>
#include "raylib.h"
#include "collisions.h"

class Bullet {
private:
	Vector2 pos = { -10, -10 };
	Vector2 speed = { 15, 15 };
	Vector2 velocity = { 15, 15 };
	float radius = 4;

	Direction vertical = NONE;
	Direction horizontal = NONE;

public:
	Vector2 getPos();

	void setDirection(Direction vertical = NONE, Direction horizontal = NONE);
	void move();
	void draw();
	void setPos(Vector2 newPos);
	void normalizeSpeed();

	float getRadius();
};

void deleteBullets();
void handleBullets();

extern std::vector<Bullet> BULLETS;