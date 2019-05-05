#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unistd.h>

typedef struct MinimapCursor
{
	SDL_Surface *Up, *Down, *Left, *Right, *image, *minimap , *entite;
    SDL_Rect pos,posminimap,pos2;
}minimap;

void Afficher_Minimap(SDL_Surface * ecran, SDL_Event event,minimap *minimap,SDL_Rect posplayer , SDL_Rect posEntite);

#endif
