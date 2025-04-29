#include "ui.h"
#include "spaceship.h"

void drawHealthBar(Spaceship *spaceship){
    int i;
    for(i=0; i< spaceship->health; i++){
        DrawCircle(80+(30*i),50, 10, RED);
    }
}