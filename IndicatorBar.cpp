
//
//  IndicatorBar.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/23/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "IndicatorBar.h"

IndicatorBar::IndicatorBar(){
    
}

IndicatorBar::IndicatorBar(int i, SDL_Color clr1){
    if(i == 0){
        this->tag = ItemTagConstants::FUEL_BAR;
    }else if( i == 1){
        this->tag = ItemTagConstants::HEALTH_BAR;
    }
    
    this->clr = clr1;
}

SDL_Surface *IndicatorBar::render(){

    if(this->val < 0){
        this->val = -5;
    }
    
    SDL_Surface *blood = SDL_CreateRGBSurface(0, this->val+5, 11, 32, 0, 0, 0, 1);
    SDL_FillRect(blood, NULL, SDL_MapRGB(blood->format, this->clr.r, this->clr.g, this->clr.b));
    return blood;
}

void IndicatorBar::setVal(float val1){
    this->val = val1;
}