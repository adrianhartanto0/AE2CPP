//
//  Utility.h
//  climb
//
//  Created by Ericko Hartanto on 3/31/16.
//  Copyright © 2016 adrian. All rights reserved.
//



#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#pragma once

struct RenderInfo{
    SDL_RendererFlip flip;
    SDL_Rect *srcRect;
    SDL_Rect destRect;
    double rotateAngle;
    RenderInfo(SDL_Rect* srcRect1,SDL_Rect dstRect1,double rotate,SDL_RendererFlip flip1) : srcRect(srcRect1),destRect(dstRect1), flip(flip1),rotateAngle(rotate){ }
};


namespace Utility {
    
//    SDL_Renderer *renderer;
    
    void renderToScreen(SDL_Renderer *renderer,SDL_Surface *sur, RenderInfo);
    SDL_Surface * loadImage(std::string url);
    void addToSurface(SDL_Surface *srcSurface, SDL_Surface *destSurface,int x, int y);
    
    
}
