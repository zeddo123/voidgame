#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL_char.h"
#include "SDL_savegame.h"
#include "SDL_gestion.h"


void SaveGame(hero player, int vie, int keys,  char filename[50])
{
    FILE * f = fopen(filename,"w+") ;
    fprintf(f, "%d\n",player.position.x);
    fprintf(f, "%d\n",player.position.y);
    fprintf(f, "%d\n",vie);
    fprintf(f, "%d\n",keys);
    fclose(f);
}

void LoadGame(hero *player, int* vie, int* keys, char filename[50])
{   int x,y;

    FILE * f = fopen(filename,"r+");
    fscanf(f,"%d",&x);
    player->position.x=x;
    fscanf(f,"%d",&y);
    player->position.y=y;
    fscanf(f,"%d",&(*vie));
    fscanf(f,"%d",&(*keys));
    fclose(f);
}