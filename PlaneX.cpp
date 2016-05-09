//
//  PlaneX.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/20/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#define PI 3.14159265

#include "PlaneX.h"

PlaneX::PlaneX(){
    this->planeName = "rocket3.png";
    this->isShooting = false;
    this->timeLastShot = 0.0f;
    this->distanceToRocket = 0.0f;
    this->bulletCount = 0;
}

void PlaneX::shoot(int y){
    
    if(this->distanceToRocket <= 490){

        unsigned int curTime = SDL_GetTicks() / 1000;

        if(curTime - this->timeLastShot > 1.3){
        
            float midX = this->getX() + (150.0 / 2.0);
            float midY = (this->getY()+y) + (150.0 / 2.0);
            
            Bullet *bl1 = new Bullet(midX,midY,this->bulletAngle);
            bl1->setColor(this->bulletType == 0?"green":"darkgreen");
            bl1->setSpeed(BULLET_SPEED_X);
            
            (this->bullets).push_back(bl1);
            
            this->timeLastShot = curTime;
            this->bulletCount++;
        }
    }
    
}

void PlaneX::rotate(float rocketX, float rocketY, int y){
    
    float midX = this->getX() + (150 / 2.0);
    float midY = (this->getY()+y) + (150 / 2.0);
    
    float adjacent = sqrt(pow(rocketY - midY,2));
    float hypo = sqrt(pow(midX-rocketX,2) + pow(midY-rocketY,2));
    this->distanceToRocket = hypo;
    this->bulletAngle = acosf(adjacent/hypo);
    this->angle = acosf(adjacent/hypo) * (180/PI);
}
