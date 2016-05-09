//
//  Item.cpp
//  climb
//
//  Created by Ericko Hartanto on 3/28/16.
//  Copyright © 2016 adrian. All rights reserved.
//


#include "Item.h"

SDL_Surface *Item::render(){
    return Utility::loadImage("image/items/"+this->imageName);
}

std::string Item::getTag(){
    return this->tag;
}
