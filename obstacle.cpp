#include "obstacle.h"
#include "level.h"

#include <iostream>

std::vector<Obstacle> OBSTACLES;

Rectangle Obstacle::getRec() {
	return {
		this->pos.x,
		this->pos.y,
		this->size.x,
		this->size.y
	};
}

Vector2 Obstacle::getPos() {
	return { this->pos.x, this->pos.y };
}

Vector2 Obstacle::getSizeVec() {
	return { this->size.x, this->size.y };
}

void Obstacle::setPos(Vector2 newPos) {
	this->pos = newPos;
}

void Obstacle::draw() {
	Color color = RAYWHITE;

	if (this->isWall) color = BLACK;
	else color = BLUE;

	DrawRectangleV(
		this->getPos(),
		this->getSizeVec(),
		color
	);
}

void updateObstacleVector() {
	int i, j;
	Obstacle obstacle;

	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLLUMNS; j++) {

			switch(LEVEL[i][j]) {

			case 'O':
				obstacle.setPos({
				(float)j * 50,
				(float)i * 50});

				obstacle.isWall = false;

				OBSTACLES.push_back(obstacle);
				break;

			case 'W':
				obstacle.setPos({
				(float) j * 50,
				(float) i * 50 });
				
				obstacle.isWall = true;

				OBSTACLES.push_back(obstacle);
				break;

			}
		}
	}
}

void handleObstacles() {
	int i;

	for (i = 0; i < OBSTACLES.size(); i++) {

		OBSTACLES[i].draw();

	}
}

