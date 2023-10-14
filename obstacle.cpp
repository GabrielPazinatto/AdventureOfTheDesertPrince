#include "obstacle.h"

Rectangle Obstacle::getRec() {
	return {
		this->pos.x,
		this->pos.y,
		this->size.x,
		this->size.y
	};
}