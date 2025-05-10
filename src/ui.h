#ifndef UI_H
#define UI_H
#include "spaceship.h"
#include "enemyWave.h"
#include "world.h"
#include "raylib.h"

void drawStartMenu(World *world);
void drawUpgradeMenu(Spaceship *spaceship, World *world);
void drawUpgrade(char *text, int current, int base, int inc, int pos);
void handleUpgrades(Spaceship *spaceship, World *world);
void drawUI(Spaceship *spaceship, EnemyWave *enemyWave, World *world);
void drawHealthBar(Spaceship *spaceship);
void drawEnemiesRemaining(EnemyWave *enemyWave);
void drawPoints(World *world);

#endif