#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include <SDL/SDL.h>

struct button{
	SDL_Rect position;
	SDL_Surface **image;
};

typedef struct button button;

struct Menu{
	button b1;
	button b2;
	button b3;
	button b4;
	
	button font;
	
	int over_b1;
	int over_b2;
	int over_b3;
	int over_b4;
	
	SDL_Surface *menuLogo;
	SDL_Rect menuLogoPosition;
	SDL_Rect menuLogoCrop;

	
	SDL_Surface **background;
	SDL_Rect backgroundPosition;
};

typedef struct Menu menu;

#endif