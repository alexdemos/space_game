#ifndef UI_H
#define UI_H
#include "spaceship.h"
#include "enemyWave.h"
#include "world.h"
#include "raylib.h"

void drawUI(Spaceship *spaceship, EnemyWave *enemyWave, World *world);
void drawHealthBar(Spaceship *spaceship);
void drawEnemiesRemaining(EnemyWave *enemyWave);
void drawPoints(World *world);

#endif