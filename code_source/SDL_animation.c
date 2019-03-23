#include"SDL_animation.h"
#include"SDL_Game.h"

void set_clips(hero *player)
{
    //On coupe la feuille de sprite à droite 
    player->clipsRight[0].x = 0;
    player->clipsRight[0].y = 0;
    player->clipsRight[0].w = player->position.w;
    player->clipsRight[0].h = player->position.h;

    player->clipsRight[1].x = player->position.w;
    player->clipsRight[1].y = 0;
    player->clipsRight[1].w = player->position.w;
    player->clipsRight[1].h = player->position.h;

    player->clipsRight[2].x = player->position.w * 2;
    player->clipsRight[2].y = 0;
    player->clipsRight[2].w = player->position.w;
    player->clipsRight[2].h = player->position.h;

    player->clipsRight[3].x = player->position.w * 3;
    player->clipsRight[3].y = 0;
    player->clipsRight[3].w = player->position.w;
    player->clipsRight[3].h = player->position.h;

    player->clipsRight[4].x = player->position.w * 4;
    player->clipsRight[4].y = 0;
    player->clipsRight[4].w = player->position.w;
    player->clipsRight[4].h = player->position.h;

    //On coupe la feuille de sprite à gauche 

    player->clipsLeft[0].x = 0;
    player->clipsLeft[0].y = player->position.h;
    player->clipsLeft[0].w = player->position.w;
    player->clipsLeft[0].h = player->position.h;

    player->clipsLeft[1].x = player->position.w;
    player->clipsLeft[1].y = player->position.h;
    player->clipsLeft[1].w = player->position.w;
    player->clipsLeft[1].h = player->position.h;

    player->clipsLeft[2].x = player->position.w * 2;
    player->clipsLeft[2].y = player->position.h;
    player->clipsLeft[2].w = player->position.w;
    player->clipsLeft[2].h = player->position.h;

    player->clipsLeft[3].x = player->position.w * 3;
    player->clipsLeft[3].y = player->position.h;
    player->clipsLeft[3].w = player->position.w;
    player->clipsLeft[3].h = player->position.h;

    player->clipsLeft[4].x = player->position.w * 4;
    player->clipsLeft[4].y = player->position.h;
    player->clipsLeft[4].w = player->position.w;
    player->clipsLeft[4].h = player->position.h;

}


void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{   clip=NULL;
    SDL_Rect offset;
 
    offset.x = x;
    offset.y = y;
 
    //On blitte la surface
    SDL_BlitSurface( source, clip, destination, &offset );
}


int get_ticks(int started , int paused , int startTicks ,int pausedTicks)
{
    //If the timer is running
    if(started == 1)
    {
        //If the timer is paused
        if(paused == 1)
        {
            //Return the number of ticks when the timer was paused
            return pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - startTicks;
        }    
    }
    
    //If the timer isn't running
    return 0;    
}

void start(int *started, int *paused, int *startTicks)
{   

    //Start the timer
    *started = 1;
    
    //Unpause the timer
    *paused = 0;
    
    //Get the current clock time
    *startTicks = SDL_GetTicks();    
}

//initialiser les parametres de mouvement / animation
void build(hero *player){
    player->pos=0;
    player->speed=0;
    player->frame=0;
    player->status=1;
}

/*void handle_events(hero *player)
{
    //Si une touche est préssée
    if( event.type == SDL_KEYDOWN )
    {
        //Mise à jour de la vitesse (speed)
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: speed += player->position.w / 4; break;
            case SDLK_LEFT: speed -= player->position.w / 4; break;
            default: break;
        }
    }
    //Si une touche est relachée
    else if( event.type == SDL_KEYUP )
    {
        //Mise à jour de la vitesse (speed)
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: speed += player->position.w / 4; break;
            case SDLK_LEFT: speed -= player->position.w / 4; break;
            default: break;
        }
    }
}*/

void show(hero *player)
{   


    //Declaration
    SDL_Rect clips[player->orientation][5];
    int FRAMES_PER_SECOND = 60;
    SDL_Surface *allFrames;
    SDL_Surface *screen;

    //Mouvement
    player->pos += player->speed;  //(absence de speed) player->pos = (player->pos)+(player->position.w);

    

    //On garde le personnage dans les limites de la fenêtre SDL
    if( ( player->pos < 0 ) || ( player->pos + player->position.w > SCREEN_WIDTH ) )
    {       
        player->pos -= player->speed; //(absence de speed) player->pos = (player->pos)-(player->position.w);
    }
    

    //Si Cat bouge à gauche
    if( player->orientation < 0 )
    {
        //On prend le personnage de profil gauche
        player->status = 0;
        //On bouge à la prochaine image de l'animation
        player->frame++;
    }
    //Si Cat bouge à droite
    else if( player->orientation > 0 )
    {
        //On prend le personnage de profil droit
        player->status = 1;

        //On bouge à la prochaine image de l'animation
        player->frame++;
    }
    //Si Cat ne bouge plus
    else
    {
        //Restart the animation
        player->frame = 1;
    }

    

    //Boucle l'animation
      if( player->frame >= 5 )
    {
        player->frame = 0;
    }

    

    //Affichage
    if( player->status == 1 )
    {
        apply_surface(player->pos, SCREEN_HEIGHT - (player->position.h), allFrames , screen, &(player->clipsRight[player->frame]));
    }
    else if( player->status == 0 )
    {
        apply_surface(player->pos, SCREEN_HEIGHT - (player->position.h), allFrames , screen, &(player->clipsLeft[player->frame]));
    }

}

   