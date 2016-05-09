//
//  ScreenManager.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/22/16.
//  Copyright © 2016 adrian. All rights reserved.
///Users/erickohartanto/Desktop/iphone/Space/Space/ScreenManager.cpp

#include "ScreenManager.h"


ScreenManager::ScreenManager(){
    
}

ScreenManager::ScreenManager(int left,int right,int height1, SDL_Renderer *render1){
    this->leftEdge = left;
    this->rightEdge = right;
    this->render = render1;
    this->height = height1;
    load();
}

void ScreenManager::update(){
    
    for(GameObject *t:this->objects){
        
        SDL_Surface * sur = t->render();
        Utility::renderToScreen(render, sur, RenderInfo(NULL, {int(t->getX()),int(t->getY()),sur->w,sur->h},0.0, SDL_FLIP_NONE));
        
        if(t->getTag() == ItemTagConstants::HEALTH_BAR){
            Text txt = Text("Health", 20, {255,255,255,255});
            Utility::renderToScreen(render, txt.render(), RenderInfo(NULL, {30,36,txt.getWidth(),txt.getHeight()},0.0, SDL_FLIP_NONE));
            txt.removeSurface();
        }else if(t->getTag() == ItemTagConstants::FUEL_BAR){
            Text txt1 = Text("Fuel", 20, {255,255,255,255});
            Utility::renderToScreen(render, txt1.render(), RenderInfo(NULL, {30,85,txt1.getWidth(),txt1.getHeight()},0.0, SDL_FLIP_NONE));
             txt1.removeSurface();
        }else if(t->getTag() == ItemTagConstants::SECONDARY_MESSAGE || t->getTag() == ItemTagConstants::PRIMARY_MESSAGE){
            auto i = std::find(this->objects.begin(), this->objects.end(), t);
            this->objects.erase(i);
        }
        SDL_FreeSurface(sur);
    }

}



void ScreenManager::load(){
    this->fuelbar = new IndicatorBar(0,{219,177,82,255});
    this->fuelbar->setCoor(30, 110);
    this->objects.push_back(this->fuelbar);
    
    this->healthBar = new IndicatorBar(1,{255,0,0,255});
    this->healthBar->setCoor(30, 60);
    this->objects.push_back(this->healthBar);
    
    
    this->sc = new Score({255,255,255,255});
    this->sc->setCoor(640, 30);
    this->objects.push_back(this->sc);
}

void ScreenManager::modifyScore(int val){
    
    this->sc->setVal(val);
    
}

void ScreenManager::modfyFuelBar(float val){
    
    this->fuelbar->setVal(val);
    
}

void ScreenManager::modifyHealthBar(float val){

    this->healthBar->setVal(val);
    
}

void ScreenManager::addObjectToscreen(GameObject *obj, double angle,int y,SDL_RendererFlip flip){
    
    
    SDL_Surface * sur = obj->render();
    
    
    if(sur != NULL){
        Utility::renderToScreen(render, sur, RenderInfo(NULL, {int(obj->getX()),int(obj->getY())+y,sur->w,sur->h},angle, flip));
    }
    
    SDL_FreeSurface(sur);
}

void ScreenManager::addMessageToScreen(std::string text, std::string text1){
    
    Text *txt = new Text(text, 30, {255,255,255,255});
    txt->setTag(ItemTagConstants::PRIMARY_MESSAGE);
    
    int midX = (rightEdge / 2) - (txt->getWidth() / 2);
    
    txt->setCoor(midX,300);
    this->objects.push_back(txt);
    
    if(!text1.empty()){
        Text *txt1 = new Text(text1,25,{255,255,255,255});
        txt1->setTag(ItemTagConstants::SECONDARY_MESSAGE);
        midX = (rightEdge / 2) - (txt1->getWidth() / 2);
        txt1->setCoor(midX, 340);
        this->objects.push_back(txt1);
    }

}

void ScreenManager::renderBackground(SDL_Surface *img, SDL_Rect rect){
    Utility::renderToScreen(this->render, img, RenderInfo(NULL,rect,0.0,SDL_FLIP_NONE));

}

bool ScreenManager::isWithinScreen(int x,int y){
    if(x < 0 || y < 0){
        return true;
    }
    
    if(x > 800 || y > 800){
        return true;
    }
    return false;
}

bool ScreenManager::isWithinHorizontal(int x,int x1){
    
    return (x1 > this->rightEdge || x < this->leftEdge);
    
}

bool ScreenManager::isWithinVerical(int y){
    return (y > this->height);
}

