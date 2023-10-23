#include "bullet.h"
#include <iostream>

std::vector<Bullet> BULLETS;

void Bullet::setDirection(Direction vertical, Direction horizontal) {

	this->vertical = vertical;
	this->horizontal = horizontal;

}

void Bullet::setPos(Vector2 newPos) {
	this->pos = newPos;
}

void Bullet::normalizeSpeed() {
	float norm;

	if (this->vertical != NONE and this->horizontal != NONE) {
		norm = sqrt(this->velocity.x * this->velocity.x + this->velocity.y * this->velocity.y);

		this->velocity.x /= norm;
		this->velocity.y /= norm;

	}
}

void Bullet::move() {

	Direction vertical = this->vertical;
	Direction horizontal = this->horizontal;

	if (vertical == UP) this->pos.y -= this->speed.y;
	if (vertical == DOWN) this->pos.y += this->speed.y;

	if (horizontal == LEFT) this->pos.x -= this->speed.x;
	if (horizontal == RIGHT) this->pos.x += this->speed.x;

}

float Bullet::getRadius() {
	return this->radius;
}

Vector2 Bullet::getPos() {
	return this->pos;
}

void Bullet::draw() {
	DrawCircleV(this->pos, this->radius, BLACK);
}

void deleteBullets() {
	int i, j;
	float radius;
	Vector2 bulletPos;

	for (i = 0; i < BULLETS.size(); i++) {

		radius = BULLETS[i].getRadius();
		bulletPos = BULLETS[i].getPos();

		if (circleCollidesWithObstacle(radius, bulletPos)) {
			BULLETS.erase(BULLETS.begin() + i);
			continue;
		}
		
		if (bulletPos.x < 0 or bulletPos.y < 0) {
			BULLETS.erase(BULLETS.begin() + i);
			continue;
		}

		if (bulletPos.x > GetScreenWidth() or bulletPos.y > GetScreenHeight()) {
			BULLETS.erase(BULLETS.begin() + i);
			continue;
		}
	}
}

void handleBullets() {
	int i;

	deleteBullets();

	for (i = 0; i < BULLETS.size(); i++) {

		BULLETS[i].draw();
		BULLETS[i].move();

		std::cout << BULLETS.size() << std::endl;
	}
}