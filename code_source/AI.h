#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include "SDL_char.h"
#include "ennemie.h"
#include "SDL_gestion.h"
#include "SDL_move.h"


int distance(ennemi E,hero H,SDL_Rect camera);
void transitionn(ennemi *E,hero H,SDL_Rect camera,SDL_Rect pos,health *sc,SDL_Surface *ecran,int *i,int *animation,int *follow,int *wait,int *attack);
