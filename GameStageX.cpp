//
//  GameStageX.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/30/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "GameStageX.h"

GameStageX::GameStageX(){
    
}


GameStageX::GameStageX(SDL_Renderer *render){
    renderer = render;
    this->hasGameStarted = false;
    map = new MapManager("1");
    bgScroller = new BackgroundScroller(imageName1,imageName2);
    screen = new ScreenManager(0,bgScroller->getBgWidth(),bgScroller->getBgHeight(),renderer);
    plyrMgr = PlayerManager(screen);
    plane = new PlaneManager(1);
    itemMgr = new ItemManager(renderer);
    itemMgr->addItems(map);
    this->levelCompleted = false;
}

void GameStageX::update(InputManager *input){
    
    bgScroller->render(screen);
    
    if(plyrMgr.isRocketFlying()){
        if(bgScroller->isLoadPoint()){
            map->load();
            plane->addPlane(map);
            itemMgr->addItems(map);
        }
        
        bgScroller->update();
    }
    
    if(!this->hasGameStarted){
        screen->addMessageToScreen("Press 'Space' to start");
        Platform pl1 = Platform(9, "planet.png");
        pl1.render(0, 703, renderer);
    }
    
    if(plyrMgr.isRocketFlying()){
        this->hasGameStarted = true;
    }
    
    if(plyrMgr.getHasPlayerWon()){
        this->levelCompleted = true;
        SDL_Delay(2000);
    }
    
    int firstY = bgScroller->getFirstY();
    int secondY = bgScroller->getSecondY();
    
    itemMgr->update(firstY,secondY,&plyrMgr);
    plane->update(secondY,firstY,&plyrMgr,screen, *itemMgr);
    
    plyrMgr.update(input,screen);
    screen->update();
}

bool GameStageX::hasLevelCompleted(){
    return this->levelCompleted;
}

GameStageX::~GameStageX(void){
    delete this->plane;
    delete this->screen;
    delete this->map;
    delete this->bgScroller;
}

