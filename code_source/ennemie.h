#ifndef ENNEMIE_H_INCLUDED
#define ENNEMIE_H_INCLUDED

typedef enum STATE STATE;

struct Ennemi{
	int orientation;
	int esprit;
	
	SDL_Surface *image;
	
	SDL_Rect position;
	SDL_Rect positionRelative;
	
	int tempsActuel;
	
	SDL_Rect clipsRight[20];
	SDL_Rect clipsLeft[20];
	
	int speed;
	int frame;
	int status;
};

typedef struct Ennemi ennemi;

#endif