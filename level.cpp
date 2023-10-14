#include <iostream>
#include <fstream>
#include <string>

#include "level.h"


void readLevelFile() {
	int i, j;
	std::ifstream levelFile("level\\level1.txt");
	char temp;

	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLLUMNS; j++) {

			levelFile >> temp;

			LEVEL[i][j] = temp;

			std::cout << temp;

		}
		std::cout << '\n';
	}


}

char LEVEL[ROWS][COLLUMNS];