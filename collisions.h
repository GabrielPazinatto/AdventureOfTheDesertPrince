#pragma once

#include "obstacle.h"
#include "player.h"
#include "monster.h"
#include "bullet.h"

bool recCollidesWithObstacle(Rectangle rec);
bool playerWillCollideDir(Direction direction);
bool monsterWillCollide(Monster monster);
bool monsterWillCollideDir(Monster monster, Direction dir);
bool monsterCollidesWithBullet(Monster monster);
bool circleCollidesWithObstacle(float radius, Vector2 pos);
