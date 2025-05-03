#ifndef WORLD_H
#define WORLD_H

typedef struct World{
    int start;
    int maxBullets;
    int points;
} World;

World initWorld(int maxBullets);

#endif