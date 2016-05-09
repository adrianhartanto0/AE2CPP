//
//  Utility.cpp
//  climb
//
//  Created by Ericko Hartanto on 3/31/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "Utility.h"





SDL_Surface * Utility::loadImage(std::string url){
    
    SDL_Surface *imgSurface = NULL;
    int flags = IMG_INIT_PNG;
    int initted = IMG_Init(flags);
    
    if(flags == initted){
        imgSurface = IMG_Load(url.c_str());
       
        if(imgSurface  == NULL){
            printf("Load image failed %s\n",IMG_GetError());
        }
    }else{
        std::cout<<"Load Image failed";
    }
    
    return imgSurface;
}

void Utility::addToSurface(SDL_Surface *srcSurface, SDL_Surface *destSurface,int x, int y){
    
    SDL_Rect dstrect = {x,y,(*srcSurface).w,(*srcSurface).h};
    SDL_BlitSurface(srcSurface,NULL,destSurface,&dstrect);
}

void Utility::renderToScreen(SDL_Renderer *renderer,SDL_Surface *sur,RenderInfo ri){
    
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, sur);
    SDL_RenderCopyEx(renderer, tex, ri.srcRect, &ri.destRect, ri.rotateAngle, NULL, ri.flip);
    SDL_DestroyTexture(tex);
    
}

//void Utility::setRenderer(SDL_Renderer *render){
//    renderer = render;
//}
