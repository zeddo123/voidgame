#ifndef ATACK_H_INCLUDED
#define ATACK_H_INCLUDED

#include "SDL_global_var.h"
#include "SDL_Init.h"
#include "SDL_free.h"
#include "SDL_char.h"
#include <SDL/SDL.h>

void moveProjectile(projectile *p);

projectile launchProjectile(projectile p, SDL_Rect positionlaunch, int axe);
#endif