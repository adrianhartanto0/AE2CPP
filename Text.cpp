//
//  Text.cpp
//  climb
//
//  Created by Ericko Hartanto on 4/10/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "Text.h"

Text::Text(){
    
}

Text::Text(std::string text,int size,SDL_Color fg){
    
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    
    TTF_Font *font = TTF_OpenFont("fonts/uni.otf", size);
    if(!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }
    
    this->surface = TTF_RenderText_Solid(font, text.c_str(), fg);
    TTF_CloseFont(font);
    
}

Text::Text(std::string text,int size1){
    this->txt = text;
    this->size = size1;
}


int Text::getWidth(){
    return this->surface->w;
}

int Text::getHeight(){
    return this->surface->h;
}

SDL_Surface *Text::render(){
    return this->surface;
}



void Text::removeSurface(){
    SDL_FreeSurface(this->surface);
}

void Text::setColor(SDL_Color clr1){

    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    
    TTF_Font *font = TTF_OpenFont("fonts/uni.otf", size);
    if(!font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }
    
    this->surface = TTF_RenderText_Solid(font, (this->txt).c_str(), clr1);
    TTF_CloseFont(font);
    
}



