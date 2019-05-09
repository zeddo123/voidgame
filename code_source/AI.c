/**
* @file AI.c
* @brief Ai libs
* @author Taher
* @version 1.0
* @date May 2,2019

*/
#include "AI.h"
#include <math.h>

int distance(ennemi E,hero H,SDL_Rect camera){  
	int x,y,d,a = 2;
	double c2;
	H.position.x = camera.x+H.position.x;
	H.position.y = camera.y+H.position.y;
	E.position.x = E.position.x+camera.x;
	E.position.y = E.position.y+camera.y;
	
	x = abs(H.position.x-E.position.x);
	y = abs(H.position.y-E.position.y);
	c2 = x*x + y*y;
	d = sqrt(c2);
	return d;
}

void moveEnnemi(ennemi *E, SDL_Rect posHero)
{
	if (posHero.x<E->position.x) 
	{
        	E->position.x -= 3; 
        	E->status = 0;
	}
		if (posHero.y<E->position.y) 
	{
        	E->position.y -= 3; 
	}
	if (posHero.x>E->position.x) 
	{
        	E->position.x += 3;
        	E->status = 1; 
	}
		if (posHero.y>E->position.y) 
	{
        	E->position.y += 3; 
	}
}

void transitionn(ennemi *E ,hero H ,SDL_Rect camera ,health *sc,SDL_Surface *screen, int *animation,int *follow,int *wait,int *attack){
	int d, d1 = 300, d2 = 10;
	Uint32 oldTimeEntite = 0;
	int randpoint = -1;
	
	d = distance(*E,H,camera);
	if((*wait == 1) && (d <= d1) && (d != d2)){
		*follow=1;
		*wait=0;
	}

	if ((*follow == 1) && (d <= d2)){
		*attack=1;
		*follow=0;
	}

	if ((*follow == 1) && (d > d1)){
		*wait=1;
		*follow=0;
	}

	if ((*attack == 1) && (d < d1) && (d2<=d)){
		*wait=1;
		*attack=0;
	}

    if(*follow == 1) {
		E->esprit=1;
	}
   
    if(*attack == 1){
    	E->esprit=2;
	}

    if(*wait == 1){
    	E->esprit = 3;
    }
	
	switch (E->esprit){
		case 3: 
			moveBetweenTwoRandom(E,1,5120,5320,&oldTimeEntite,&randpoint);
			*wait=1;
			break;

		case 1: 			
			moveEnnemi(E,H.position);
  	
			E->positionRelative = makeItRelative(E->position,camera);
 
			break;

		/*case 2:
			play_ennemi(s);
			*attack=0;
			*wait=1;
			if(sc->n_vie>0)
				sc->n_vie--;
				*animation=1;
			E->position.x+=200;
			E->position.y+=200;
			break;*/
	}
	
	if(E->status == 1){
		apply_surface(E->positionRelative.x, E->positionRelative.y, E->image, screen, &E->clipsRight[E->frame]);
	}else if(E->status == 0){
        apply_surface(E->positionRelative.x, E->positionRelative.y, E->image, screen, &E->clipsLeft[E->frame]);
    }

	if(SDL_GetTicks()- E->tempsActuel > 50){
		E->frame++;
		if(E->frame >= 19)
			E->frame = 0;
		E->tempsActuel = SDL_GetTicks();
	}
}
