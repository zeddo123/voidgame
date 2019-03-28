#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED

#include <SDL/SDL.h>
#include "SDL_collision.h"
#include "SDL_char.h"

struct health{
	int vie;
	SDL_Rect position;
	SDL_Surface *font_vie;
};

typedef struct health health;

struct keys{
	int keys;
	SDL_Rect position;
	SDL_Surface *font_key;
};

typedef struct keys keys;

health gestionVie(hero player, hero villain, health vie, Uint32 *oldTime);

keys gestionKey(keys key, int x, int x2);

#endif
