#include "monster.h"
#include "collisions.h"
#include "level.h"

#include <iostream>

std::vector<Monster> MONSTERS;

Vector2 Monster::getSizeVec() {
	return this->size;
}

Vector2 Monster::getSpeed() {
	return this->speed;
}

Vector2 Monster::getPos() {
	return this->pos;
}

Rectangle Monster::getRec() {
	return 
	{ this->pos.x,
	this->pos.y,
	this->getSizeVec().x,
	this->getSizeVec().y
	};
}

void Monster::setPos(Vector2 newPos) {
	this->pos = newPos;
}

void Monster::resetSpeed() {
	this->speed = this->initialSpeed;
}

void Monster::seekPos(Vector2 destiny) {
	this->resetSpeed();

	float deltaX = this->pos.x - destiny.x;
	float deltaY = this->pos.y - destiny.y;

	float distance = sqrt(deltaX * deltaX + deltaY * deltaY);

	this->speed.x = deltaX / distance;
	this->speed.y = deltaY / distance;

	this->pos.x -= this->speed.x;
	this->pos.y -= this->speed.y;

	//std::cout << this->speed.x << " " << this->speed.y << std::endl;

}

void Monster::draw() {

	DrawRectangleV(this->pos, this->getSizeVec(), PINK);

}

void Monster::move() {
	//se nao colidir move normalmente
	//se colidir vai para outro lado
	
	if (not monsterWillCollide(*this)) {
		this->seekPos(PLAYER.getPos());
		return;}

}

void updateMonsterVector() {
	int i, j;
	Monster monster;

	for (i = 0; i < ROWS ; i++) {
		for (j = 0; j < COLLUMNS; j++) {

			if (LEVEL[i][j] == 'M') {

				monster.setPos({
					(float)j * 50,
					(float)i * 50 });

				MONSTERS.push_back(monster);
			}
		}
	}
}

void killMonsters() {
	int i;

	for (i = 0; i < MONSTERS.size(); i++) {
		if (monsterCollidesWithBullet(MONSTERS[i]))
			MONSTERS.erase(MONSTERS.begin() + i);
	}
}

void handleMonsters() {
	int i;

	killMonsters();

	for (i = 0; i < MONSTERS.size(); i++) {

		MONSTERS[i].draw();
		MONSTERS[i].move();

	}
}