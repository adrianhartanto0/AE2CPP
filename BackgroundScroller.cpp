//
//  BackgroundScroller.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/27/16.
//  Copyright © 2016 adrian. All rights reserved.
//


const int loadHiddenPoint = -740;
#include "BackgroundScroller.h"

BackgroundScroller::BackgroundScroller(){

    
}

BackgroundScroller::BackgroundScroller(std::string name, std::string name1){
    this->scrollQuantity = 0;
    this->revert = false;
    this->numberOfLevel = 0;
    
    this->name = name;
    this->name1 = name1;

    
    SDL_Surface *bg =  Utility::loadImage("image/bg/" + name);
    this->bgHeight = bg->h;
    this->bgWidth = bg->w;
    SDL_FreeSurface(bg);
    
    this->firstY = 0;
    this->secondY = 0;
}

void BackgroundScroller::update(){
    
    if(this->numberOfLevel != 7){

        this->scrollQuantity+=4;
        
        if(this->firstY > 800){
            this->revert = true;
            this->scrollQuantity = 0;
            this->numberOfLevel++;
        }
        
        if(this->secondY > 800){
            this->revert = false;
            this->scrollQuantity = 0;
            this->numberOfLevel++;
        }
    }
}

void BackgroundScroller::render(ScreenManager *screen){
    
    this->firstY = this->revert?this->scrollQuantity-this->bgHeight:this->scrollQuantity;
    this->secondY = this->revert?this->scrollQuantity:this->scrollQuantity-this->bgHeight;
    
    if(this->numberOfLevel == 1){
        this->name = this->name1;
    }
    
    SDL_Surface *bg1 = Utility::loadImage("image/bg/"+this->name);
    SDL_Surface *bg2 = Utility::loadImage("image/bg/"+this->name1);
    
    screen->renderBackground(bg1, {0,this->firstY, 800,800});
    screen->renderBackground(bg2, {0,this->secondY,800,800});
 
    SDL_FreeSurface(bg1);
    SDL_FreeSurface(bg2);
}

bool BackgroundScroller::isLoadPoint(){
    return (this->scrollQuantity - this->bgHeight == loadHiddenPoint);
}

int BackgroundScroller::getFirstY(){
    return this->firstY;
}

int BackgroundScroller::getSecondY(){
    return this->secondY;
}

int BackgroundScroller::getBgWidth(){
    return this->bgWidth;
}

int BackgroundScroller::getBgHeight(){
    return this->bgHeight;
}
