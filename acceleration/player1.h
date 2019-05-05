#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "bg.h"
#include "son.h"

//#include "collision.h"




struct player 
{
   SDL_Rect pos;
    SDL_Surface *perso_bas[3],*perso_left[3],*perso_right[3],*perso_up[3],*perso_leftdown[2],*perso_leftup[2],*perso_rightup[2],*perso_rightdown[2],*fen;
    int vitess;
  
};
typedef struct player player;

struct speed
{
 int s,s_tick,runing;
};
typedef struct speed speed;

struct move
{
 int up,down,left,right;
};
typedef struct move move;

struct saut
{
 double v_x,v_grav,v_y,v_saut;
 int j;
};
typedef struct saut saut;

void init_player(player *p,move *m,speed *sp,saut *jump);
void init_player2(player *p,move *m,speed *sp,saut *jump);
void display_player(player *p ,SDL_Surface *ecran);
void saut_jump (player *p,saut *jump);
void dsaut_jump (player *p,saut *jump);
void Acceleration(speed *sp);
void Decceleration(speed *sp);
int collision_Parfaite(background *map,player *p,SDL_Rect pos,int decalage,int d);
void handle_input( SDL_Event event, player *p,SDL_Surface *ecran,background *map,int *i,SDL_Rect pos,move *m,son s,speed *sp,saut *jump, FILE *f);
void handle_input2( SDL_Event event, player *p,SDL_Surface *ecran,background *map,int *i,SDL_Rect pos,move *m,son s,speed *sp,saut *jump);
void handle_inputsouris( SDL_Event event, player *p,SDL_Surface *ecran,background *map,int *i,SDL_Rect pos,move *m,son s,speed *sp);


#endif /* PLAYER_H */
