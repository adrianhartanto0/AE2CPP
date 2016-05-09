//
//  GameObject.cpp
//  climb
//
//  Created by Ericko Hartanto on 4/7/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "GameObject.h"



float GameObject::getX(){
    return this->x;
}

float GameObject::getY(){
    return this->y;
}


void GameObject::setCoor(float x, float y){
    this->x =x;
    this->y = y;
}

std::string GameObject::getTag(){
    return this->tag;
}

void GameObject::setTag(std::string name){
    this->tag = name;
}




