#include "SDL_atack.h"

projectile launchProjectile(projectile p, SDL_Rect positionlaunch, int axe){

	p.active = 1;
	p.axe = axe;
	if (axe == 0){ //DOWN
		p.where = initPosition(p.where,positionlaunch.x,positionlaunch.y + STEP*20,p.image->w,p.image->h);
		p.position = initPosition(p.position,positionlaunch.x,positionlaunch.y,p.image->w,p.image->h);
	
	}else if(axe == 1){//UP
		p.where = initPosition(p.where,positionlaunch.x,positionlaunch.y - STEP*20,p.image->w,p.image->h);
		p.position = initPosition(p.position,positionlaunch.x,positionlaunch.y,p.image->w,p.image->h);
	
	}else if(axe == 2){//RIGHT
		p.where = initPosition(p.where,positionlaunch.x + STEP*20,positionlaunch.y,p.image->w,p.image->h);
		p.position = initPosition(p.position,positionlaunch.x,positionlaunch.y,p.image->w,p.image->h);
	
	}else{//LEFT
		p.where = initPosition(p.where,positionlaunch.x - STEP*20,positionlaunch.y,p.image->w,p.image->h);
		p.position = initPosition(p.position,positionlaunch.x,positionlaunch.y,p.image->w,p.image->h);
	}

	return p;
}

void moveProjectile(projectile *p){
	if(p->axe == 0){
		if(p->where.y > p->position.y)
			p->position.y += STEP/4;
		else
			p->active = 0;
	}else if(p->axe == 1){
		if(p->where.y < p->position.y)
			p->position.y -= STEP/4;
		else
			p->active = 0;
	}else if(p->axe == 2){
		if(p->where.x > p->position.x)
			p->position.x += STEP/4;
		else
			p->active = 0;
	}else{
		if(p->where.x < p->position.x)
			p->position.x -= STEP/4;
		else
			p->active = 0;
	}

}