#include "collisions.h"
#include <iostream>

bool playerObstacleCollision() {
	int i;
	Rectangle obstacleRec;
	Rectangle playerRec = PLAYER.getFutureRec();

	for (i = 0; i < OBSTACLES.size(); i++) {

		obstacleRec = OBSTACLES[i].getRec();

		if (CheckCollisionRecs(obstacleRec, playerRec)) {
			std::cout << "collision\n";
			return true;
		}
	}

	return false;
}

bool playerObstacleCollisionX() {

	if (PLAYER.getRec().x == PLAYER.getFutureRec().x) return false;

	int i;
	Rectangle obstacleRec;
	Rectangle playerRec = PLAYER.getFutureRec();

	for (i = 0; i < OBSTACLES.size(); i++) {

		obstacleRec = OBSTACLES[i].getRec();

		if (CheckCollisionRecs(obstacleRec, playerRec)) {
			std::cout << "x\n";
			return true;
		}
	}

	return false;

}

bool playerObstacleCollisionY() {

	if (PLAYER.getRec().y == PLAYER.getFutureRec().y) return false;

	int i;
	Rectangle obstacleRec;
	Rectangle playerRec = PLAYER.getFutureRec();

	for (i = 0; i < OBSTACLES.size(); i++) {

		obstacleRec = OBSTACLES[i].getRec();

		if (CheckCollisionRecs(obstacleRec, playerRec)) {
			std::cout << "y\n";
			return true;
		}
	}

	return false;
}