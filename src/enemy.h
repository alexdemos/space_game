#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"

typedef struct enemy{
    int health;
    int speed;
    int active;
    int init;
    Color color;
    Rectangle rectangle;
} Enemy;

//return 1 if enemy died
int updateEnemy(Enemy *enemy);
void drawEnemies(Enemy **enemies, int amount);
void drawEnemy(Enemy *enemy);
void clearEnemy(Enemy *enemy);

//enemy creation
Enemy* createBasicEnemy();
Enemy* createBeefEnemy();
Enemy* createFastEnemy();

#endif