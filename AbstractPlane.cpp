//
//  AbstractPlane.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/20/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "AbstractPlane.h"

SDL_Surface * AbstractPlane::render(){
    return Utility::loadImage("image/items/"+this->planeName);
}

float AbstractPlane::getAngle(){
    return this->angle;
}

void AbstractPlane::setRotateLeft(bool isLeft){
    this->rotateLeft = isLeft;
}

bool AbstractPlane::getRotateLeft(){
    return this->rotateLeft;
}

std::vector<Bullet *> * AbstractPlane::getbullets(){
    return &this->bullets;
}

int AbstractPlane::getBulletCount(){
    return this->bulletCount;
}

int AbstractPlane::getBulletType(){
    return this->bulletType;
}
void AbstractPlane::setBulletType(int val){
    this->bulletType = val;
}
