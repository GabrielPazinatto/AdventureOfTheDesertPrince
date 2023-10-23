#include "collisions.h"
#include <iostream>

bool recCollidesWithObstacle(Rectangle rec){
	int i;

	for (i = 0; i < OBSTACLES.size(); i++) 
		if (CheckCollisionRecs(rec, OBSTACLES[i].getRec()))
			return true;

	return false;
}

bool circleCollidesWithObstacle(float radius, Vector2 pos) {
	int i;

	for (i = 0; i < OBSTACLES.size(); i++)
		if (CheckCollisionCircleRec(pos, radius, OBSTACLES[i].getRec()))
			return true;

	return false;
}

bool playerWillCollideDir(Direction direction) {
	Rectangle playerRec = PLAYER.getRec();

	switch (direction) {
	case UP:
		playerRec.y -= PLAYER.getSpeed().y * PLAYER.getVelocity().y;
		return recCollidesWithObstacle(playerRec);

	case DOWN:
		playerRec.y += PLAYER.getSpeed().y * PLAYER.getVelocity().y;
		return recCollidesWithObstacle(playerRec);

	case LEFT:
		playerRec.x -= PLAYER.getSpeed().x * PLAYER.getVelocity().x;
		return recCollidesWithObstacle(playerRec);

	case RIGHT:
		playerRec.x += PLAYER.getSpeed().x * PLAYER.getVelocity().x;
		return recCollidesWithObstacle(playerRec);

	default:
		return false;
	}

	return false;
}

bool monsterWillCollideDir(Monster monster, Direction dir) {

	return false;
}

bool monsterWillCollide(Monster monster) {
	Rectangle monsterRec = monster.getRec();

	monsterRec.x += monster.getSpeed().x;
	monsterRec.y += monster.getSpeed().y;

	return recCollidesWithObstacle(monsterRec);
}

bool monsterCollidesWithBullet(Monster monster) {
	int i;
	Vector2 bulletPos;
	float radius;
	Rectangle monsterRec = monster.getRec();

	for (i = 0; i < BULLETS.size(); i++) {

		bulletPos = BULLETS[i].getPos();
		radius = BULLETS[i].getRadius();

		if (CheckCollisionCircleRec(bulletPos, radius, monsterRec)) {
			BULLETS.erase(BULLETS.begin() + i);
			return true;
		}
		
	}
	
	return false;

}

