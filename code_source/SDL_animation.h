#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<stdlib.h>
#include<stdio.h>
#include "SDL_char.h"

void set_clips(hero *player);
void build(hero *player);
void show(hero *player);
void handle_events(hero *player);
void start(int *started, int *paused, int *startTicks);
int get_ticks(int started, int paused, int startTicks, int pausedTicks);
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip); 
