#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player1.h"
#include "bg.h"



void init_player(player *p,move *m,speed *sp,saut *jump)
{
    
    
    p->pos.x=500;
    p->pos.y=300;
     p->perso_bas[0] = IMG_Load("perso/face1.png");
        p->perso_bas[1] = IMG_Load("perso/face2.png");
        p->perso_bas[2] = IMG_Load("perso/face3.png");
	p->perso_bas[3] = IMG_Load("perso/face4.png");

	p->perso_left[0] = IMG_Load("perso/left2.png");
	p->perso_left[1] = IMG_Load("perso/left1.png");
	p->perso_left[2] = IMG_Load("perso/left2.png");
	p->perso_left[3] = IMG_Load("perso/left1.png");

	p->perso_right[0] = IMG_Load("perso/right1.png");
	p->perso_right[1] = IMG_Load("perso/right2.png");
	p->perso_right[2] = IMG_Load("perso/right1.png");
	p->perso_right[3] = IMG_Load("perso/right2.png");

	p->perso_up[0] = IMG_Load("perso/dos1.png");
	p->perso_up[1] = IMG_Load("perso/dos2.png");
	p->perso_up[2] = IMG_Load("perso/dos3.png");
	p->perso_up[3] = IMG_Load("perso/dos4.png");

    p->perso_leftup[0] = IMG_Load("perso/leftup1.png");
        p->perso_leftup[1] = IMG_Load("perso/leftup2.png");

    p->perso_leftdown[0]=IMG_Load("perso/leftdown1.png");

    p->perso_leftdown[1]=IMG_Load("perso/leftdown2.png");

    p->perso_rightdown[0]=IMG_Load("perso/rightdown1.png");

    p->perso_rightdown[1]=IMG_Load("perso/rightdown2.png");

    p->perso_rightup[0]=IMG_Load("perso/rightup1.png");

    p->perso_rightup[1]=IMG_Load("perso/rightup2.png");



        p->fen=p->perso_bas[0];
        m->down=0;
        m->left=0;
        m->right=0;
        m->up=0;
        sp->s=1;
        sp->s_tick=0;
        jump->v_grav=0.08;
        jump->v_x=1.5;
        jump->v_saut=-4;
        jump->v_y=jump->v_saut;
        jump->j=0;
}

void saut_jump (player *p,saut *jump)
{
    if(!jump->j)
   { p->pos.y+=jump->v_saut;
        jump->j=1;}
   // jump->v_y=jump->v_grav;  
}

void dsaut_jump (player *p,saut *jump)
{       if(jump->j)
   { p->pos.y-=jump->v_saut;
   jump->j=0;}

   // jump->v_y=jump->v_grav;

}

void Acceleration(speed *sp)
{ 
    if( sp->s <= 5 && !sp->runing )
    {
        if(SDL_GetTicks() - sp->s_tick > 250 )
        {
            sp->s += 1 ;
            sp->s_tick = SDL_GetTicks();
        }
        if(sp->s==5)
        sp->runing=0;

    }
}

void Decceleration(speed *sp)
{ 
    if( sp->s > 2 && sp->runing )
    {
        if(SDL_GetTicks() - sp->s_tick > 250 )
        {
            sp->s -= 1 ;
            sp->s_tick = SDL_GetTicks();
        }
        if(sp->s<2)
        sp->runing=0;

    }
}

void init_player2(player *p,move *m,speed *sp,saut *jump)
{
    
    
    p->pos.x=1300;
    p->pos.y=300;
     p->perso_bas[0] = IMG_Load("perso2/face1.png");
        p->perso_bas[1] = IMG_Load("perso2/face2.png");
        p->perso_bas[2] = IMG_Load("perso2/face3.png");
	p->perso_bas[3] = IMG_Load("perso2/face4.png");

	p->perso_left[0] = IMG_Load("perso2/left2.png");
	p->perso_left[1] = IMG_Load("perso2/left1.png");
	p->perso_left[2] = IMG_Load("perso2/left2.png");
	p->perso_left[3] = IMG_Load("perso2/left1.png");

	p->perso_right[0] = IMG_Load("perso2/right1.png");
	p->perso_right[1] = IMG_Load("perso2/right2.png");
	p->perso_right[2] = IMG_Load("perso2/right1.png");
	p->perso_right[3] = IMG_Load("perso2/right2.png");

	p->perso_up[0] = IMG_Load("perso2/dos1.png");
	p->perso_up[1] = IMG_Load("perso2/dos2.png");
	p->perso_up[2] = IMG_Load("perso2/dos3.png");
	p->perso_up[3] = IMG_Load("perso2/dos4.png");

    p->perso_leftup[0] = IMG_Load("perso2/leftup1.png");
        p->perso_leftup[1] = IMG_Load("perso2/leftup2.png");

    p->perso_leftdown[0]=IMG_Load("perso2/leftdown1.png");

    p->perso_leftdown[1]=IMG_Load("perso2/leftdown2.png");

    p->perso_rightdown[0]=IMG_Load("perso2/rightdown1.png");

    p->perso_rightdown[1]=IMG_Load("perso2/rightdown2.png");

    p->perso_rightup[0]=IMG_Load("perso2/rightup1.png");

    p->perso_rightup[1]=IMG_Load("perso2/rightup2.png");


        p->fen=p->perso_bas[0];
        m->down=0;
        m->left=0;
        m->right=0;
        m->up=0;
        sp->s=1;
        sp->s_tick=0;
        jump->v_grav=0.08;
        jump->v_x=1.5;
        jump->v_saut=-4;
        jump->v_y=jump->v_saut;
        jump->j=0;
 }

void display_player(player *p,SDL_Surface *ecran)
{
    SDL_BlitSurface(p->perso_bas[0], NULL, ecran, &p->pos);
    
}

int collision_Parfaite(background *map,player *p,SDL_Rect pos,int decalage,int d)
{
       
        
     SDL_Color col;
  if(d==0)
  {
    col=GetPixel(map->mapCollision,pos.x+p->fen->w +decalage,pos.y+(p->fen->h));
  }
else  if(d==1)
  {
    col=GetPixel(map->mapCollision,pos.x+p->fen->w ,pos.y+(p->fen->h/2)+decalage);
  }
else  if(d==2)
  {
    col=GetPixel(map->mapCollision,pos.x+(p->fen->w/2)+decalage ,pos.y+(p->fen->h/2));
  }
else  if(d==3)
  {
    col=GetPixel(map->mapCollision,pos.x+(p->fen->w/2),pos.y+p->fen->h +decalage);
  }
 // printf("%d    %d   %d\n",col.r,col.b,col.g );
if ((col.r==0)&&(col.b==0)&&(col.g==0))
{
  return 1;
}
if ((col.r==255)&&(col.b==0)&&(col.g==0))
return 2;
else 
return 0;
}


void handle_input( SDL_Event event, player *p,SDL_Surface *ecran,background *map,int *i,SDL_Rect pos,move *m,son s,speed *sp,saut *jump,FILE *f)
{
       int vitess=1;
	char str[10];

       strcpy( str,"");
		fscanf(f, "%s", str);
		if(strcmp(str, "up_1")==0)
		m->up=1;
		else if(strcmp(str, "left_1")==0)
		m->left=1;
		else if(strcmp(str, "right_1")==0)
                m->right=1;
		else if(strcmp(str, "down_1")==0)
		m->down=1;
		else if(strcmp(str, "jump_1")==0)
		printf("%s\n", str);
                else if(strcmp(str, "up_0")==0)
		m->up=0;
		else if(strcmp(str, "left_0")==0)
		m->left=0;
		else if(strcmp(str, "right_0")==0)
                m->right=0;
		else if(strcmp(str, "down_0")==0)
		m->down=0;
               fprintf(f, "1");

    if( event.type == SDL_KEYDOWN )
    {
        switch(event.key.keysym.sym)
            {
		case SDLK_LSHIFT:
                Acceleration(sp);
                break;	
                case SDLK_z:
                    m->up=1;
                     
                break;
		
                case SDLK_d:
                m->right=1;
                       
                break;
                case SDLK_q:
         m->left=1;
                break;
             
                case SDLK_s:
                m->down=1;
                break;
                case SDLK_SPACE:
                saut_jump (p,jump);
                break;
                
        }
    }
    else if( event.type == SDL_KEYUP )
    {
        switch(event.key.keysym.sym)
            {
                    case SDLK_LSHIFT:
                Decceleration(sp);
                break;
			
                case SDLK_z:
                    m->up=0;
                     
                break;
		
                case SDLK_d:
                m->right=0;
                       
                break;
                case SDLK_q
                :
         m->left=0;
                break;
             
                case SDLK_s:
                m->down=0;

                break;
                case SDLK_SPACE:
                dsaut_jump (p,jump);
                break;
                
        }
    } 
     
     if((m->up) && (!m->left)&&(!m->right)){
                     if(! collision_Parfaite(map,p,pos,15,2))
                       {

                if(*i >= 3)
                *i = 0;
                p->pos.y -=vitess;
	
        	p->fen = p->perso_up[*i];
                (*i)++; 
                       }
                       else 
                                play_collision(s);
                     
                }
		 if((m->up) && (m->left) && (!m->right)){
                     if(! collision_Parfaite(map,p,pos,15,2))
                       {

                if(*i > 1)
                *i = 0;

                p->pos.y -=vitess;
                p->pos.x -=vitess;
	
        	p->fen = p->perso_leftup[*i];
                (*i)++; 
                       }

                       else 
                                play_collision(s);
                     
                }
		 if((m->up) && (!m->left) && (m->right)){
                     if(! collision_Parfaite(map,p,pos,15,2))
                       {

                if(*i > 1)
                *i = 0;
                p->pos.y -=vitess;
                p->pos.x += vitess;
	
        	p->fen = p->perso_rightup[*i];
                (*i)++; 
                       }

                       else 
                                play_collision(s);
                     
                }
		
                if((m->right)&&(!m->up)&&(!m->down)){
                                       if(! collision_Parfaite(map,p,pos,15,0))
                                       {

               if(p->pos.x+p->fen->w<ecran->w-p->fen->w){
		if(*i>=3)
                *i=0;
                p->pos.x += vitess;
        	p->fen=p->perso_right[*i];
           (*i)++; }
         
                                       }

                       else 
                                play_collision(s);
                       
                }
                if((m->left)&&(!m->up)&&(!m->down) ){
                 
                                  if(! collision_Parfaite(map,p,pos,15,1))
{
		if(*i >= 3)
                *i = 0;
                p->pos.x -= vitess;
	
        	p->fen=p->perso_left[*i];
                (*i)++;
              
}

                       else 
                                play_collision(s);

                }
             
                if((m->down)&&(!m->right)&&(!m->left)){
                                       if(! collision_Parfaite(map,p,pos,15,3))
{
		if(p->pos.y+p->fen->h<ecran->h){
                if(*i >= 3)
                *i = 0;
                p->pos.y += vitess;

        	p->fen=p->perso_bas[*i];
                (*i)++;}
              
}

                       else 
                                play_collision(s);

                }
                               if((m->down) && (m->right) && (!m->left)){
                                       if(! collision_Parfaite(map,p,pos,15,3))
{
		if(p->pos.y+p->fen->h<ecran->h){
                if(*i > 1)
                *i = 0;
                p->pos.y +=vitess;
                p->pos.x +=vitess;

        	p->fen=p->perso_rightdown[*i];
                (*i)++;}
              
}

                       else 
                                play_collision(s);

                }
                               if((m->down) && (!m->right) && (m->left)){
                                       if(! collision_Parfaite(map,p,pos,15,3))
{
		if(p->pos.y+p->fen->h<ecran->h){
                if(*i > 1)
                *i = 0;
                p->pos.y += vitess;
                p->pos.x -= vitess;

        	p->fen=p->perso_leftdown[*i];
                (*i)++;}
              
}

                       else 
                                play_collision(s);

                }
                
}
 


void handle_input2( SDL_Event event, player *p,SDL_Surface *ecran,background *map,int *i,SDL_Rect pos,move *m,son s,speed *sp,saut *jump)
{
       int vitess=1;

    if( event.type == SDL_KEYDOWN )
    {
        switch(event.key.keysym.sym)
            {
		case SDLK_RSHIFT:
                Acceleration(sp);
                break;	
                case SDLK_UP:
                    m->up=1;
                     
                break;
		
                case SDLK_RIGHT:
                m->right=1;
                       
                break;
                case SDLK_LEFT:
         m->left=1;
                break;
             
                case SDLK_DOWN:
                m->down=1;

                break;
                case SDLK_KP_ENTER:
                saut_jump(p,jump);
                break;
                
        }
    }
    else if( event.type == SDL_KEYUP )
    {
        switch(event.key.keysym.sym)
            {
                    case SDLK_RSHIFT:
                Decceleration(sp);
                break;
			
                case SDLK_UP:
                    m->up=0;
                     
                break;
		
                case SDLK_RIGHT:
                m->right=0;
                       
                break;
                case SDLK_LEFT:
         m->left=0;
                break;
             
                case SDLK_DOWN:
                m->down=0;

                break;

                case SDLK_KP_ENTER:
                dsaut_jump(p,jump);
                break;
                
        }
    } 
     
     if((m->up) && (!m->left)&&(!m->right)){
                     if(! collision_Parfaite(map,p,pos,15,2))
                       {

                if(*i >= 3)
                *i = 0;
                p->pos.y -=vitess;
	
        	p->fen = p->perso_up[*i];
                (*i)++; 
                       }
                       else 
                                play_collision(s);
                     
                }
		 if((m->up) && (m->left) && (!m->right)){
                     if(! collision_Parfaite(map,p,pos,15,2))
                       {

                if(*i > 1)
                *i = 0;

                p->pos.y -=vitess;
                p->pos.x -=vitess;
	
        	p->fen = p->perso_leftup[*i];
                (*i)++; 
                       }

                       else 
                                play_collision(s);
                     
                }
		 if((m->up) && (!m->left) && (m->right)){
                     if(! collision_Parfaite(map,p,pos,15,2))
                       {

                if(*i > 1)
                *i = 0;
                p->pos.y -=vitess;
                p->pos.x += vitess;
	
        	p->fen = p->perso_rightup[*i];
                (*i)++; 
                       }

                       else 
                                play_collision(s);
                     
                }
		
                if((m->right)&&(!m->up)&&(!m->down)){
                                       if(! collision_Parfaite(map,p,pos,15,0))
                                       {

               if(p->pos.x+p->fen->w<ecran->w-p->fen->w){
		if(*i>=3)
                *i=0;
                p->pos.x += vitess;
        	p->fen=p->perso_right[*i];
           (*i)++; }
         
                                       }

                       else 
                                play_collision(s);
                       
                }
                if((m->left)&&(!m->up)&&(!m->down) ){
                 
                                  if(! collision_Parfaite(map,p,pos,15,1))
{
		if(*i >= 3)
                *i = 0;
                p->pos.x -= vitess;
	
        	p->fen=p->perso_left[*i];
                (*i)++;
              
}

                       else 
                                play_collision(s);

                }
             
                if((m->down)&&(!m->right)&&(!m->left)){
                                       if(! collision_Parfaite(map,p,pos,15,3))
{
		if(p->pos.y+p->fen->h<ecran->h){
                if(*i >= 3)
                *i = 0;
                p->pos.y += vitess;

        	p->fen=p->perso_bas[*i];
                (*i)++;}
              
}

                       else 
                                play_collision(s);

                }
                               if((m->down) && (m->right) && (!m->left)){
                                       if(! collision_Parfaite(map,p,pos,15,3))
{
		if(p->pos.y+p->fen->h<ecran->h){
                if(*i > 1)
                *i = 0;
                p->pos.y +=vitess;
                p->pos.x +=vitess;

        	p->fen=p->perso_rightdown[*i];
                (*i)++;}
              
}

                       else 
                                play_collision(s);

                }
                               if((m->down) && (!m->right) && (m->left)){
                                       if(! collision_Parfaite(map,p,pos,15,3))
{
		if(p->pos.y+p->fen->h<ecran->h){
                if(*i > 1)
                *i = 0;
                p->pos.y += vitess;
                p->pos.x -= vitess;

        	p->fen=p->perso_leftdown[*i];
                (*i)++;}
              
}

                       else 
                                play_collision(s);

                }
                
}

void handle_inputsouris( SDL_Event event, player *p,SDL_Surface *ecran,background *map,int *i,SDL_Rect pos,move *m,son s,speed *sp)
{
    int x,y;
    SDL_GetMouseState(&x,&y);
    y-=p->fen->h;
       switch(event.type){

    case SDL_MOUSEBUTTONDOWN:
 if( event.button.button==SDL_BUTTON_LEFT&& p->pos.y>y && p->pos.x==x){
                     if(! collision_Parfaite(map,p,pos,15,2))
                       {

                if(*i >= 3)
                *i = 0;
                p->pos.y -=sp->s;
	
        	p->fen = p->perso_up[*i];
                (*i)++; 
                       }
                       else 
                                play_collision(s);
                     
                }
 else if( event.button.button==SDL_BUTTON_LEFT&&p->pos.x>x && p->pos.y>y){
                     if(! collision_Parfaite(map,p,pos,15,2))
                       {

                if(*i > 1)
                *i = 0;

                p->pos.y -=sp->s;
                p->pos.x -=sp->s;
	
        	p->fen = p->perso_leftup[*i];
                (*i)++; 
                       }

                       else 
                                play_collision(s);
                     
                }
 else if( event.button.button==SDL_BUTTON_LEFT&& p->pos.x<x && p->pos.y>y){
                     if(! collision_Parfaite(map,p,pos,15,2))
                       {

                if(*i > 1)
                *i = 0;
                p->pos.y -=sp->s;
                p->pos.x +=sp->s;
	
        	p->fen = p->perso_rightup[*i];
                (*i)++; 
                       }

                       else 
                                play_collision(s);
                     
                }
		
           else   if(event.button.button==SDL_BUTTON_LEFT&& p->pos.x<x && p->pos.y==y){
                                       if(! collision_Parfaite(map,p,pos,15,0))
                                       {

               if(p->pos.x+p->fen->w<ecran->w-p->fen->w){
		if(*i>=3)
                *i=0;
                p->pos.x +=sp->s;
        	p->fen=p->perso_right[*i];
           (*i)++; }
         
                                       }

                       else 
                                play_collision(s);
                       
                }
          else     if(event.button.button==SDL_BUTTON_LEFT&& p->pos.x>x&& p->pos.y==y){
                 
                                  if(! collision_Parfaite(map,p,pos,15,1))
{
		if(*i >= 3)
                *i = 0;
                p->pos.x -=sp->s;
	
        	p->fen=p->perso_left[*i];
                (*i)++;
              
}

                       else 
                                play_collision(s);

                }
             
         else    if(event.button.button==SDL_BUTTON_LEFT&& p->pos.y<y && p->pos.x==x){
                                       if(! collision_Parfaite(map,p,pos,15,3))
{
		if(p->pos.y+p->fen->h<ecran->h){
                if(*i >= 3)
                *i = 0;
                p->pos.y +=sp->s;

        	p->fen=p->perso_bas[*i];
                (*i)++;}
              
}

                       else 
                                play_collision(s);
                                

                }
          else       if(event.button.button==SDL_BUTTON_LEFT&& p->pos.x>x && p->pos.y<y){
                                       if(! collision_Parfaite(map,p,pos,15,3))
{
		if(p->pos.y+p->fen->h<ecran->h){
                if(*i > 1)
                *i = 0;
                p->pos.y +=sp->s;
                p->pos.x -=sp->s;

        	p->fen=p->perso_leftdown[*i];
                (*i)++;}
              
}

                       else 
                                play_collision(s);


                }
           else      if(event.button.button==SDL_BUTTON_LEFT&& p->pos.x<x&&p->pos.y<y){
                                       if(! collision_Parfaite(map,p,pos,15,3))
{
		if(p->pos.y+p->fen->h<ecran->h){
                if(*i > 1)
                *i = 0;
                p->pos.y +=sp->s;
                p->pos.x +=sp->s;

        	p->fen=p->perso_rightdown[*i];
                (*i)++;}
              
}

                       else 
                                play_collision(s);

                }
}    
}
/*
void free_player(player *p)
{
    //SDL_FreeSurface(p->img);
}*/

