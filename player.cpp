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

Rectangle Player::getRec() {
	return {
		this->pos.x,
		this->pos.y,
		this->size.x,
		this->size.y
	};
}

Rectangle Player::getFutureRec() {
	return {
		this->futurePos.x,
		this->futurePos.y,
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

bool Player::willLeaveScreenX() {
	
	if (this->futurePos.x <= 0) return true;
	if (this->futurePos.x > GetScreenWidth() - this->size.x) return true;

	return false;

}

bool Player::willLeaveScreenY() {
	if (this->futurePos.y <= 0) return true;
	if (this->futurePos.y > GetScreenHeight() - this->size.y) return true;

	return false;
}

void Player::updateFuturePos() {
	//changes y position
	if (IsKeyDown(KEY_W)) Player::futurePos.y -= Player::speed.y;
	else Player::futurePos.y = Player::pos.y;

	if (IsKeyDown(KEY_S)) Player::futurePos.y += Player::speed.y;
	else Player::futurePos.y = Player::pos.y;

	//changes x position
	if (IsKeyDown(KEY_A)) Player::futurePos.x -= Player::speed.x;
	else Player::futurePos.x = Player::pos.x;

	if (IsKeyDown(KEY_D)) Player::futurePos.x += Player::speed.x;
	else Player::futurePos.x = Player::pos.x;

}

void Player::move() {

	//changes y position
	if (not willLeaveScreenY() and not playerObstacleCollision()) {
		if (IsKeyDown(KEY_W)) Player::pos.y -= Player::speed.y;
		if (IsKeyDown(KEY_S)) Player::pos.y += Player::speed.y;
	}

	//changes x position
	if (not willLeaveScreenX() and not playerObstacleCollision()) {
		if (IsKeyDown(KEY_A)) Player::pos.x -= Player::speed.x;
		if (IsKeyDown(KEY_D)) Player::pos.x += Player::speed.x;
	}
}

void Player::draw() {
	DrawRectangleV(this->pos, this->size, RED);
}

//not class member functions:

void handlePlayer() {

	PLAYER.updateFuturePos();
	PLAYER.move();
	PLAYER.draw();
	
}

Player PLAYER;