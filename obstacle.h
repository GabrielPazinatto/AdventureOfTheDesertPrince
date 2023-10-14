#pragma once

#include <raylib.h>
#include <vector>

class Obstacle {
private:

	Vector2 pos = { -50, -50 };
	Vector2 size = { 40, 40 };

public:

	Rectangle getRec();


};

static std::vector<Obstacle> obstacles;