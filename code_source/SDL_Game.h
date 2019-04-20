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

#define STEP 20
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define FHD // or HD

#ifdef FHD
//positions of the buttons
	#define FROM 250
	#define PLAY_FROM 248
	#define SET_FROM 448
	#define QUIT_FROM 682

	#define MAIN_MENU "../src/design/zoom_menu/frames.txt"
	#define PLAY_MENU "../src/design/Main_menu/frames.txt"

	#define LOGO "../src/design/final menu/menu_no_buttons.png"

	#define PLAY_B_STATIC "../src/design/final menu/play_button_0.png"
	#define PLAY_B_OVER "../src/design/final menu/play_button_1.png"

	#define QUIT_B_STATIC "../src/design/final menu/quit_button_0.png"
	#define QUIT_B_OVER "../src/design/final menu/quit_button_1.png"

	#define SET_B_STATIC "../src/design/final menu/settings_button_0.png"
	#define SET_B_OVER "../src/design/final menu/settings_button_1.png"
	
	#define NEWGAME_B_STATIC "../src/design/final menu/newgame_button_0.png"
	#define NEWGAME_B_OVER "../src/design/final menu/newgame_button_1.png"

	#define BACK_B_STATIC "../src/design/final menu/return_button_0.png"
	#define BACK_B_OVER "../src/design/final menu/return_button_1.png"

	#define LOADGAME_B_STATIC "../src/design/final menu/loadgame_button_0.png"
	#define LOADGAME_B_OVER "../src/design/final menu/loadgame_button_1.png"

#endif

#ifdef HD
//positions of the buttons
	#define FROM 150
	#define PLAY_FROM 148
	#define SET_FROM 248
	#define QUIT_FROM 382
	
	#define MAIN_MENU "../src/design/zoom_menu_720p/frames.txt"
	#define PLAY_MENU "../src/design/Main_menu_720p/frames.txt"

	#define LOGO "../src/design/final menu/menu_no_buttons_720.png"

	#define PLAY_B_STATIC "../src/design/final menu/play_button_0_720.png"
	#define PLAY_B_OVER "../src/design/final menu/play_button_1_720.png"

	#define QUIT_B_STATIC "../src/design/final menu/quit_button_0_720.png"
	#define QUIT_B_OVER "../src/design/final menu/quit_button_1_720.png"

	#define SET_B_STATIC "../src/design/final menu/settings_button_0_720.png"
	#define SET_B_OVER "../src/design/final menu/settings_button_1_720.png"
	
	#define NEWGAME_B_STATIC "../src/design/final menu/newgame_button_0_720.png"
	#define NEWGAME_B_OVER "../src/design/final menu/newgame_button_1_720.png"

	#define BACK_B_STATIC "../src/design/final menu/return_button_0_720.png"
	#define BACK_B_OVER "../src/design/final menu/return_button_1_720.png"

	#define LOADGAME_B_STATIC "../src/design/final menu/loadgame_button_0_720.png"
	#define LOADGAME_B_OVER "../src/design/final menu/loadgame_button_1_720.png"

#endif

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
#endif