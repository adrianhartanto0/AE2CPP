//
//  GameManager.cpp
//  climb
//
//  Created by Ericko Hartanto on 3/31/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "GameManager.h"
#include <SDL2/SDL.h>

//#include "Uti"
//#include "ItemTag.h"


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

SDL_Window *gWindow = NULL;
SDL_Surface *gSurface = NULL;


#include <iostream>

SDL_Renderer * screenRenderer;

GameManager::GameManager(){
    
    SDL_Init(SDL_INIT_VIDEO);
    gWindow = SDL_CreateWindow("Test SDL",100,100,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
    screenRenderer = SDL_CreateRenderer(gWindow, -1, 0);
    
    (this->input) = new InputManager();
    this->stg = NULL;
    this->stg1 = new GameStageX(screenRenderer);
    this->stg = new GameStage(screenRenderer);
    SDL_RenderPresent(screenRenderer);
    this->_isRunning = true;
    this->level = new SelectLevel(screenRenderer);
    
}

void GameManager::update(){
    SDL_RenderClear(screenRenderer);

    
    if(this->level->getOption() == -1){
        (this->level)->update(input);
    }else{
        int opt = this->level->getOption();
        if(opt == 1 && !(this->stg1)->hasLevelCompleted()){
            (this->stg1)->update(input);
        }else if(opt == 2 || (this->stg1)->hasLevelCompleted()){
            this->stg->update(input);
        }
    }
}


void GameManager::render(){
    SDL_RenderPresent(screenRenderer);
    (this->input)->clearKey();
     (this->input)->setClickedMouse(false);
}


void GameManager::receiveInput(){

    SDL_Event e;
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_KEYDOWN){
            if(e.key.keysym.sym == SDLK_ESCAPE){
                this->_isRunning = false;
            }else if(e.key.keysym.sym == SDLK_SPACE){
                (this->input)->setKey(SDL_GetKeyName(e.key.keysym.sym));
            }
        }
        
        if(e.type== SDL_MOUSEMOTION){
            (this->input)->setMouseX(e.motion.x);
            (this->input)->setMouseY(e.motion.y);
        }
        
        
        if(SDL_GetMouseState(NULL, NULL) &&  SDL_BUTTON(SDL_BUTTON_LEFT)){
            (this->input)->setClickedMouse(true);
        }

    }
}

bool GameManager::isGameRunning(){
    return this->_isRunning;
}

void GameManager::quit(){
    
    delete stg;
    delete input;
    
    delete stg1;
    
    stg = NULL;
    stg1 = NULL;
    
    SDL_Quit();
}
