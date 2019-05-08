#ifndef SAVEGAME_H_INCLUDED
#define SAVEGAME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL_char.h"
#include "SDL_gestion.h"


void SaveGame(hero player, int vie, int keys,  char filename[50]);
void LoadGame(hero *player, int* vie, int* keys, char filename[50]);

#endif