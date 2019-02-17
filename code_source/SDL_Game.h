#include <SDL/SDL.h>

#define twist(a,b,c) a = 0; b = 1; c = 1;

#define STEP 4
#define SCREEN_WIDTH 1920//1280
#define SCREEN_HEIGHT 1080//720
#define FHD // or HD

#ifdef FHD
//positions of the buttons
	#define FROM 434
	#define TO 1486
	#define PLAY_FROM 371
	#define PLAY_TO 529
	#define SET_FROM 596
	#define SET_TO 754
	#define QUIT_FROM 821
	#define QUIT_TO 979
	#define MENU_FILE "../src/menu1.png"
	#define MENU_FILE_PLAY "../src/menu1_play_mouseover.png"
	#define MENU_FILE_SET "../src/menu1_set_mouseover.png"
	#define MENU_FILE_QUIT "../src/menu1_quit_mouseover.png"
#endif

#ifdef HD
//positions of the buttons
	#define FROM 290
	#define TO 992
	#define PLAY_FROM 248
	#define PLAY_TO 352
	#define SET_FROM 396
	#define SET_TO 504
	#define QUIT_FROM 548
	#define QUIT_TO 654
	#define MENU_FILE "../src/menu1_720p.png"
	#define MENU_FILE_PLAY "../src/menu1_play_mouseover-720p.png"
	#define MENU_FILE_SET "../src/menu1_set_mouseover_720p.png"
	#define MENU_FILE_QUIT "../src/menu1_quit_mouseover_720p.png"
#endif

typedef struct{
	int dx, dy;
	int height, width;
}hero;

void moveToMouse(hero *player, int dx, int dy);

void move(hero *player, int xy, int i);

void eventHandler(hero *player, SDL_Rect *positionPlayer, char *ptr_game, char *ptr_in_menu, char *ptr_job);