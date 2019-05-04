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
	
	#define SELECT1_B_STATIC " "
	#define SELECT1_B_OVER " "
	
	#define SELECT2_B_STATIC " "
	#define SELECT2_B_OVER " "
	
	#define SELECT3_B_STATIC " "
	#define SELECT3_B_OVER " "
	
	#define SELECT_MENU " "
	

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