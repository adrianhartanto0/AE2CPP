//
//  SelectLevel.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/30/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "SelectLevel.h"

SelectLevel::SelectLevel(){
    

}

bool isWithinBox(SDL_Rect rt,int mouseX,int mouseY){
    
    if( mouseX > rt.x && mouseX < (rt.x+rt.w)){
        if(mouseY > rt.y  && mouseY < (rt.y +rt.h)){
            return true;
        }
    }
    
    return false;
}

SelectLevel::SelectLevel(SDL_Renderer *renderer){
    this->render = renderer;
    this->option = -1;
    this->txt1 = {200,200,200,255};
    this->txt2 = {200,200,200,255};
    
}

void SelectLevel::update(InputManager * input){
    
    Text select = Text("Click to Select level", 30, {200,200,200,255});
    SDL_Rect rt = {40,50,select.getWidth(),select.getHeight()};
    
    Text l1 = Text("Level 1", 25,this->txt1);
    SDL_Rect rt1 = {40,130,l1.getWidth(),l1.getHeight()};

    if(isWithinBox(rt1,input->getMouseX(),input->getMouseY())){
        this->txt1 = {255,0,0,255};
        if(input->getClick()){
            this->option = 1;
        }
    }else{
        this->txt1 = {200,200,200,255};
    }
    
    Text l2 = Text("Level 2", 25,this->txt2);
    SDL_Rect rt2 = {40,170,l2.getWidth(),l2.getHeight()};
    
    if(isWithinBox(rt2,input->getMouseX(),input->getMouseY())){
        this->txt2 = {255,0,0,255};
        
        if(input->getClick()){
            this->option = 2;
        }
    }else{
        this->txt2 = {200,200,200,255};
    }
    
    
    Utility::renderToScreen(this->render,select.render(), RenderInfo(NULL,rt, 0.0, SDL_FLIP_NONE));
    Utility::renderToScreen(this->render,l1.render(), RenderInfo(NULL,rt1, 0.0, SDL_FLIP_NONE));
    Utility::renderToScreen(this->render,l2.render(), RenderInfo(NULL,rt2, 0.0, SDL_FLIP_NONE));
    
    select.removeSurface();
    l1.removeSurface();
    l2.removeSurface();

}

int SelectLevel::getOption(){
    return this->option;
}

