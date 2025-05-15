#include "enemyWave.h"
#include "enemy.h"
#include "world.h"
#include "raylib.h"
#include <stdlib.h>

void drawEnemyWave(EnemyWave *enemyWave){
    drawEnemies(enemyWave->enemies, enemyWave->enemyAmount);
}

void updateEnemyWave(EnemyWave *enemyWave, World *world){
    int i;
    for (i=0; i<enemyWave->enemyAmount; i++){
        Enemy *enemy = enemyWave->enemies[i];
        enemyWave->currentEnemyAmount -= updateEnemy(enemy, world); 
    }
    if(enemyWave->currentEnemyAmount == 0){
        freeEnemyWave(enemyWave);
        *enemyWave = createNewWave(enemyWave->wave+1);
    }
}

void freeEnemyWave(EnemyWave *enemyWave){
    int i;
    for(i=0; i < enemyWave->enemyAmount; i++){
        free(enemyWave->enemies[i]);
    }
    free(enemyWave->enemies);
}

void resetWaves(EnemyWave *enemyWave){
    freeEnemyWave(enemyWave);
    enemyWave->wave = 1;
    *enemyWave = createNewWave(1);
}

EnemyWave createNewWave(int wave){
    switch(wave){
        case 1:
            return createEnemyWaveOne(wave);
            break;
        case 2:
            return createEnemyWaveTwo(wave);
            break;
        case 3:
            return createEnemyWaveThree(wave);
            break;
        case 4:
            return createEnemyWaveFour(wave);
            break;
        case 5:
            return createEnemyWaveFive(wave);
            break;
        default:
            return createEnemyWaveTwo(wave);
            break;
    }
}

EnemyWave createEnemyWaveOne(int wave){
    EnemyWave enemyWave;
    enemyWave.wave = wave;
    enemyWave.enemyAmount = 3;
    enemyWave.currentEnemyAmount = enemyWave.enemyAmount;
    Enemy **enemies = malloc(sizeof(*enemies) * enemyWave.enemyAmount);
    int i;
    for(i=0; i<enemyWave.enemyAmount; i++){
        Enemy *enemy = createBasicEnemy();
        enemy->rectangle.x = GetScreenWidth() + enemy->rectangle.width;
        enemy->rectangle.y = (200 * i) + 200;
        enemy->speed = 5;
        enemies[i] = enemy;
    }
    enemyWave.enemies = enemies;
    return enemyWave;
}

EnemyWave createEnemyWaveTwo(int wave){
    EnemyWave enemyWave;
    enemyWave.wave = wave;
    int basicEnemies = 3;
    int beefEnemies = 2;
    enemyWave.enemyAmount = basicEnemies + beefEnemies;
    enemyWave.currentEnemyAmount = enemyWave.enemyAmount;
    Enemy **enemies = malloc(sizeof(*enemies) * enemyWave.enemyAmount);
    //basic enemies
    int i;
    for(i=0; i<basicEnemies; i++){
        Enemy *enemy = createBasicEnemy();
        enemy->rectangle.x = GetScreenWidth() + enemy->rectangle.width;
        enemy->rectangle.y = (i+1) * (GetScreenHeight()/(basicEnemies+1));
        enemy->y_speed = 3+i;
        enemies[i] = enemy;
    }
    for(i=basicEnemies; i<enemyWave.enemyAmount; i++){
        Enemy *enemy = createBeefEnemy();
        enemy->rectangle.x = GetScreenWidth() + enemy->rectangle.width;
        enemy->rectangle.y = (i-basicEnemies+1) * (GetScreenHeight()/(beefEnemies+1));
        enemies[i] = enemy;
    }
    enemyWave.enemies = enemies;
    return enemyWave;
}

EnemyWave createEnemyWaveThree(int wave){
    EnemyWave enemyWave;
    enemyWave.wave = wave;
    enemyWave.enemyAmount = 6;
    enemyWave.currentEnemyAmount = enemyWave.enemyAmount;
    Enemy **enemies = malloc(sizeof(*enemies) * enemyWave.enemyAmount);
    int i;
    for(i=0; i<enemyWave.enemyAmount; i++){
        Enemy *enemy = createFastEnemy();
        enemy->rectangle.x = GetScreenWidth() + enemy->rectangle.width + (200*i);
        enemy->rectangle.y = 200;
        enemy->speed = 6;
        enemy->pattern=SIN_PATTERN;
        enemies[i] = enemy;
    }
    enemyWave.enemies = enemies;
    return enemyWave;
}

EnemyWave createEnemyWaveFour(int wave){
    EnemyWave enemyWave;
    enemyWave.wave = wave;
    int basic = 3;
    int beef = 3;
    int fast = 3;
    enemyWave.enemyAmount = basic + beef + fast;
    enemyWave.currentEnemyAmount = enemyWave.enemyAmount;
    Enemy **enemies = malloc(sizeof(*enemies) * enemyWave.enemyAmount);
    int i;
    for(i=0; i<basic; i++){
        Enemy *enemy = createBasicEnemy();
        enemy->rectangle.x = GetScreenWidth() + enemy->rectangle.width + (200);
        enemy->rectangle.y = 0;
        enemy->speed = 7;
        enemy->y_speed = i;
        enemies[i] = enemy;
    }
    for(i=basic; i<basic+beef; i++){
        Enemy *enemy = createBeefEnemy();
        enemy->rectangle.x = GetScreenWidth() + enemy->rectangle.width + (200);
        enemy->rectangle.y = 0;
        enemy->y_speed = i;
        enemies[i] = enemy;
    }
    for(i=basic+beef; i<enemyWave.enemyAmount; i++){
        Enemy *enemy = createFastEnemy();
        enemy->rectangle.x = GetScreenWidth() + enemy->rectangle.width + (200 * (i-6));
        enemy->rectangle.y = 200;
        enemy->pattern = SIN_PATTERN;
        enemy->speed = 5;
        enemies[i] = enemy;
    }
    enemyWave.enemies = enemies;
    return enemyWave;
}

EnemyWave createEnemyWaveFive(int wave){
    EnemyWave enemyWave;
    enemyWave.wave = wave;
    enemyWave.enemyAmount = 16;
    enemyWave.currentEnemyAmount = enemyWave.enemyAmount;
    Enemy **enemies = malloc(sizeof(*enemies) * enemyWave.enemyAmount);
    int i;
    for(i=0; i<enemyWave.enemyAmount; i++){
        Enemy *enemy = createBeefEnemy();
        enemy->rectangle.x = GetScreenWidth() + enemy->rectangle.width;
        enemy->rectangle.y = ((enemy->rectangle.height+10) * i);
        enemy->speed = (rand() % 6) + 5;
        enemies[i] = enemy;
        enemy->pattern = RAND_PATTERN;
    }
    enemyWave.enemies = enemies;
    return enemyWave;
}
