#include "SDL_collision.h"

int collisionBox(SDL_Rect a, SDL_Rect b){
	int leftSideA = a.x;
	int rightSideA = a.x + a.w;
	int topA = a.y;
	int bottomA = a.y + a.h;

	int leftSideB = b.x;
	int rightSideB = b.x + b.w;
	int topB = b.y;
	int bottomB = b.y + b.h;

	if(bottomA <= topB){
		return 0;
	}

	if(topA >= bottomB){
		return 0;
	}

	if(rightSideA <= leftSideB){
		return 0;
	}

	if(leftSideA >= rightSideB){
		return 0;
	}

	return 1;
}

double distanceSquared(int x1, int y1, int x2, int y2){
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    return deltaX*deltaX + deltaY*deltaY;
}

int collisionCxC(Circle a, Circle b){
    int totalRadiusSquared = a.r + b.r;
    totalRadiusSquared = totalRadiusSquared * totalRadiusSquared;
    if( distanceSquared( a.x, a.y, b.x, b.y ) < ( totalRadiusSquared ) )
    {
        return 1;
    }
    return 0;
}



int collisionBxC(Circle a, SDL_Rect b){
    int centreX, centreY;

    if(a.x < b.x){
        centreX = b.x;
    }else if( a.x > b.x + b.w ){
        centreX = b.x + b.w;
    }else{
        centreX = a.x;
    }

    if(a.y < b.y){
        centreY = b.y;
    }else if( a.y > b.y + b.h ){
        centreY = b.y + b.h;
    }else{
        centreY = a.y;
    }


    if( distanceSquared(a.x, a.y, centreX, centreY) < a.r * a.r ){
        //This box and the circle have collided
        return 1;
    }

    return 0;
}

SDL_Color GetPixel(SDL_Surface *surface,int x,int y){

    SDL_Color color;
    Uint32 col = 0;

    //determine position
    char* pPosition = (char*) surface->pixels;

    //offset by y
    pPosition += surface->pitch * y;

    
    //offset by x
    pPosition += (surface->format->BytesPerPixel * x);


    //copy pixel data
    memcpy(&col, pPosition, surface->format->BytesPerPixel);


    //convert color
    SDL_GetRGB(col,surface->format,&color.r,&color.g,&color.b);

    return color;
}

int collision_Parfaite(SDL_Surface *calque, SDL_Surface *perso, SDL_Rect posperso, int decalage, int direction){
	SDL_Color col;
	int c = 0;

	if(direction == 0){//Up
		col=GetPixel(calque,posperso.x+perso->w +decalage,posperso.y+(perso->h/2));

	}else if(direction == 1){//Down
		col=GetPixel(calque,posperso.x ,posperso.y+(perso->h/2)+decalage);

	}else if(direction == 2){//Rigth
		col=GetPixel(calque,posperso.x+(perso->w/2)+decalage ,posperso.y);

	}else if(direction == 3){//Left
		col=GetPixel(calque,posperso.x+(perso->w/2),posperso.y+perso->h +decalage);

	}

	if ((col.r == 0) && (col.b == 0) && (col.g == 0)){
		c = 1;
	}else if((col.r == 255) && (col.b == 0) && (col.g == 0)){
		c = 2;
	}else if((col.r==255)&&(col.b==255)&&(col.g==255)){
		c = 3;
	}
	
	return c;
}
