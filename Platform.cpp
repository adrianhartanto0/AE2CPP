//
//  Platform.cpp
//  climb
//
//  Created by Ericko Hartanto on 4/14/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "Platform.h"

Platform::Platform(){
    
}


void Platform::render(int x,int y, SDL_Renderer *renderer){
    

    int offset = 0;
   
    for(int i =0; i < this->size+2;i++){
        
        SDL_Surface *firstTile = Utility::loadImage(this->tileName);
        
        SDL_Rect rect = {x+offset,y,firstTile->w,firstTile->h};
        SDL_Texture *tex1 = SDL_CreateTextureFromSurface(renderer, firstTile);
        SDL_RenderCopyEx(renderer, tex1, NULL, &rect, 0.0, NULL, SDL_FLIP_NONE);
        offset += firstTile->w;
        SDL_FreeSurface(firstTile);
        SDL_DestroyTexture(tex1);
    }
    
    offset = 0;
    

    for(int i =0; i < this->size+2;i++){
        
        SDL_Surface * left = Utility::loadImage("image/items/planetCenter.png");
        SDL_Rect rect = {x+offset,y+(left->h)-10,left->w,left->h};
        SDL_Texture *tex1 = SDL_CreateTextureFromSurface(renderer, left);
        SDL_RenderCopyEx(renderer, tex1, NULL, &rect, 0.0, NULL, SDL_FLIP_NONE);
        offset += left->w;
        SDL_FreeSurface(left);
        SDL_DestroyTexture(tex1);
    }
}

Platform::Platform(int size, std::string begin){
    
    this->tileName = "image/items/" + begin;
    this->size = size;
}

