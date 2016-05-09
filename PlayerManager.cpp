//
//  PlayerManager.cpp
//  climb
//
//  Created by Ericko Hartanto on 4/9/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "PlayerManager.h"

//const int JUMP_KEY = 4;
//const int MOVE_LEFT_KEY = 0;
//const int MOVE_RIGHT_KEY = 1;

bool move = false;
double collisionTime = 0;

PlayerManager::PlayerManager(){
    
}

PlayerManager::PlayerManager(ScreenManager *mgr){
    
    this->rc = new Rocket();
    
    this->points = 0;
    this->flicker = false;
    this->playerHasWon = false;   
    mgr->modifyHealthBar(rc->getHealth());
    mgr->modfyFuelBar(rc->getFuel());
    mgr->modifyScore(this->points);
    mgr->addObjectToscreen(this->rc);
   
}

void PlayerManager::update(InputManager *input, ScreenManager *mgr){

    
     //mgr->addObjectToscreen(this->rc);
    
    if(!this->playerHasWon){
        if(input->getKey() != NULL){
            if(strcmp(input->getKey(), "Space") == 0){
                (this->rc)->setCruising(true);
            }
        }

        (this->rc)->move(input->getMouseX(),input->getMouseY());

        if(!this->flicker) {
            mgr->addObjectToscreen(rc);
             if((this->rc)->isRocketCruising()){
                 mgr->addObjectToscreen((this->rc)->getBurner());
             }
         }
        
         if((this->rc)->isRocketCruising()){
            (this->rc)->modifyFuel(-0.3);
             if(mgr->isWithinHorizontal((this->rc)->getX(),(this->rc)->getX()+130) || mgr->isWithinVerical(this->rc->getY()+ 240)){
                 (this->rc)->revertMovement();
             }
         }
        
        
         if((this->rc)->getFuel() < -4){
            mgr->addMessageToScreen("Better luck next time","You ran out of fuel!!");
            rc->setCruising(false);
         }
        
         if((this->rc)->getHealth() < -4){
            mgr->addMessageToScreen("Better luck next time","You ran out of health points!!");
            this->rc->setCruising(false);
         }
    
    }else{
        mgr->addObjectToscreen(rc);
        mgr->addMessageToScreen("Congratulations!","You've won!!");
    }
    

    

    this->flicker = false;

    mgr->modfyFuelBar(this->rc->getFuel());
    mgr->modifyHealthBar((this->rc)->getHealth());
    mgr->modifyScore(this->points);
}

Rocket PlayerManager::getRocket(){
    return *(this->rc);
}


bool PlayerManager::isRocketFlying(){
    return rc->isRocketCruising();
}

bool PlayerManager::isRocketCollided(){
    return rc->getHasCollided();
}

bool PlayerManager::isRocketDead(){
    return rc->getFuel() <= 0;
}


bool PlayerManager::checkCollision(SDL_Rect rt){
    
    float m = (this->rc)->getX() + COLLIDER_OFFSET_X;
    float j = (this->rc)->getY() + COLLIDER_OFFSET_Y;
    
    bool hasCollided = false;
    
    if(((m > rt.x) && (m+COLLIDER_WIDTH < rt.x+rt.w))){
        if(j - (rt.y+rt.h) < 5){
            hasCollided = true;
        }
    }
    
    if(((m > rt.x) && (m+COLLIDER_WIDTH > rt.x+rt.w))){
        if(m < rt.x+rt.w){
            if(j - (rt.y+rt.h) < 2 && j - (rt.y+rt.h) > -35 ){
                hasCollided = true;
            }else if(j < rt.y && j+COLLIDER_HEIGHT >  rt.y+rt.h){
                 hasCollided = true;
            }
        }
    }
    
    if((m < rt.x) && (m+COLLIDER_WIDTH > rt.x && m+COLLIDER_WIDTH < rt.x+rt.w)){
        if(j > rt.y && j < rt.y+rt.h){
            hasCollided = true;
        }
        
    }
    
    if((m < rt.x) && (m+COLLIDER_WIDTH > rt.x && m+COLLIDER_WIDTH > rt.x+rt.w)){
        if(j > rt.y && j < rt.y+rt.h){
            hasCollided = true;
        }
        
    }
    
    return hasCollided;
}


void PlayerManager::addObject(std::string name){
    
    if(name == ItemTagConstants::GREEN_DIAMOND){
        this->points+=10;
    }if(name == ItemTagConstants::FUEL_TANK){
        rc->modifyFuel(65);
    }else if(name == ItemTagConstants::GREEN_BULLET){
        this->rc->modifyHealth(-15);
        this->flicker = true;
    }else if(name == ItemTagConstants::BLUE_BULLET){
        this->rc->modifyHealth(-25);
        this->flicker = true;
    }else if(name == ItemTagConstants::RED_STONE){

        
    }else if(name == ItemTagConstants::FINAL_FLAG){
        this->playerHasWon = true;
        this->rc->setCruising(false);
    }
}

// Idea and code adopted from
// http://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/

float area(int x1,int y1,int x2,int y2,int x3,int y3){
    
    return abs((x1*(y2-y3) + x2*(y3-y1)+x3 *(y1-y2))/2);
}

bool PlayerManager::isInside(int x,int y){
    
    int leftEdgeX = rc->getX();
    int leftEdgeY = rc->getY()+180;
    
    int rightEdgeX = rc->getX() +120;
    int rightEdgeY = rc->getY() + 180;
    
    int midX = rc->getX() + (120 / 2);
    
    float A = area(midX-10, rc->getY()+60, leftEdgeX, leftEdgeY, rightEdgeX, rightEdgeY);
    float A1 = area(x,y,leftEdgeX,leftEdgeY,rightEdgeX,rightEdgeY);
    float A2 = area(midX-10,rc->getY()+60,x,y,rightEdgeX,rightEdgeY);
    float A3 = area(midX-10,rc->getY()+60,leftEdgeX,leftEdgeY,x,y);
    
    if(A == A1+A3+A2){
        return true;
    }
    
    return false;
}

bool PlayerManager::getHasPlayerWon(){
    return this->playerHasWon;
}

