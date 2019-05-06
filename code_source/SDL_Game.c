//the main code of the game
/**
* @file SDL_Game.c
* @brief Testing program
* @author voidprod
* @date Apr 01,2019

*/
#include "SDL_Game.h"


int main(void)
{
	SDL_Surface *screen = NULL;
	
	SDL_Event event;
	SDL_Event event_in_game;

	Uint32 oldTime = 0, currentTime = 0, oldTimeKey = -100, oldTimeEntite = 0;

	Mix_Music *music = NULL; //pointer of the music

	Mix_Chunk *effect = NULL; //pointer of the sound effect

	hero player;

	struct Menu mainMenu, playMenu, settingsMenu;

	int dx_cursor = 0, dy_cursor = 0;
	
	int next = 0;//first frame of the animation of the menu
	
	int dx_cursor_in_game = 0, dy_cursor_in_game = 0;
	
	char job = 1;
	char game = 1;
	char in_menu = 1;

	int menu_key = -1;

	int oldVolume = 128;//max volume

	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("unable to init SDL %s\n", SDL_GetError());
		return 1;
	}

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) != 0){
		return 1;
	}

	SDL_WM_SetCaption("Escapeism",NULL); //set the caption

	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,0,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	if(screen == NULL){
		printf("unable to set video mode %s\n", SDL_GetError());
		return 1;
	}
	mainMenu = initMainMenu();
	playMenu = initPlayMenu(mainMenu);
	settingsMenu = initSettingsMenu(mainMenu);

	music = Mix_LoadMUS("../src/sound/Dylan_Locke_-_Lasagna_(The_Remix_Instrumental).wav"); // load the music
	if(music == NULL){
		printf("->cant load the music \n");
		return 1;
	}

	effect = Mix_LoadWAV("../src/sound/effect1.wav");//load the sound effects
	if(effect == NULL){
		printf("->cant load the sound effect %s\n",Mix_GetError());
		return 1;
	}

	SDL_BlitSurface(mainMenu.background[next],NULL,screen,NULL);

	if(Mix_PlayMusic(music,-1) == 1){ //play music
		printf("cant play music ->%s\n",Mix_GetError());
		return 1;
	}

	while(job){
		menuEventHandler(&mainMenu,playMenu,settingsMenu,&job,&next,&menu_key,&in_menu,effect,&oldTimeKey,screen,&oldVolume);
		
		if(in_menu){
			mainMenu = overWhat(effect,&menu_key,mainMenu);

			currentTime = SDL_GetTicks();
			if(currentTime - oldTime > 100){
				nextFrame(&next,19);
				oldTime = currentTime;
			}
			menuBlitter(screen,mainMenu,menu_key,next);
		}
	}
	
	SDL_FreeSurface(mainMenu.menuLogo);
	
	freeMenu(mainMenu,19);
	freeMenu(playMenu,7);
	
	freeSettingsMenu(settingsMenu);

	Mix_FreeMusic(music);
	Mix_FreeChunk(effect);
	Mix_CloseAudio();

	SDL_Quit();

	return 0;
}
