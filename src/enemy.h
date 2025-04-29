#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"

typedef struct enemy{
    int health;
    int speed;
    int active;
    Color color;
    Rectangle rectangle;
} Enemy;

Enemy* initEnemy(int health, int speed, Color color, Rectangle rectangle);
void updateEnemies(Enemy **enemies, int enemyAmount);
void updateEnemy(Enemy *enemy);
void drawEnemies(Enemy **enemies, int amount);
void drawEnemy(Enemy *enemy);
void clearEnemy(Enemy *enemy);

#endif