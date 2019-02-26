#include <SDL/SDL.h>

#define twist(a,b,c) a = 0; b = 1; c = 1;

#define STEP 4
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define FHD // or HD

#ifdef FHD
//positions of the buttons
	#define FROM 32
	#define TO 895
	#define PLAY_FROM 168
	#define PLAY_TO 314
	#define SET_FROM 398
	#define SET_TO 554
	#define QUIT_FROM 632
	#define QUIT_TO 778

	#define MENU_FILE_FRAME_1 "../src/design/new_menu/menu_1080p/1/menu_frame1_1080.png"
	#define MENU_FILE_FRAME_2 "../src/design/new_menu/menu_1080p/1/menu_frame2_1080p.png"
	#define MENU_FILE_FRAME_3 "../src/design/new_menu/menu_1080p/1/menu_frame3_1080p.png"
	#define MENU_FILE_FRAME_4 "../src/design/new_menu/menu_1080p/1/menu_frame4_1080.png"
	#define MENU_FILE_FRAME_5 "../src/design/new_menu/menu_1080p/1/menu_frame5_1080.png"
	#define MENU_FILE_FRAME_6 "../src/design/new_menu/menu_1080p/1/menu_frame6_1080.png"
	#define MENU_FILE_FRAME_7 "../src/design/new_menu/menu_1080p/1/menu_frame7_1080.png"
	#define MENU_FILE_FRAME_8 "../src/design/new_menu/menu_1080p/1/menu_frame8_1080.png"

	#define MENU_FILE_PLAY "../src/design/new_menu/menu_gif/new_menu_1920_play.gif"
	#define MENU_FILE_SET "../src/design/new_menu/menu_gif/new_menu_1920_setting.gif"
	#define MENU_FILE_QUIT "../src/design/new_menu/menu_gif/new_menu_1920_quit.gif"
#endif

#ifdef HD
//positions of the buttons
	#define FROM 20
	#define TO 598
	#define PLAY_FROM 112
	#define PLAY_TO 210
	#define SET_FROM 264
	#define SET_TO 364
	#define QUIT_FROM 422
	#define QUIT_TO 520

	#define MENU_FILE_FRAME_1 "../src/design/new_menu/menu_720p/1/menu_frame1_720p.png"
	#define MENU_FILE_FRAME_2 "../src/design/new_menu/menu_720p/1/menu_frame2_720p.png"
	#define MENU_FILE_FRAME_3 "../src/design/new_menu/menu_720p/1/menu_frame3_720p.png"
	#define MENU_FILE_FRAME_4 "../src/design/new_menu/menu_720p/1/menu_frame4_720p.png"
	#define MENU_FILE_FRAME_5 "../src/design/new_menu/menu_720p/1/menu_frame5_720p.png"
	#define MENU_FILE_FRAME_6 "../src/design/new_menu/menu_720p/1/menu_frame6_720p.png"
	#define MENU_FILE_FRAME_7 "../src/design/new_menu/menu_720p/1/menu_frame7_720p.png"
	#define MENU_FILE_FRAME_8 "../src/design/new_menu/menu_720p/1/menu_frame8_720p.png"

	#define MENU_FILE_PLAY "../src/design/new_menu/menu_gif/new_menu_720_play.gif"
	#define MENU_FILE_SET "../src/design/new_menu/menu_gif/new_menu_720_setting.gif"
	#define MENU_FILE_QUIT "../src/design/new_menu/menu_gif/new_menu_720_quit.gif"
#endif

typedef struct{
	int dx, dy;
	int height, width;
}hero;

void moveToMouse(hero *player, int dx, int dy);

void move(hero *player, int xy, int i);

void eventHandler(hero *player, SDL_Rect *positionPlayer, char *ptr_game, char *ptr_in_menu, char *ptr_job);

int checkImageLoad(SDL_Surface *set[], int index, int maxIndex);

void nextFrame(int *frame, int maxframes);