//
//  Bullet.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/21/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "Bullet.h"

#define PI 3.14159265

Bullet::Bullet(){
    
}

Bullet::Bullet(int x,int y,float angle1){
    
    this->originX = x;
    this->originY = y;
    this->speed = 0;
    this->angle = angle1;
    this->distance = 60.0f;
}

void Bullet::calculatePath(float y1,bool left){
    
    float horizontalDistance = sinf(this->angle) *this->distance;
    float verticalDistance = cosf(this->angle) * this->distance;

    float x = this->originX + (left?-horizontalDistance:horizontalDistance);
    float y = y1 + verticalDistance;
        
    this->setCoor(x, y);
    this->distance+=this->speed;
    
}

SDL_Surface * Bullet::render(){
    return Utility::loadImage("image/items/"+this->name);
}

void Bullet::setSpeed(int val){
    this->speed = val;
}

void Bullet::setColor(std::string clr){
    if(clr == "blue"){
        this->tag = ItemTagConstants::BLUE_BULLET;
        this->name = "weapon3.png";
    }else if(clr == "green"){
        this->name = "weapon.png";
        this->tag = ItemTagConstants::GREEN_BULLET;
    }else if(clr == "red"){
        this->name = "bullet3.png";
        this->tag = ItemTagConstants::BLUE_BULLET;
    }else if(clr == "darkgreen"){
        this->name = "bullet4.png";
        this->tag = ItemTagConstants::GREEN_BULLET;
    }
}

