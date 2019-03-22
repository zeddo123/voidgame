#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "SDL_Init.h"
#include "SDL_char.h"
#include "SDL_move.h"

#define STEP 4
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define HD // or HD

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
	#define FROM 250
	#define PLAY_FROM 248
	#define SET_FROM 448
	#define QUIT_FROM 682
	
	#define MAIN_MENU "../src/design/zoom_menu_720p/frames.txt"
	#define PLAY_MENU "../src/design/Main_menu_720p/frames.txt"

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

void eventHandler(hero *player, char *ptr_game, char *ptr_in_menu, char *ptr_job);

void menuEventHandler(SDL_Surface *menu, char *ptr_job, int *ptr_menuFrame, int *ptr_menuKey, char *ptr_in_menu, Mix_Chunk *effect, Uint32 *oldTimeKey,
				SDL_Rect positionScreen, SDL_Surface *screen,
				SDL_Rect positionText, SDL_Surface *font,
				SDL_Rect logoCrop, SDL_Rect positionLogo, SDL_Surface *logo, 
				SDL_Surface *play[], SDL_Surface *set[], SDL_Surface *quit[], 
				SDL_Rect positionNewGame, SDL_Surface *newGame[], 
				SDL_Rect positionLoadGame, SDL_Surface *loadGame[], 
				SDL_Rect positionBack, SDL_Surface *back[], 
				SDL_Surface *background[], SDL_Surface *menu_frame[],
				SDL_Surface *menu_setting);


void playMenu(char *ptr_job, Mix_Chunk *effect, 
			SDL_Rect positionScreen, SDL_Surface *screen,
			SDL_Rect positionText, SDL_Surface *font, 
			SDL_Rect logoCrop, SDL_Rect positionLogo, SDL_Surface *logo, 
			SDL_Rect positionNewGame, SDL_Surface *newGame[], 
			SDL_Rect positionLoadGame, SDL_Surface *loadGame[], 
			SDL_Rect positionBack, SDL_Surface *back[], 
			SDL_Surface *background[]);

void play(char *ptr_in_menu, char *ptr_job, SDL_Rect positionScreen, SDL_Surface *screen);

void overWhat(Mix_Chunk *effect, int *menu_key,int x1a, int x1b, int y1a, int y1b, int y2a, int y2b, int y3a, int y3b, int x2a, int x2b, int y4a, int y4b, int *button1, int *button2, int *button3, int *button4);

void menuBlitter(SDL_Rect positionScreen,SDL_Surface *screen,
				SDL_Surface *background, 
				SDL_Rect positionText,SDL_Surface *font,
				SDL_Rect logoCrop, SDL_Rect positionLogo, SDL_Surface *logo,
				SDL_Rect positionB1, SDL_Surface *button1[],
				SDL_Rect positionB2, SDL_Surface *button2[],
				SDL_Rect positionB3, SDL_Surface *button3[],
				int over_b1, int over_b2, int over_b3, int over_b4, int menu_key);

int moveInMenuByKeyboard(int pointeur, int operation, int a, int b, Uint32 *oldTime);

void twist(int *a, int *b, int *c, int *d);

#endif