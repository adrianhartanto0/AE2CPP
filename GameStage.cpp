//
//  GameStage.cpp
//  climb
//
//  Created by Ericko Hartanto on 4/6/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "GameStage.h"

GameStage::GameStage(){
    
}

GameStage::GameStage(SDL_Renderer * render1){
    
    renderer = render1;
    this->hasGameStarted = false;
    map = new MapManager("2");
    bgScroller = new BackgroundScroller(imageName,imageName);
    screen = new ScreenManager(0,bgScroller->getBgWidth(),bgScroller->getBgHeight(),renderer);
    this->plyrMgr = new PlayerManager(screen);
    plane = new PlaneManager(0);
    itemMgr = new ItemManager(renderer);
    itemMgr->addItems(map);
    
}

void GameStage::update(InputManager *input){
    
    bgScroller->render(screen);
    
    if((this->plyrMgr)->isRocketFlying()){
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

    if((this->plyrMgr)->isRocketFlying()){
        this->hasGameStarted = true;
    }

    int firstY = bgScroller->getFirstY();
    int secondY = bgScroller->getSecondY();
    (this->itemMgr)->update(firstY,secondY,this->plyrMgr);
    (this->plane)->update(secondY,firstY,this->plyrMgr,screen, *itemMgr);

    (this->plyrMgr)->update(input,screen);
    screen->update();

}

GameStage::~GameStage(void){
    delete this->plane;
    delete this->screen;
    delete this->map;
    delete this->bgScroller;
}







