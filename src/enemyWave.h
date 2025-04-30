#ifndef ENEMYWAVE_H
#define ENEMYWAVE_H
#include "enemy.h"

typedef struct EnemyWave{
    Enemy **enemies;
    int enemyAmount;
    int currentEnemyAmount;
    int active;
} EnemyWave;

EnemyWave initEnemyWave(int enemyAmount);
void updateEnemyWave(EnemyWave *enemyWave);
void drawEnemyWave(EnemyWave *enemyWave);
void freeEnemyWave(EnemyWave *enemyWave);

#endif