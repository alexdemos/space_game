#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "raylib.h"

static const int START_X = 200;

static const int BASE_DAMAGE = 10;
static const int DAMAGE_INC = 10;
static const int DAMAGE_POS = 0;

static const int BASE_SPEED = 5;
static const int SPEED_INC = 1;
static const int SPEED_POS = 1;

static const int BASE_FIRE_RATE = 20;
static const int FIRE_RATE_INC = -2;
static const int FIRE_RATE_POS = 2;

static const int BASE_BULLET_SPEED = 10;
static const int BULLET_SPEED_INC = 5;
static const int BULLET_SPEED_POS = 3;

static const int BASE_HEALTH = 3;
static const int HEALTH_INC = 1;
static const int HEALTH_POS = 4;

static const int BASE_RANGE = 300;
static const int RANGE_INC = 10;
static const int RANGE_POS = 5;

static const int BASE_COST = 50;
static const int COST_INC = 50;


typedef struct Spaceship
{
    Rectangle rectangle;
    Color color;
    int speed;
    int damage;
    int fire_rate;
    int cooldown;
    int bullet_speed;
    int bullet_count;
    int health;
    int total_health;
    int isInvincible;
    int points;
    int range;
} Spaceship;

Spaceship initSpaceship();

void updateSpaceship(Spaceship *spaceship);
void updateSpaceshipPos(Spaceship *spaceship);
void drawSpaceship(Spaceship *spaceship);
void fire(Spaceship *spaceship);
int calculateNumberOfUpgrades(Spaceship *spaceship, int property_index);
void resetAfterDeath(Spaceship *spaceship);

#endif