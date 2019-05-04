#ifndef ENNEMIE_H_INCLUDED
#define ENNEMIE_H_INCLUDED

typedef enum STATE STATE;
struct Ennemi{
	int orientation;
	int moveWithMouse;
	int esprit;
	SDL_Surface *image,*right[3],*left[3],*up[3],*down[3];
	SDL_Rect position;
	SDL_Rect positionRelative;

	SDL_Rect clipsRight[4];
	SDL_Rect clipsLeft[4];
	
	int speed;
	int frame;
	int status;

};

typedef struct Ennemi ennemi;

#endif