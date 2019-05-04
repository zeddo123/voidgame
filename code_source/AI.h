#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include "SDL_char.h"
#include "ennemie.h"
#include "SDL_gestion.h"
#include "SDL_move.h"
#include "SDL_animation.h"
#include "SDL_scrolling.h"


int distance(ennemi E,hero H,SDL_Rect camera);
void transitionn(ennemi *E ,hero H ,SDL_Rect camera ,health *sc ,SDL_Surface *screen,int *animation ,int *follow,int *wait,int *attack);
void moveEnnemi(ennemi *E, SDL_Rect posHero);
