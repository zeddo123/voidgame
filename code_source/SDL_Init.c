#include "SDL_Init.h"

menu initSelectMenu(){
	menu m;
	
	m.b1.image = calloc(2,sizeof(SDL_Surface*));
	m.b2.image = calloc(2,sizeof(SDL_Surface*));
	m.b3.image = calloc(2,sizeof(SDL_Surface*));

	m.b1.image[1] = loadImage(SELECT1_B_STATIC);
	m.b1.image[0] = loadImage(SELECT1_B_OVER);

	//load the setting botton
	m.b2.image[1] = loadImage(SELECT2_B_STATIC);
	m.b2.image[0] = loadImage(SELECT2_B_OVER);

	//load the quit botton
	m.b3.image[1] = loadImage(SELECT3_B_STATIC);
	m.b3.image[0] = loadImage(SELECT3_B_OVER);

	displayFormatFrame(m.b1.image,2);
	displayFormatFrame(m.b2.image,2);
	displayFormatFrame(m.b3.image,2);

	m.b1.position = initPosition(m.b1.position,150 + m.menuLogo->w/ 2 - m.b1.image[0]->w / 2,PLAY_FROM,m.b1.image[0]->w,m.b1.image[0]->h);

	m.b3.position = initPosition(m.b3.position,150 + m.menuLogo->w/ 2 - m.b3.image[0]->w / 2,QUIT_FROM,m.b3.image[0]->w,m.b3.image[0]->h);

	m.b2.position = initPosition(m.b2.position,150 + m.menuLogo->w/ 2 - m.b2.image[0]->w / 2,SET_FROM,m.b2.image[0]->w,m.b2.image[0]->h);

	m.over_b1 = 1;
	m.over_b2 = 1;
	m.over_b3 = 1;
	m.over_b4 = 1;

	m.background = NULL;
	m.background = calloc(19,sizeof(SDL_Surface*));

	if(m.background == NULL){
		fprintf(stderr, "callocError\n");
		exit(0);
	}

	loadFrames(m.background,19,SELECT_MENU);
	displayFormatFrame(m.background,19);

	return m;
}

menu initMainMenu(){
	TTF_Font *fontGen = NULL;
	SDL_Color fontColor = {255,255,255};
	menu m;
	if(TTF_Init() == -1){
		exit(0);
	}

	fontGen = TTF_OpenFont("../src/font/blue highway rg.ttf",30);
	
	m.menuLogo = loadImage(LOGO);

	m.b1.image = calloc(2,sizeof(SDL_Surface*));
	m.b2.image = calloc(2,sizeof(SDL_Surface*));
	m.b3.image = calloc(2,sizeof(SDL_Surface*));

	m.font.image = calloc(1,sizeof(SDL_Surface*));
	
	m.font.image[0] = TTF_RenderText_Blended(fontGen,"void prod .Inc : game under the MIT licence",fontColor);
	if(m.font.image[0] == NULL || fontGen == NULL){
		printf("Unable to TTF_RenderText_Solid\n");
		exit(0);
	}

	m.b1.image[1] = loadImage(PLAY_B_STATIC);
	m.b1.image[0] = loadImage(PLAY_B_OVER);

	//load the setting botton
	m.b2.image[1] = loadImage(SET_B_STATIC);
	m.b2.image[0] = loadImage(SET_B_OVER);

	//load the quit botton
	m.b3.image[1] = loadImage(QUIT_B_STATIC);
	m.b3.image[0] = loadImage(QUIT_B_OVER);

	displayFormatFrame(m.b1.image,2);
	displayFormatFrame(m.b2.image,2);
	displayFormatFrame(m.b3.image,2);

	m.menuLogoPosition = initPosition(m.menuLogoPosition,150,0,m.menuLogo->w,m.menuLogo->h);

	m.menuLogoCrop = initPosition(m.menuLogoCrop,0,40,m.menuLogo->w,m.menuLogo->h);

	m.b1.position = initPosition(m.b1.position,150 + m.menuLogo->w/ 2 - m.b1.image[0]->w / 2,PLAY_FROM,m.b1.image[0]->w,m.b1.image[0]->h);

	m.b3.position = initPosition(m.b3.position,150 + m.menuLogo->w/ 2 - m.b3.image[0]->w / 2,QUIT_FROM,m.b3.image[0]->w,m.b3.image[0]->h);

	m.b2.position = initPosition(m.b2.position,150 + m.menuLogo->w/ 2 - m.b2.image[0]->w / 2,SET_FROM,m.b2.image[0]->w,m.b2.image[0]->h);

	m.b4.position = initPosition(m.b4.position,324,837,509-324,1000-837);

	m.font.position = initPosition(m.font.position, m.b1.position.x+300, m.b3.position.y + m.b3.position.h + 70,m.font.image[0]->w,m.font.image[0]->h);

	m.over_b1 = 1;
	m.over_b2 = 1;
	m.over_b3 = 1;
	m.over_b4 = 1;

	m.background = NULL;
	m.background = calloc(19,sizeof(SDL_Surface*));

	if(m.background == NULL){
		fprintf(stderr, "callocError\n");
		exit(0);
	}

	loadFrames(m.background,19,MAIN_MENU);
	displayFormatFrame(m.background,19);

	TTF_CloseFont(fontGen);
	TTF_Quit();
	return m;
}


menu initPlayMenu(menu main){
	menu m;

	m.menuLogo = main.menuLogo;
	m.font.image = main.font.image;
	m.font.position = main.font.position;

	m.b1.image = calloc(2,sizeof(SDL_Surface*));
	m.b2.image = calloc(2,sizeof(SDL_Surface*));
	m.b3.image = calloc(2,sizeof(SDL_Surface*));
	
	//load the new game botton
	m.b1.image[1] = loadImage(NEWGAME_B_STATIC);
	m.b1.image[0] = loadImage(NEWGAME_B_OVER);

	//load the load game botton
	m.b2.image[1] = loadImage(LOADGAME_B_STATIC);
	m.b2.image[0] = loadImage(LOADGAME_B_OVER);

	//load the return botton
	m.b3.image[1] = loadImage(BACK_B_STATIC);
	m.b3.image[0] = loadImage(BACK_B_OVER);

	displayFormatFrame(m.b1.image,2);
	displayFormatFrame(m.b2.image,2);
	displayFormatFrame(m.b3.image,2);

	m.menuLogoPosition = initPosition(m.menuLogoPosition,150,0,m.menuLogo->w,m.menuLogo->h);

	m.menuLogoCrop = initPosition(m.menuLogoCrop,0,40,m.menuLogo->w,m.menuLogo->h);

	m.b1.position = initPosition(m.b1.position,150 + m.menuLogo->w/ 2 - m.b1.image[0]->w / 2,PLAY_FROM,m.b1.image[0]->w,m.b1.image[0]->h);

	m.b3.position = initPosition(m.b3.position,150 + m.menuLogo->w/ 2 - m.b3.image[0]->w / 2,QUIT_FROM,m.b3.image[0]->w,m.b3.image[0]->h);

	m.b2.position = initPosition(m.b2.position,150 + m.menuLogo->w/ 2 - m.b2.image[0]->w / 2,SET_FROM,m.b2.image[0]->w,m.b2.image[0]->h);


	m.b4.position = initPosition(m.b4.position,324,837,509-324,1000-837);

	m.over_b1 = 1;
	m.over_b2 = 1;
	m.over_b3 = 1;
	m.over_b4 = 1;

	m.background = NULL;
	m.background = calloc(7,sizeof(SDL_Surface*));

	if(m.background == NULL){
		fprintf(stderr, "callocError\n");
		exit(0);
	}

	loadFrames(m.background,7,PLAY_MENU);
	displayFormatFrame(m.background,7);

	return m;
}

menu initSettingsMenu(menu main){
	menu m;

	m.menuLogo = main.menuLogo;

	m.b1.image = calloc(2,sizeof(SDL_Surface*));
	
	//load the return botton
	m.b1.image[1] = loadImage(BACK_B_STATIC);
	m.b1.image[0] = loadImage(BACK_B_OVER);

	displayFormatFrame(m.b1.image,2);
	
	m.menuLogoPosition = initPosition(m.menuLogoPosition,150,0,m.menuLogo->w,m.menuLogo->h);

	m.menuLogoCrop = initPosition(m.menuLogoCrop,0,40,m.menuLogo->w,m.menuLogo->h);

	m.b1.position = initPosition(m.b1.position,150 + m.menuLogo->w/ 2 - m.b1.image[0]->w / 2,QUIT_FROM,m.b1.image[0]->w,m.b1.image[0]->h);

	m.over_b1 = 1;

	m.background = NULL;
	m.background = calloc(1,sizeof(SDL_Surface*));

	if(m.background == NULL){
		fprintf(stderr, "callocError\n");
		exit(0);
	}

	m.background[0] = SDL_DisplayFormat(IMG_Load("../src/design/bazar/wallhaven-553699.png"));

	return m;
}

void loadFrames(SDL_Surface *set[], int maxframes, char file_name[]){
	FILE *ptr_file = fopen(file_name,"r");

	char *string = NULL;
	string = malloc(sizeof(char)*100);

	if(string == NULL){
		printf("allocation prob\n");
		exit(0);
	}

	for(int i = 0;i < maxframes;i++){
		fscanf(ptr_file,"%s\n",string);
		set[i] = IMG_Load(string);
	}

	free(string);
}

int checkImageLoad(SDL_Surface *set[], int index, int maxIndex){
	if(index >= maxIndex){
		return 1;
	}else{
		if(set[index] != NULL){
			return checkImageLoad(set,index+1,maxIndex);
		}else{
			printf("checkImageLoad[%d] : unable to load image %s\n", index, SDL_GetError());
			return 0;
		}
	}
}

void nextFrame(int *frame, int maxframes){
	if(*frame + 1 < maxframes){
		(*frame)++;
	}else{
		(*frame) = 0;
	}
}

void displayFormatFrame(SDL_Surface *set[], int maxframes){
	if(checkImageLoad(set,0,maxframes) != 1){
		printf("DisplayFormatFrame(1) : error on loading %s",IMG_GetError());
		exit(0);
	}

	for(int i = 0;i < maxframes;i++){
		set[i] = SDL_DisplayFormat(set[i]);
	}
	if(checkImageLoad(set,0,maxframes) != 1){
		printf("DisplayFormatFrame(1) : error on loading %s",IMG_GetError());
		exit(0);
	}
}

SDL_Rect initPosition(SDL_Rect position, int x, int y, int w, int h){
	if(x != -1){
		position.x = x;
	}

	if(y != -1){
		position.y = y;
	}

	if(w != -1){
		position.w = w;
	}

	if(h != -1){
		position.h = h;
	}

	return position;
}

hero initHero(hero h, char image_name[], int x, int y){
	h.image = NULL;
	h.image = loadImage(image_name);
	set_clips(&h);
	h.position = initPosition(h.position,x,y,h.clipsRight[0].w,h.clipsRight[0].h);
	h.orientation = 0;
	h.frame = 0;
	h.status = 1;

	return h;
}

ennemi initEnnemie(ennemi e, char image_name[], int x, int y){
	e.image = NULL;
	e.image = loadImage(image_name);
	
	set_clipsEnemie(&e);
	
	e.position = initPosition(e.position,x,y,e.clipsRight[0].w,e.clipsRight[0].h);
	
	e.orientation = 0;
	e.frame = 0;
	e.status = 1;

	return e;
}

object initObject(object o, char image_name[], int x, int y){
	o.image = NULL;
	o.image = IMG_Load(image_name);
	if(o.image == NULL){
		fprintf(stderr, "%s\n",SDL_GetError());
	}
	o.state = 1;
	o.position = initPosition(o.position,x,y,o.image->w,o.image->h);

	return o;
}

enigme loadTextForRiddle(enigme e){
	TTF_Font *font = NULL;
	SDL_Color fontColor = {63, 13, 58};

	if(TTF_Init() == -1){
		exit(0);
	}
	
	font = TTF_OpenFont("../src/font/Baron Neue.otf",36);
	if(font == NULL){
		exit(1);
	}

	e.Question = TTF_RenderText_Blended(font,e.question,fontColor);
	if(e.Question == NULL){
		printf("unable to TTF_RenderText_Solid\n");
	}


	e.Answer1 = TTF_RenderText_Blended(font,e.answer1,fontColor);
	if(e.Answer1 == NULL){
		printf("unable to TTF_RenderText_Solid\n");
	}

	e.Answer2 = TTF_RenderText_Blended(font,e.answer2,fontColor);
	if(e.Answer2 == NULL){
		printf("unable to TTF_RenderText_Solid\n");
	}

	e.Answer3 = TTF_RenderText_Blended(font,e.answer3,fontColor);
	if(e.Answer3 == NULL){
		printf("unable to TTF_RenderText_Solid\n");
	}

	e.Answer4 = TTF_RenderText_Blended(font,e.answer4,fontColor);
	if(e.Answer4 == NULL){
		printf("unable to TTF_RenderText_Solid\n");
	}

	TTF_CloseFont(font);
	
	return e;
}


SDL_Surface* loadImage(char file_name[]){
	SDL_Surface *s = NULL;
	s = IMG_Load(file_name);
	if(s == NULL){
		fprintf(stderr, "loadImage : %s\n",SDL_GetError());
	}
	return s;
}

enigme initPrintRiddle(enigme e){
	int xBackground, yBackground;
	int xA1, yA1;
	int xA2, yA2;
	int xA3, yA3;
	int xA4, yA4;
	int xAnswer1, yAnswer1;
	int xAnswer2, yAnswer2;
	int xAnswer3, yAnswer3;
	int xAnswer4, yAnswer4;
	int xQuestion, yQuestion;

	xBackground = (SCREEN_WIDTH / 2) - (e.Background->w/2);
	yBackground = (SCREEN_HEIGHT / 2) - (e.Background->h/2);
	
	yA1 = (yBackground + e.Background->h) / 2;
	xA1 = xBackground + 25;
	xA2 = e.Button[0]->w + xA1 + 50;
	yA3 = yA1 + e.Button[0]->h + 25;
	xA3 = xBackground + 25;
	xA4 = e.Button[0]->w + xA3 + 50;

	xAnswer1 = xA1;
	yAnswer1 = yA1;

	xAnswer2 = xA2;
	yAnswer2 = yA1;

	xAnswer3 = xA3;
	yAnswer3 = yA3;

	xAnswer4 = xA4;
	yAnswer4 = yA3;

	xQuestion = (xBackground + e.Background->w / 2) - (e.Question->w / 2);
	yQuestion = yBackground + 20;

	e.positionButton1 = initPosition(e.positionButton1,xA1,yA1,e.Button[0]->w,e.Button[0]->h);
	e.positionButton2 = initPosition(e.positionButton2,xA2,yA1,e.Button[0]->w,e.Button[0]->h);
	e.positionButton3 = initPosition(e.positionButton3,xA3,yA3,e.Button[0]->w,e.Button[0]->h);
	e.positionButton4 = initPosition(e.positionButton2,xA4,yA3,e.Button[0]->w,e.Button[0]->h);

	e.positionBackground = initPosition(e.positionBackground,xBackground,yBackground,e.Background->w,e.Background->h);
	e.positionQuestion = initPosition(e.positionQuestion,xQuestion,yQuestion,0,0);
	e.positionAnswer1 = initPosition(e.positionAnswer1,xAnswer1,yAnswer1,0,0);
	e.positionAnswer2 = initPosition(e.positionAnswer2,xAnswer2,yAnswer2,0,0);
	e.positionAnswer3 = initPosition(e.positionAnswer3,xAnswer3,yAnswer3,0,0);
	e.positionAnswer4 = initPosition(e.positionAnswer4,xAnswer4,yAnswer4,0,0);

	return e;
}

void init_minimap(minimap *m,SDL_Surface *ecran){
	m->minimap = IMG_Load("../src/design/minimap/minimap.png");
    m->minimap=rotozoomSurface(m->minimap,0,0.025,0);
    m->posminimap.x=(ecran->w/2)-96.9;
    m->posminimap.y=(ecran->h)-205;

    m->Down=IMG_Load("../src/design/minimap/down.png");
    m->Up=IMG_Load("../src/design/minimap/up.png");
    m->Left=IMG_Load("../src/design/minimap/left.png");
    m->Right=IMG_Load("../src/design/minimap/right.png");
    m->entite=IMG_Load("../src/design/minimap/pointRouge.png");
    m->image=m->Down;
}
