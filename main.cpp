#include <iostream>
#include <raylib.h>

#include "player.h"
#include "collisions.h"
#include "level.h"

using namespace std;

const int screenWidth = 1200;
const int screenHeight = 900;

int main(void) {

	InitWindow(screenWidth, screenHeight, "Adventure of the Desert Prince");

	readLevelFile();
	updateObstacleVector();

	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(RAYWHITE);

		handlePlayer();
		handleObstacles();

		DrawRectangleRec(PLAYER.getFutureRec(), YELLOW);

		EndDrawing();
	}

	CloseWindow();
}