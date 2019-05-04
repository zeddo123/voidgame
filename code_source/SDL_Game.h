#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "SDL_src_struct.h"
#include "SDL_char.h"	
#include "SDL_move.h"
#include "SDL_animation.h"
#include "SDL_collision.h"
#include "SDL_free.h"
#include "SDL_Init.h"
#include "SDL_global_var.h"

void eventHandler(hero *player, char *ptr_game, char *ptr_in_menu, char *ptr_job, 
					SDL_Surface *calque_game, SDL_Rect camera, SDL_Rect *positionMouse);


void menuEventHandler(menu *mainMenu, menu playMenu, menu settingMenu, char *ptr_job, int *ptr_menuFrame, int *ptr_menuKey, char *ptr_in_menu, Mix_Chunk *effect, Uint32 *oldTimeKey, SDL_Surface *screen, int *oldVolume);

void openPlayMenu(char *ptr_job, Mix_Chunk *effect, menu playMenu, SDL_Surface *screen);

void play(char *ptr_in_menu, char *ptr_job, SDL_Surface *screen);

menu overWhat(Mix_Chunk *effect, int *menu_key, menu m);

void menuBlitter(SDL_Surface *screen, menu m, int menu_key, int next);

int moveInMenuByKeyboard(int pointeur, int operation, int a, int b, Uint32 *oldTime);

void twist(int *a, int *b, int *c, int *d);

void settingsEventHandler(int *job, int *oldVolume, SDL_Rect fullBar, menu settings);

void openSettingMenu(int* oldVolume, SDL_Surface* screen, menu settings);

void setVolume(int volumeValue);

hero selectCharacter(SDL_Surface* screen);

int eventSelect(menu m, int *job, int *ptr_menuKey, Uint32 *oldTimeKey);

#endif