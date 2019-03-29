//Header file of the characters
#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED

struct hero{
	int orientation;
	int moveWithMouse;
	SDL_Surface *image;
	SDL_Rect position;
	SDL_Rect positionRelative;

	SDL_Rect clipsRight[4];
	SDL_Rect clipsLeft[4];
	
	int speed;
	int frame;
	int status;

};

typedef struct{
	SDL_Surface *image;
	SDL_Rect position;
	SDL_Rect positionRelative;
	int state;
}object;

typedef struct hero hero;

#endif