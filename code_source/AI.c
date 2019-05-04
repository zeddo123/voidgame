#include "AI.h"
#include <math.h>

int distance(ennemi E,hero H,SDL_Rect camera){  
	int x,y,d,a = 2;
	double c2;
	H.position.x = camera.x+H.position.x;
	H.position.y = camera.y+H.position.y;
	
	x = abs(H.position.x-E.position.x);
	y = abs(H.position.y-E.position.y);
	c2 = x*x + y*y;
	d = sqrt(c2);
	return d;
}

void transitionn(ennemi *E ,hero H ,SDL_Rect camera ,health *sc,SDL_Surface *screen, int *animation,int *follow,int *wait,int *attack){
	int d, d1 = 200, d2 = 10;
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
		case 2: 
			moveBetweenTwoRandom(E,1,5120,5320,&oldTimeEntite,&randpoint);
			*wait=1;
			break;

		case 1: 
			H.position.x=camera.x+H.position.x;
			H.position.y=camera.y+H.position.y;
	
			if (E->position.x<H.position.x){
				E->status = 1;
				E->position.x += 1;
  			}
  
  			if (E->position.x>H.position.x){
	   			E->status = 0;
	   			E->position.x -= 1;
  			}
  			if (E->position.y<H.position.y){
				E->position.y += 1;  
  			}
  			if (E->position.y>H.position.y){
	  			E->position.y -= 1;
  			}
  	
			E->positionRelative = makeItRelative(E->position,camera);
 
			break;

		/*case 3:
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
