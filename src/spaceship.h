#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "raylib.h"

typedef struct Spaceship
{
    Rectangle rectangle;
    float speed;
    float damage;
    float fire_rate;
    float bullet_speed;
} Spaceship;

Spaceship initSpaceship();

void updateSpaceshipPos(Spaceship *spaceship);
void drawSpaceship(Spaceship *spaceship);
void fire(Spaceship *spaceship);

#endif