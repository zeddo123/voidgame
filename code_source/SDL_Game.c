//the main code of the game
#include "SDL_Game.h"


int main(void)
{
	SDL_Surface *screen = NULL;
	SDL_Surface *menu = NULL;
	SDL_Surface *menu_setting = NULL;
	SDL_Surface *menu_frame[19];
	SDL_Surface *playmenu[7];
	SDL_Surface *font_surface = NULL;
	SDL_Surface *play[2];
	SDL_Surface *set[2];
	SDL_Surface *quit[2];
	SDL_Surface *newGame[2];
	SDL_Surface *loadGame[2];
	SDL_Surface *back[2];
	SDL_Surface *logo = NULL;

	SDL_Rect positionScreen;
	SDL_Rect positionText;
	SDL_Rect positionPlay;
	SDL_Rect positionQuit;
	SDL_Rect positionSet;
	SDL_Rect positionLogo;
	SDL_Rect logoCrop;
	SDL_Rect positionNewGame;
	SDL_Rect positionLoadGame;
	SDL_Rect positionBack;

	SDL_Event event;
	SDL_Event event_in_game;

	SDL_Color fontColor = {255, 255, 255};

	Uint32 oldTime = 0, currentTime = 0, oldTimeKey = -100, oldTimeEntite = 0;

	Mix_Music *music = NULL; //pointer of the music

	Mix_Chunk *effect = NULL; //pointer of the sound effect

	TTF_Font *font = NULL;

	hero player;

	int dx_cursor = 0, dy_cursor = 0;
	int next = 0;
	int dx_cursor_in_game = 0, dy_cursor_in_game = 0;
	char job = 1;
	char game = 1;
	char in_menu = 1;
	int over_play = 1, over_set = 1, over_quit = 1, licence = 1;
	int menu_key = -1;

	int oldVolume = 128;

	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("unable to init SDL %s\n", SDL_GetError());
		return 1;
	}

	if(TTF_Init() == -1){
		return 1;
	}

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) != 0){
		return 1;
	}

	font = TTF_OpenFont("../src/font/Baron Neue.otf",30);
	font_surface = TTF_RenderText_Blended(font,"void prod .Inc\tgame under the MIT licence",fontColor);
	if(font_surface == NULL || font == NULL){
		printf("unable to TTF_RenderText_Solid\n");
		return 1;
	}

	SDL_WM_SetCaption("Escapeism",NULL); //set the caption

	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,0,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	if(screen == NULL){
		printf("unable to set video mode %s\n", SDL_GetError());
		return 1;
	}

	// load the menu background
	loadFrames(menu_frame,19,MAIN_MENU);
	// load the play menu
	loadFrames(playmenu,7,PLAY_MENU);

	//load the play botton
	play[1] = loadImage(PLAY_B_STATIC);
	play[0] = loadImage(PLAY_B_OVER);

	//load the setting botton
	set[1] = loadImage(SET_B_STATIC);
	set[0] = loadImage(SET_B_OVER);

	//load the quit botton
	quit[1] = loadImage(QUIT_B_STATIC);
	quit[0] = loadImage(QUIT_B_OVER);

	//load the new game botton
	newGame[1] = loadImage(NEWGAME_B_STATIC);
	newGame[0] = loadImage(NEWGAME_B_OVER);

	//load the load game botton
	loadGame[1] = loadImage(LOADGAME_B_STATIC);
	loadGame[0] = loadImage(LOADGAME_B_OVER);

	//load the return botton
	back[1] = loadImage(BACK_B_STATIC);
	back[0] = loadImage(BACK_B_OVER);

	//load logo
	logo = loadImage(LOGO);

	//menu setting
	menu_setting = SDL_DisplayFormat(IMG_Load("../src/design/bazar/wallhaven-553699.png"));

	displayFormatFrame(menu_frame,19);
	displayFormatFrame(playmenu,7);
	displayFormatFrame(play,3);
	displayFormatFrame(set,3);
	displayFormatFrame(quit,3);
	displayFormatFrame(newGame,3);
	displayFormatFrame(loadGame,3);
	displayFormatFrame(back,3);


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


	//iniatilizing the positions
	positionScreen = initPosition(positionScreen,0,0,SCREEN_WIDTH,SCREEN_WIDTH);

	positionPlay = initPosition(positionPlay,150 + logo->w/ 2 - play[0]->w / 2,PLAY_FROM,play[0]->w,play[0]->h);

	positionQuit = initPosition(positionQuit,150 + logo->w/ 2 - quit[0]->w / 2,QUIT_FROM,quit[0]->w,quit[0]->h);

	positionSet = initPosition(positionSet,150 + logo->w/ 2 - set[0]->w / 2,SET_FROM,set[0]->w,set[0]->h);

	positionNewGame = initPosition(positionPlay,150 + logo->w/ 2 - newGame[0]->w / 2,PLAY_FROM,newGame[0]->w,newGame[0]->h);

	positionBack = initPosition(positionBack,150 + logo->w/ 2 - back[0]->w / 2,QUIT_FROM,back[0]->w,back[0]->h);

	positionLoadGame = initPosition(positionLoadGame,150 + logo->w/ 2 - loadGame[0]->w / 2,SET_FROM,loadGame[0]->w,loadGame[0]->h);
	

	positionText = initPosition(positionText, positionPlay.x+300, positionQuit.y + positionQuit.h + 70,font_surface->w,font_surface->h);

	positionLogo = initPosition(positionLogo,150,0,logo->w,logo->h);

	logoCrop = initPosition(logoCrop,0,40,logo->w,logo->h);

	//starting everything
	SDL_BlitSurface(menu_frame[next],&positionScreen,screen,NULL);

	if(Mix_PlayMusic(music,-1) == 1){ //play music
		printf("cant play music ->%s\n",Mix_GetError());
		return 1;
	}

	while(job){
		menuEventHandler(menu,&job,&next,&menu_key,&in_menu,effect,&oldTimeKey,positionScreen,screen,positionText,font_surface,logoCrop,positionLogo,logo,play,set,quit,positionNewGame,newGame,positionLoadGame,loadGame,positionBack,back,playmenu,menu_frame,menu_setting,&oldVolume);
		
		if(in_menu){
			
			overWhat(effect,&menu_key,positionPlay.x,positionPlay.x + positionPlay.w, positionPlay.y,positionPlay.y+positionPlay.h, positionSet.y,positionSet.y + positionSet.h, positionQuit.y,positionQuit.y + positionQuit.h, positionPlay.x,positionPlay.x+positionPlay.w,positionQuit.h+positionQuit.y+50,1080, &over_play,&over_set,&over_quit,&licence);

			currentTime = SDL_GetTicks();
			if(currentTime - oldTime > 100){
				menu = menu_frame[next];
				nextFrame(&next,19);
				oldTime = currentTime;
			}
			menuBlitter(positionScreen,screen,menu,positionText,font_surface,logoCrop,positionLogo,logo,positionPlay,play,positionSet,set,positionQuit,quit,over_play,over_set,over_quit,licence,menu_key);
		}
	}

	SDL_FreeSurface(menu);
	SDL_FreeSurface(font_surface);
	SDL_FreeSurface(logo);

	for(int i = 0;i < 19;i++){
		SDL_FreeSurface(menu_frame[i]);
		SDL_FreeSurface(playmenu[i]);
	}

	for(int i = 0;i < 3;i++){
		SDL_FreeSurface(play[i]);
		SDL_FreeSurface(set[i]);
		SDL_FreeSurface(quit[i]);
		SDL_FreeSurface(newGame[i]);
		SDL_FreeSurface(loadGame[i]);
		SDL_FreeSurface(back[i]);
	}
	Mix_FreeMusic(music);
	Mix_FreeChunk(effect);
	Mix_CloseAudio();
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();

	return 0;
}
