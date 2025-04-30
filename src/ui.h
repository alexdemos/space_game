#ifndef UI_H
#define UI_H
#include "spaceship.h"
#include "enemyWave.h"
#include "raylib.h"

void drawUI(Spaceship *spaceship, EnemyWave *enemyWave);
void drawHealthBar(Spaceship *spaceship);
void drawEnemiesRemaining(EnemyWave *enemyWave);

#endif