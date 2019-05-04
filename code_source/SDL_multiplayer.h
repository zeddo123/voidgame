#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "SDL_char.h"
#include "SDL_global_var.h"
#include "SDL_Init.h"
#include "SDL_Game.h"
#include "SDL_scrolling.h"
#include "SDL_gestion.h"
#include "SDL_animation.h"
#include "SDL_collision.h"
#include "SDL_arduino.h"

void playMultiplayer(char *ptr_in_menu, char *ptr_job, SDL_Surface *screen);

void eventHandlerMultiplayer(hero *player1, hero *player2,
				char *ptr_game, char *ptr_in_menu, char *ptr_job, SDL_Surface *calque_game,
				SDL_Rect camera1, SDL_Rect camera2,
				SDL_Rect *positionMouse1, SDL_Rect *positionMouse2);