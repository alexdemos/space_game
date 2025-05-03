#ifndef WORLD_H
#define WORLD_H

typedef struct World{
    int maxBullets;
    int points;
} World;

World initWorld(int maxBullets);

#endif