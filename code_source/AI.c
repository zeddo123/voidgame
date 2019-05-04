#include "AI.h"
#include <math.h>

int distance(ennemi E,hero H,SDL_Rect camera)
{  

	int x,y,d,a=2;
	double c2;
		H.position.x=camera.x+H.position.x;
	H.position.y=camera.y+H.position.y;
	

	x=abs(H.position.x-E.position.x);
	y=abs(H.position.y-E.position.y);
	c2=x*x+y*y;
	d=sqrt(c2);
	return d;
}

void transitionn(ennemi *E,hero H,SDL_Rect camera,SDL_Rect pos,health *sc,SDL_Surface *ecran,int *i,int *animation,int *follow,int *wait,int *attack)
{
	int d,d1,d2;
	Uint32 oldTimeEntite = 0;
	int randpoint = -1;
	d1=200;// distance entre fen w ennemie ki thebouh ywalli ytaba3
	d2=10;
	d=distance(*E,H,camera);
	//printf("dddd=%d\n",d);

if ((*wait==1)&&(d<=d1)&&(d!=d2)){
    *follow=1;
	*wait=0;
}

if ((*follow==1)&&(d<=d2)){
   *attack=1;
   *follow=0;
}

if ((*follow==1)&&(d>d1)){
	*wait=1;
	*follow=0;}

if ((*attack==1)&&(d<d1)&&(d2<=d)){
	*wait=1;
	*attack=0;}


//printf("%d",*follow);


    if(*follow==1) {
 E->esprit=1;
}
   
    if(*attack==1) {
    E->esprit=2;
}
    if(*wait==1){
    E->esprit=3;
    }
//	printf("%d\n",*wait);
//	printf("%d %d \n",c.cam.x+H.pos.x,c.cam.y+H.pos.y);
//	printf("%d %d \n",E->position.x,E->position.y);
switch (E->esprit)
{
	case 2: 
		moveBetweenTwoRandom(E,1,5120,5320,&oldTimeEntite,&randpoint);
	  *wait=1;
	break;

	case 1: 

	H.position.x=camera.x+H.position.x;
	H.position.y=camera.y+H.position.y;
//printf("ccccc");	
  if (E->position.x<H.position.x){
	   E->image=E->right[*i];
	   E->position.x+=1;
  }
  if (E->position.x>H.position.x){
	   E->image=E->left[*i];
	   E->position.x-=1;
  }
  if (E->position.y<H.position.y){
	  E->image=E->down[*i];
	  E->position.y+=1;  
  }
  if (E->position.y>H.position.y){
	  E->image=E->up[*i];
	  E->position.y-=1;
  }
  	
pos.x=E->position.x-camera.x;

pos.y=E->position.y-camera.y;
 
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
}
