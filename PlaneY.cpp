//
//  PlaneY.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/20/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#define PI 3.14159265

#include "PlaneY.h"

PlaneY::PlaneY(){
    this->planeName = "rocket6.png";
    this->timeLastShot = 0.0f;
    this->distanceToRocket = 0.0f;
    this->bulletCount = 0;
}

void PlaneY::shoot(int y){
    
    if(this->distanceToRocket <= 550){
        
        unsigned int curTime = SDL_GetTicks() / 1000;
        
        if(curTime - this->timeLastShot > 0.3){
            
            float midX = this->getX() + (150.0 / 2.0);
            float midY = (this->getY()+y) + (150.0 / 2.0);
            
            Bullet *bl1 = new Bullet(midX,midY,this->bulletAngle);
            bl1->setColor(this->bulletType == 0?"blue":"red");
            bl1->setSpeed(BULLET_SPEED_Y);
            
            (this->bullets).push_back(bl1);
            
            this->timeLastShot = curTime;
            this->bulletCount++;
        }
    }
}

void PlaneY::rotate(float rocketX, float rocketY, int y){
    
    float midX = this->getX() + (150 / 2.0);
    float midY = (this->getY()+y) + (150 / 2.0);
    
    float opposite = sqrt(pow(midY - rocketY,2));
    float hypo =sqrt(pow(midX-rocketX,2) + pow(midY-rocketY,2));
    this->distanceToRocket = hypo;
    
    if(rocketY < midY){
    
        this->bulletAngle = sinf(opposite/hypo) + (PI/2);
        this->angle = (sinf(opposite/hypo) *(180/PI))+90;
    }else{
        this->bulletAngle = acosf(opposite/hypo);
        this->angle = acosf(opposite/hypo) * (180/PI);
    }
}