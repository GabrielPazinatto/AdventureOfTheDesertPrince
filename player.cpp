#include "player.h"
#include "collisions.h"
#include <iostream>

using std::cout;

Vector2 Player::getSpeed() {
	return this->speed;
}

Vector2 Player::getPos() {
	return this->pos;
}

Vector2 Player::getSizeVec() {
	return this->size;
}

Vector2 Player::getVelocity() {
	return this->velocity;
}

Rectangle Player::getRec() {
	return {
		this->pos.x,
		this->pos.y,
		this->size.x,
		this->size.y
	};
}

float Player::getSpeedX() {
	return this->speed.x;
}

float Player::getSpeedY() {
	return this->speed.y;
}

void Player::draw() {
	DrawRectangleV(this->pos, this->size, RED);
}

bool Player::willLeaveScreen() {
	return false;
}

void Player::resetVelocity() {

	this->velocity = { 1, 1 };

}

void Player::move() {

	Direction vertical = NONE;
	Direction horizontal = NONE;
	float norm;

	if (IsKeyDown(KEY_W)) vertical = UP;
	if (IsKeyDown(KEY_S)) vertical = DOWN;

	if (IsKeyDown(KEY_A)) horizontal = LEFT;
	if (IsKeyDown(KEY_D)) horizontal = RIGHT;

	if (IsKeyDown(KEY_W) and IsKeyDown(KEY_S)) vertical = NONE;
	if (IsKeyDown(KEY_A) and IsKeyDown(KEY_D)) horizontal = NONE;

	if (vertical != NONE and horizontal != NONE) {
		norm = sqrt(PLAYER.velocity.x * PLAYER.velocity.x + PLAYER.velocity.y * PLAYER.velocity.y);

		PLAYER.velocity.x /= norm;
		PLAYER.velocity.y /= norm;

	}
	else this->resetVelocity();

	if (vertical == DOWN and not playerWillCollideDir(DOWN))
		this->pos.y += this->speed.y *this->velocity.y;
	if (vertical == UP and not playerWillCollideDir(UP))
		this->pos.y -= this->speed.y * this->velocity.y;

	if(horizontal == RIGHT and not playerWillCollideDir(RIGHT))
		this->pos.x += this->speed.x * this->velocity.x;
	if (horizontal == LEFT and not playerWillCollideDir(LEFT))
		this->pos.x -= this->speed.x * this->velocity.x;

	//std::cout << this->speed.x * this->velocity.x << " " << this->speed.y * this->velocity.y << '\n';

	//std::cout << this->pos.x << " " << this->pos.y << std::endl;

}

void Player::shoot() {
	Direction vertical = NONE;
	Direction horizontal = NONE;
	Bullet bullet;

	Vector2 initialPos = this->pos;
	initialPos.x += PLAYER.getSizeVec().x / 2;
	initialPos.y += PLAYER.getSizeVec().y / 2;

	if (IsKeyPressed(KEY_UP)) vertical = UP;
	if (IsKeyPressed(KEY_DOWN)) vertical = DOWN;
	if (IsKeyPressed(KEY_LEFT)) horizontal = LEFT;
	if (IsKeyPressed(KEY_RIGHT)) horizontal = RIGHT;

	if (vertical == NONE and horizontal == NONE) return;

	bullet.setPos(initialPos);
	bullet.setDirection(vertical, horizontal);
	bullet.normalizeSpeed();

	BULLETS.push_back(bullet);

}

//not class member functions:

void handlePlayer() {

	PLAYER.move();
	PLAYER.draw();
	PLAYER.shoot();
	
}

Player PLAYER;