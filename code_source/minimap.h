#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unistd.h>


void Afficher_Minimap(SDL_Surface * screen, SDL_Rect posplayer , SDL_Rect posEntite, SDL_Rect poskey1, SDL_Rect poskey2);

SDL_Rect makeItSmall(SDL_Rect minimap, SDL_Rect position);
#endif