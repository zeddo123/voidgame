#include <SDL/SDL.h>

#define twist(a,b,c,d) a = 0; b = 1; c = 1; d = 1;

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

	#define MENU_FILE_PLAY "../src/design/new_menu/menu_gif/new_menu_1920_play.gif"
	#define MENU_FILE_SET "../src/design/new_menu/menu_gif/new_menu_1920_setting.gif"
	#define MENU_FILE_QUIT "../src/design/new_menu/menu_gif/new_menu_1920_quit.gif"
	#define LOGO "../src/design/logo_jeu/png-white-contour.png"
	#define PLAY_B_STATIC "../src/design/botton/play/b_play_low.png"
	#define PLAY_B_OVER "../src/design/botton/play/b_play_over_low.png"
	#define QUIT_B_STATIC "../src/design/botton/quit/b_quit_low.png"
	#define QUIT_B_OVER "../src/design/botton/quit/b_quit_over_low.png"
	#define SET_B_STATIC "../src/design/botton/setting/b_setting_low.png"
	#define SET_B_OVER "../src/design/botton/setting/b_setting_over_low.png"
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

	#define MENU_FILE_FRAME_1 "../src/design/Main_menu/lastmenu_f1_1080.png"
	#define MENU_FILE_FRAME_2 "../src/design/Main_menu/lastmenu_f2_1080.png"
	#define MENU_FILE_FRAME_3 "../src/design/Main_menu/lastmenu_f3_1080.png"
	#define MENU_FILE_FRAME_4 "../src/design/Main_menu/lastmenu_f4_1080.png"
	#define MENU_FILE_FRAME_5 "../src/design/Main_menu/lastmenu_f5_1080.png"
	#define MENU_FILE_FRAME_6 "../src/design/Main_menu/lastmenu_f6_1080.png"
	#define MENU_FILE_FRAME_7 "../src/design/Main_menu/lastmenu_f7_1080.png"

	#define MENU_FILE_PLAY "../src/design/new_menu/menu_gif/new_menu_720_play.gif"
	#define MENU_FILE_SET "../src/design/new_menu/menu_gif/new_menu_720_setting.gif"
	#define MENU_FILE_QUIT "../src/design/new_menu/menu_gif/new_menu_720_quit.gif"
	#define LOGO "../src/design/logo_jeu/logo_jeu_low_png.png"
	#define PLAY_B_STATIC "../src/design/botton/play/b_play_low.png"
	#define PLAY_B_OVER "../src/design/botton/play/b_play_over_low.png"
	#define QUIT_B_STATIC "../src/design/botton/quit/b_quit_low.png"
	#define QUIT_B_OVER "../src/design/botton/quit/b_quit_over_low.png"
	#define SET_B_STATIC "../src/design/botton/setting/b_setting_low.png"
	#define SET_B_OVER "../src/design/botton/setting/b_setting_over_low.png"
#endif

typedef struct{
	int dx, dy;
	int height, width;
}hero;

void moveToMouse(hero *player, int dx, int dy);

void move(hero *player, int xy, int i);

void eventHandler(hero *player, SDL_Rect *positionPlayer, char *ptr_game, char *ptr_in_menu, char *ptr_job);

int checkImageLoad(SDL_Surface *set[], int index, int maxIndex);

void displayFormatFrame(SDL_Surface *set[], int maxframes);

void moveBetweenTwo(hero *entit, int axe, int a, int b, int *i);

void nextFrame(int *frame, int maxframes);

void loadFrames(SDL_Surface *set[], int maxframes, char file_name[]);