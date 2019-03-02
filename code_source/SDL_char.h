//Hearder file of the characters
#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED

struct hero{
	int orientation;
	SDL_Surface *image;
	SDL_Rect position;
};
typedef struct hero hero;

#endif