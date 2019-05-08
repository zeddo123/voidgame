#include "minimap.h"
#include "SDL_global_var.h"
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unistd.h>

void Afficher_Minimap(SDL_Surface * screen, SDL_Rect posplayer , SDL_Rect posEntite){
    SDL_Rect minimap = {SCREEN_WIDTH/2 - 200 ,SCREEN_HEIGHT / 2 + 270,400,200};
    SDL_Rect positionPlayer;
    SDL_Rect positionEntite;
    
    Uint32 black = SDL_MapRGB(screen->format, 12, 12, 12);
    Uint32 red = SDL_MapRGB(screen->format, 255, 12, 14);
    Uint32 purple = SDL_MapRGB(screen->format, 128,0,128);

    positionPlayer.x = minimap.x + 400 * posplayer.x / 8000;
    positionPlayer.y = minimap.y + 200 * posplayer.y / 8000;
    positionPlayer.h = 10;
    positionPlayer.w = 10;

    positionEntite.x = minimap.x + 400 * posEntite.x / 8000;
    positionEntite.y = minimap.y + 200 * posEntite.y / 8000;
    positionEntite.h = 10;
    positionEntite.w = 10;

    SDL_FillRect(screen, &minimap, black);
    SDL_FillRect(screen, &positionEntite, red);
    SDL_FillRect(screen, &positionPlayer, purple);

   
}