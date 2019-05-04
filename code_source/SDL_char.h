//Header file of the characters
#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED

struct hero{
	int orientation;
	int moveWithMouse;
	SDL_Surface *image;
	SDL_Rect position;
	SDL_Rect positionRelative;

	SDL_Rect clipsRight[20];
	SDL_Rect clipsLeft[20];
	
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

struct projectile{
	SDL_Rect position;
	SDL_Rect where;
	SDL_Rect positionRelative;
	SDL_Surface* image;
	int active;
	int axe;
};

typedef struct projectile projectile;
typedef struct hero hero;

#endif