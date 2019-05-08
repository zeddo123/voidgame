#ifndef CONDITION_H_INCLUDED
#define CONDITION_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "SDL_gestion.h"
#include "SDL_char.h"

void condition_fin(char *game, hero player, health h, keys key, SDL_Surface* screen);

#endif