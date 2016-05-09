//
//  ItemLocation.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/23/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "ItemLocation.h"

ItemLocation::ItemLocation(int x1,int y1,int key1){
    this->x = x1;
    this->y = y1;
    this->key = key1;
}
int ItemLocation::getX(){
    return this->x;
}

int ItemLocation::getY(){
    return this->y;
}

int ItemLocation::getKey(){
    return this->key;
}
