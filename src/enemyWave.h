#ifndef ENEMYWAVE_H
#define ENEMYWAVE_H
#include "enemy.h"
#include "world.h"

typedef struct EnemyWave{
    Enemy **enemies;
    int enemyAmount;
    int currentEnemyAmount;
    int wave;
} EnemyWave;

void updateEnemyWave(EnemyWave *enemyWave, World *world);
void drawEnemyWave(EnemyWave *enemyWave);
void freeEnemyWave(EnemyWave *enemyWave);
void resetWaves(EnemyWave *enemyWave);

//enemy wave factory
EnemyWave createNewWave(int wave);
EnemyWave createEnemyWaveOne(int wave);
EnemyWave createEnemyWaveTwo(int wave);
EnemyWave createEnemyWaveThree(int wave);
EnemyWave createEnemyWaveFour(int wave);
EnemyWave createEnemyWaveFive(int wave);

#endif