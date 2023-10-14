#include "collisions.h"
#include <iostream>

bool playerObstacleCollision() {
	int i;
	Rectangle obstacleRec;
	Rectangle playerRec = player.getFutureRec();

	for (i = 0; i < obstacles.size(); i++) {

		obstacleRec = obstacles[i].getRec();

		if (CheckCollisionRecs(obstacleRec, playerRec)) {
			std::cout << "collision\n";
			return true;
		}
	}
	
	return false;
}