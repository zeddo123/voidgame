#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<stdlib.h>
#include<stdio.h>
#include "SDL_char.h"

void start(int *started, int *paused, int *startTicks);

//void move_animation(hero *player);

void show(hero *player, SDL_Surface *screen);

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* frame);

//void build(hero *player);

void set_clips(hero *player);

int get_ticks(int *started , int *paused , int *startTicks ,int *pausedTicks);