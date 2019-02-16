#include <SDL/SDL.h>
#define twist(a,b,c) a = 0; b = 1; c = 1;

typedef struct{
	int dx;
	int dy;
	int vdx;
	int vdy;
}hero;

void move(hero *player,int dx, int dy, char mouse);

void eventHandler(hero *player, SDL_Rect *positionPlayer, char *ptr_game, char *ptr_in_menu, char *ptr_job);