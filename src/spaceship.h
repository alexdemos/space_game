#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "raylib.h"

typedef struct Spaceship
{
    Rectangle rectangle;
    Color color;
    int speed;
    int damage;
    int fire_rate;
    int bullet_speed;
    int health;
} Spaceship;

Spaceship initSpaceship();

void updateSpaceship(Spaceship *spaceship);
void updateSpaceshipPos(Spaceship *spaceship);
void drawSpaceship(Spaceship *spaceship);
void fire(Spaceship *spaceship);

#endif