#include <iostream>
#include <raylib.h>

#include "player.h"
#include "collisions.h"
#include "level.h"
#include "monster.h"

using namespace std;

const int screenWidth = 1200;
const int screenHeight = 900;

int main(void) {

	InitWindow(screenWidth, screenHeight, "Adventure of the Desert Prince");
	SetTargetFPS(60);

	readLevelFile();
	updateObstacleVector();
	updateMonsterVector();

	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(RAYWHITE);

		handlePlayer();
		handleObstacles();
		handleMonsters();
		handleBullets();

		//DrawRectangleRec(PLAYER.getFutureRec(), YELLOW);

		EndDrawing();
	}

	CloseWindow();
}