#pragma once

#include <raylib.h>
#include <vector>

class Obstacle {
private:

	Vector2 pos = { -50, -50 };
	Vector2 size = { 40, 40 };

public:

	Rectangle getRec();
	Vector2 getPos();
	Vector2 getSizeVec();

	void setPos(Vector2 newPos);
	void draw();

};

void updateObstacleVector();
void handleObstacles();

extern std::vector<Obstacle> OBSTACLES;