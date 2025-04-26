#include "spaceship.h"
#include "bullet.h"
#include "raylib.h"

Spaceship initSpaceship(){
    Spaceship spaceship;
    spaceship.rectangle.x = 200;
    spaceship.rectangle.y = GetScreenHeight() / 2;
    spaceship.rectangle.width = 50;
    spaceship.rectangle.height = 25;
    spaceship.speed = 5;
    spaceship.damage = 10;
    spaceship.fire_rate = 10;
    spaceship.bullet_speed = 10;

    return spaceship;
}

void updateSpaceshipPos(Spaceship *spaceship){
    if(IsKeyDown(KEY_RIGHT) && spaceship->rectangle.x < GetScreenWidth() - spaceship->rectangle.width) {
        spaceship->rectangle.x += spaceship->speed;
    }
    if(IsKeyDown(KEY_LEFT) && spaceship->rectangle.x > 0) { 
        int t = GetScreenWidth();
        spaceship->rectangle.x -= spaceship->speed;
    }
    if(IsKeyDown(KEY_UP) && spaceship->rectangle.y > 0 ) {
        int t = GetScreenHeight();
        spaceship->rectangle.y -= spaceship->speed;
    }
    if(IsKeyDown(KEY_DOWN) && spaceship->rectangle.y < GetScreenHeight() - spaceship->rectangle.height) {
        spaceship->rectangle.y += spaceship->speed;
    }
}

void drawSpaceship(Spaceship *spaceship){
    DrawRectangleRec(spaceship->rectangle, RED);
}