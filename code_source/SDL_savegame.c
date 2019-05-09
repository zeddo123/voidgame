/**
* @file SDL_savegame.c
* @brief save game
* @author rayen
* @version 1.0
* @date May 8,2019

*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL_char.h"
#include "SDL_gestion.h"
#include <string.h>
#include "SDL_Game.h"
#include "SDL_scrolling.h"
#include "SDL_animation.h"
#include "SDL_collision.h"
#include "SDL_arduino.h"
#include "AI.h"
#include "ennemie.h"
#include "SDL_multiplayer.h"
#include "SDL_atack.h"
#include "minimap.h"
#include "SDL_jump.h"
#include "SDL_acceleration.h"
#include "SDL_savegame.h"
#include "SDL_CONDITION.h"



void SaveGame(hero player, int vie, int keys,  char filename[50])
{
    FILE * f = fopen(filename,"w+") ;
    fprintf(f, "%d\n",player.position.x);
    fprintf(f, "%d\n",player.position.y);
    fprintf(f, "%d\n",vie);
    fprintf(f, "%d\n",keys);
    fclose(f);
}


void LoadGame(char *ptr_in_menu, char *ptr_job, SDL_Surface *screen){
    int saved_x,saved_y,saved_vie,saved_key;
    FILE* f = fopen("savegame.txt","r");

    fscanf(f,"%d\n",&saved_x);
    fscanf(f,"%d\n",&saved_y);
    fscanf(f,"%d\n",&saved_vie);
    fscanf(f,"%d\n",&saved_key);
    fclose(f);

    // Load map and Calque Map(black and white)
    SDL_Surface *game_surface = SDL_DisplayFormat(IMG_Load("../src/design/map/map.png"));
    SDL_Surface *calque_surface = SDL_DisplayFormat(IMG_Load("../src/design/map/map_back_white.png"));

    SDL_Rect positionMouse;
    
    Uint32 oldTimeEntite = 0, oldTimeDamageVillain = 0, oldTimeDamageProjectile = 0, animationTime = 0;
    
    hero player;

    projectile villainProjectile;
    
    object key, key2;
    SDL_Event event;
    enigme firstEnigme, secondEnigme;
    
    SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    
    TTF_Font *font = NULL;
    SDL_Color fontColor = {255, 255, 255};
    
    char bufferVie[5],bufferKey[10];
    char game = 1;
    
    ennemi villain;
    health vie;
    
    int xKEY = -1, xKEY2 = -1,follow=0,wait=1,attack=0;
    keys number_key;
    int animation2=0;
    int randpoint = -1;
    
    int quit, FRAMES_PER_SECOND = 60, paused, started, startTicks , pausedTicks;
    
    if(TTF_Init() == -1){
        exit(0);
    }

    //init TTF Font
    font = TTF_OpenFont("../src/font/blue highway rg.ttf",50);

    //Init health
    vie.vie = saved_vie;
    sprintf(bufferVie, "%d", vie.vie);
    vie.font_vie = TTF_RenderText_Blended(font,bufferVie,fontColor);
    vie.position = initPosition(vie.position,50,20,vie.font_vie->w,vie.font_vie->h);
    
    //Init number keys
    number_key.keys = saved_key;
    sprintf(bufferKey, "Key : %d", number_key.keys);
    number_key.font_key = TTF_RenderText_Blended(font,bufferKey,fontColor);
    number_key.position = initPosition(number_key.position,SCREEN_WIDTH - 199,20,number_key.font_key->w,number_key.font_key->h);
    
    //init position and images
    villain = initEnnemie(villain,"../Sprites/entité secondaire/entité_sprite_demon_breath.png",5320,7427);

    villainProjectile.image = SDL_DisplayFormat(loadImage("../src/design/bazar/fire.png"));
    villainProjectile = launchProjectile(villainProjectile,villain.position,3);

    player = initHero(player,"../Sprites/Sprites Rayen/sprite_aio_half.png",saved_x,saved_y);

    key = initObject(key,"../src/design/bazar/key.png",5321,7427);

    key2 = initObject(key2,"../src/design/bazar/key.png",5000,7430);

    //Init riddle 1

    firstEnigme = fetchQuestion("enigme.q","enigme.s");
    firstEnigme.positionRiddle = initPosition(firstEnigme.positionRiddle,key.position.x,key.position.y,key.position.w,key.position.h);
    firstEnigme = loadTextForRiddle(firstEnigme);
    
    firstEnigme.Background = loadImage("../src/design/enigmes/question_box.png");
    firstEnigme.Button[0] = loadImage("../src/design/enigmes/answer_box_0.png"); //non selected
    firstEnigme.Button[1] = loadImage("../src/design/enigmes/answer_box_1.png"); //selected 
    
    firstEnigme = initPrintRiddle(firstEnigme);
    
    //Init riddle 1

    secondEnigme = createQustion();
    secondEnigme.positionRiddle = initPosition(secondEnigme.positionRiddle,key2.position.x,key2.position.y,key2.position.w,key2.position.h);
    secondEnigme = loadTextForRiddle(secondEnigme);
    
    secondEnigme.Background = loadImage("../src/design/enigmes/question_box.png");
    secondEnigme.Button[0] = firstEnigme.Button[0]; //non selected
    secondEnigme.Button[1] = firstEnigme.Button[1]; //selected  
    
    secondEnigme = initPrintRiddle(secondEnigme);
    
    //moveToMouse(&player,2260,7427);
    SDL_EnableKeyRepeat(10,15);
    
    while(game){
        //Mise en route du timer
        start(&started,&paused,&startTicks);
        if(eventHandlerArduino(&player,calque_surface) == 0)
            eventHandler(&player,&game,ptr_in_menu,ptr_job,calque_surface,camera,&positionMouse,&animationTime);

        moveToMouseDynamic(&player,positionMouse.x,positionMouse.y,calque_surface);

        //jump(&player,camera);
        
        camera = moveCamera(camera,player,game_surface); // gestion de la camera (scrolling)

        vie = gestionVie(player.position, villain.position, vie, &oldTimeDamageVillain); // gestion de points de vie
        vie = gestionVie(player.position,villainProjectile.position,vie,&oldTimeDamageProjectile);
        
        player.positionRelative = makeItRelative(player.position,camera);
        villain.positionRelative = makeItRelative(villain.position,camera);
        key.positionRelative = makeItRelative(key.position,camera);
        key2.positionRelative = makeItRelative(key2.position,camera);
        
        SDL_BlitSurface(game_surface,&camera,screen,NULL); //show background
        
        //SDL_BlitSurface(villain.image,&positionScreen,screen,&villain.positionRelative);
        
        if(key.state){
            SDL_BlitSurface(key.image,NULL,screen,&key.positionRelative);
        }

        if(key2.state){
            SDL_BlitSurface(key2.image,NULL,screen,&key2.positionRelative); 
        }
        
        /*---------------------------Launch the projectile------------------------------------------------*/
        
        if(!villainProjectile.active)
            villainProjectile = launchProjectile(villainProjectile,villain.position,3);
        
        moveProjectile(&villainProjectile);
                
        
        villainProjectile.positionRelative = makeItRelative(villainProjectile.position,camera);     

        if(villainProjectile.active)
            SDL_BlitSurface(villainProjectile.image,NULL,screen,&villainProjectile.positionRelative);

        /*---------------------------END-----------------------------------------------------------------*/

        Afficher_Minimap(screen,player.position,villain.position,key.position,key2.position);

        /*---------------------------Show moving characters------------------------------------------------*/

        transitionn(&villain,player,camera,&vie,screen,&animation2,&follow,&wait,&attack);//Show the villain
        show(&player,screen);

        /*---------------------------END-----------------------------------------------------------------*/


        if(xKEY == -1){
            xKEY = riddle(firstEnigme,player,screen);
            if(xKEY != -1){
                key.state = 0;
            }
        }
        
        if(xKEY2 == -1){
            xKEY2 = riddle(secondEnigme,player,screen);
            if(xKEY2 != -1){
                key2.state = 0;
            }
        }
        turnOnOff(xKEY,xKEY2);
        number_key = gestionKey(number_key,xKEY,xKEY2);
        

        sprintf(bufferVie, " %d", vie.vie);
        vie.font_vie = TTF_RenderText_Blended(font,bufferVie,fontColor);
        SDL_BlitSurface(vie.font_vie,NULL,screen,&vie.position);
        
        sprintf(bufferKey, "Key : %d", number_key.keys);
        number_key.font_key = TTF_RenderText_Blended(font,bufferKey,fontColor);
        SDL_BlitSurface(number_key.font_key,NULL,screen,&number_key.position);

        SDL_Flip(screen);
        
        /*---------------------------Move to next level--------------------------------------------------*/
        if(player.position.x > 5311 && player.position.x < 5511 && player.position.y > 7002 && player.position.y < 7323){
            if(number_key.keys >= 1){
                SDL_Delay(100);
                moveToMouse(&player,2089,3826);
            }
        }
        /*---------------------------END-----------------------------------------------------------------*/


        while( get_ticks(&started,&paused,&startTicks,&pausedTicks) < (1000 / FRAMES_PER_SECOND)){
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND) - get_ticks(&started, &paused, &startTicks, &pausedTicks));
        }

        condition_fin(&game,player,vie,number_key,screen);

    }
    TTF_CloseFont(font);

    SDL_FreeSurface(game_surface);
    SDL_FreeSurface(calque_surface);
    
    SDL_FreeSurface(firstEnigme.Button[0]);
    SDL_FreeSurface(firstEnigme.Button[1]);
    SDL_FreeSurface(firstEnigme.Background);
    SDL_FreeSurface(firstEnigme.Question);
    SDL_FreeSurface(firstEnigme.Answer1);
    SDL_FreeSurface(firstEnigme.Answer2);
    SDL_FreeSurface(firstEnigme.Answer3);
    SDL_FreeSurface(firstEnigme.Answer4);

    SDL_FreeSurface(secondEnigme.Background);
    SDL_FreeSurface(secondEnigme.Question);
    SDL_FreeSurface(secondEnigme.Answer1);
    SDL_FreeSurface(secondEnigme.Answer2);
    SDL_FreeSurface(secondEnigme.Answer3);
    SDL_FreeSurface(secondEnigme.Answer4);
    
    SDL_FreeSurface(vie.font_vie);

    SDL_FreeSurface(villain.image);
    SDL_FreeSurface(villainProjectile.image);

    SDL_FreeSurface(player.image);

    SDL_FreeSurface(key.image);
}
/*-----------------------END-----------------------*/
