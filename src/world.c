#include "world.h"

World initWorld(int maxBullets){
    World world;
    world.maxBullets = maxBullets;
    world.start = 0;
    world.points = 0;
    return world;
}