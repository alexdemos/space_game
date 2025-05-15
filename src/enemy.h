#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"
#include "world.h"

static int const LINE_PATTERN = 0;
static int const SIN_PATTERN = 1;
static int const RAND_PATTERN = 2;

typedef struct enemy{
    int health;
    int speed;
    int y_speed;
    int pattern;
    int active;
    int init;
    int points;
    Color color;
    Rectangle rectangle;
} Enemy;

//return 1 if enemy died
int updateEnemy(Enemy *enemy, World *world);
void updateY(Enemy *enemy);
void drawEnemies(Enemy **enemies, int amount);
void drawEnemy(Enemy *enemy);
void clearEnemy(Enemy *enemy);

//enemy creation
Enemy* createBasicEnemy();
Enemy* createBeefEnemy();
Enemy* createFastEnemy();

#endif