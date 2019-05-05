#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL_char.h"
#include "SDL_enigme.h"
#include "SDL_Game.h"
#include "ennemie.h"
#include "minimap.h"
#include <SDL/SDL_rotozoom.h>


menu initSelectMenu();

menu initMainMenu();

menu initPlayMenu(menu main);

menu initSettingsMenu(menu main);

int checkImageLoad(SDL_Surface *set[], int index, int maxIndex);

void displayFormatFrame(SDL_Surface *set[], int maxframes);

void nextFrame(int *frame, int maxframes);

void loadFrames(SDL_Surface *set[], int maxframes, char file_name[]);

SDL_Surface* loadImage(char file_name[]);

SDL_Rect initPosition(SDL_Rect position, int x, int y, int w, int h);

hero initHero(hero h, char image_name[], int x, int y);

ennemi initEnnemie(ennemi e, char image_name[], int x, int y);

object initObject(object o, char image_name[], int x, int y);

enigme loadTextForRiddle(enigme e);

enigme initPrintRiddle(enigme e);

void init_minimap(minimap *m,SDL_Surface *ecran);

#endif