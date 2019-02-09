#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main(void)
{
	SDL_Surface *screen = NULL;
	SDL_Surface *menu = NULL;

	SDL_Rect positionScreen;
	SDL_Rect positionDestination = {0, 0, 0, 0};

	SDL_Event event;

	int dx_cursor = 0,dy_cursor = 0;
	char job = 1;
	char in_menu = 1;

	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("unable to init SDL %d\n", SDL_GetError());
		return 1;
	}

	screen = SDL_SetVideoMode(1920,1080,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(screen == NULL){
		printf("unable to set video mode %s\n", SDL_GetError());
		return 1;
	}

	SDL_Surface *tmp = IMG_Load("../src/menu1.png");
	if (tmp == NULL){
		printf("unable to load image %s\n", SDL_GetError());
		return 1;
	}

	menu = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	if(menu == NULL){
		printf("unable to load menu %s\n", SDL_GetError());
		return 1;
	}

	//iniatilizing the positions
	positionScreen.x = 0;
	positionScreen.y = 0;
	positionScreen.w = menu->w;
	positionScreen.h = menu->h;

	SDL_BlitSurface(menu,&positionScreen,screen,&positionDestination);
		SDL_Flip(screen);

	while(job){
		SDL_PollEvent(&event);

		switch(event.type){
			case SDL_QUIT:
				printf("..Quiting the menu..\n");
				job = 0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						menu = SDL_DisplayFormat(IMG_Load("../src/menu1.png"));
						in_menu = 1;
						break;
				}
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button){
					case SDL_BUTTON_LEFT:
						SDL_GetMouseState(&dx_cursor,&dy_cursor);
						if(dx_cursor >= 434 && dx_cursor <= 1486){
							
							if(dy_cursor >= 371 && dy_cursor <= 529){
								menu = SDL_DisplayFormat(IMG_Load("../src/play.jpg")); //load the game to the player
								in_menu = 0;
							}else if (dy_cursor >= 596 && dy_cursor <= 754){
								menu = SDL_DisplayFormat(IMG_Load("../src/settings.jpg")); //load the setting to the user
								in_menu = 0;
							}else if (dy_cursor >= 821 && dy_cursor <= 979){
								job = 0;
							}

							break;
						}
				}
				break;
		}
		
		if(in_menu){
			
			SDL_GetMouseState(&dx_cursor,&dy_cursor);
			if(dx_cursor >= 434 && dx_cursor <= 1486){
							
				if(dy_cursor >= 371 && dy_cursor <= 529){
					menu = SDL_DisplayFormat(IMG_Load("../src/menu1_play_mouseover.png")); //load the mouseover play
				}else if (dy_cursor >= 596 && dy_cursor <= 754){
					menu = SDL_DisplayFormat(IMG_Load("../src/menu1_set_mouseover.png")); //load the mouseover settings
				}else if (dy_cursor >= 821 && dy_cursor <= 979){
					menu = SDL_DisplayFormat(IMG_Load("../src/menu1_quit_mouseover.png")); //load the mouseover quit
				}else{
					menu = SDL_DisplayFormat(IMG_Load("../src/menu1.png"));
				}
			}else{
				menu = SDL_DisplayFormat(IMG_Load("../src/menu1.png"));
			}
		}
		SDL_BlitSurface(menu,&positionScreen,screen,&positionDestination);
		SDL_Flip(screen);

	}

	SDL_FreeSurface(menu);

	SDL_Quit();

	return 0;
}