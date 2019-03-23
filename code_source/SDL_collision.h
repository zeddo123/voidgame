//Header file of the collisions
#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include <SDL/SDL.h>

typedef struct{
    int x, y;
    int r;
}Circle;

double distanceSquared(int x1, int y1, int x2, int y2);

int collisionBxC(Circle a, SDL_Rect b);

int collisionCxC(Circle a, Circle b);

int collisionBox(SDL_Rect a, SDL_Rect b);

#endif
