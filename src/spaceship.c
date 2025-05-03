#include "spaceship.h"
#include "bullet.h"
#include "raylib.h"

Spaceship initSpaceship(){
    Spaceship spaceship;
    spaceship.color = GRAY;
    spaceship.rectangle.x = 200;
    spaceship.rectangle.y = GetScreenHeight() / 2;
    spaceship.rectangle.width = 50;
    spaceship.rectangle.height = 25;
    spaceship.speed = 5;
    spaceship.damage = 10;
    spaceship.fire_rate = 20;
    spaceship.cooldown = spaceship.fire_rate;
    spaceship.bullet_count = 0;
    spaceship.bullet_speed = 10;
    spaceship.isInvincible = 0;
    spaceship.health = 0;

    return spaceship;
}

void updateSpaceship(Spaceship *spaceship){
    updateSpaceshipPos(spaceship);
    spaceship->cooldown -= 1;
}

void updateSpaceshipPos(Spaceship *spaceship){
    if(IsKeyDown(KEY_RIGHT) && spaceship->rectangle.x < GetScreenWidth() - spaceship->rectangle.width) {
        spaceship->rectangle.x += spaceship->speed;
    }
    if(IsKeyDown(KEY_LEFT) && spaceship->rectangle.x > 0) { 
        spaceship->rectangle.x -= spaceship->speed;
    }
    if(IsKeyDown(KEY_UP) && spaceship->rectangle.y > 0 ) {
        spaceship->rectangle.y -= spaceship->speed;
    }
    if(IsKeyDown(KEY_DOWN) && spaceship->rectangle.y < GetScreenHeight() - spaceship->rectangle.height) {
        spaceship->rectangle.y += spaceship->speed;
    }
}

void drawSpaceship(Spaceship *spaceship){
    DrawRectangleRec(spaceship->rectangle, spaceship->color);
}