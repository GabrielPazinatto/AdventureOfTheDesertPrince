#include <iostream>
#include <raylib.h>

#include "player.h"

using namespace std;

const int screenWidth = 1200;
const int screenHeight = 900;

int main(void) {

	InitWindow(screenWidth, screenHeight, "Adventure of the Desert Prince");

	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(RAYWHITE);

		handlePlayer();

		EndDrawing();
	}

	CloseWindow();
}