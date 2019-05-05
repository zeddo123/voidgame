#include "minimap.h"
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unistd.h>



void Afficher_Minimap(SDL_Surface * ecran, SDL_Event event,minimap *minimap,SDL_Rect posplayer , SDL_Rect posEntite)
{
   // switch(event.type)
    //{
      //  case SDL_KEYDOWN :
            switch ( event . key . keysym . sym )
            {
            case SDLK_RIGHT:
                minimap->image = minimap->Right ;
                break;
            case SDLK_LEFT:
                minimap->image = minimap->Left ;
                break;
            case SDLK_UP:
                minimap->image = minimap->Up ;
                break;
            case SDLK_DOWN:
                minimap->image = minimap->Down ;
                break;
            }
      //  break;
    //}

    minimap->pos.x = minimap->posminimap.x + ( posplayer.x ) * 0.23 ;
    minimap->pos.y = minimap->posminimap.y + ( posplayer.y ) * 0.21 ;

    minimap->pos2.x = minimap->posminimap.x + ( posEntite.x ) * 0.09 ;
    minimap->pos2.y = minimap->posminimap.y + ( posEntite.y ) * 0.21 ;


    SDL_BlitSurface(minimap->minimap, NULL, ecran,&minimap->posminimap);
    SDL_BlitSurface(minimap->image, NULL, ecran, &minimap->pos);
    SDL_BlitSurface(minimap->entite, NULL, ecran, &minimap->pos2);

}