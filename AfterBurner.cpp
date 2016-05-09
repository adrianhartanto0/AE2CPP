//
//  AfterBurner.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/22/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "AfterBurner.h"

AfterBurner::AfterBurner(){
    
}

SDL_Surface *AfterBurner::render(){
    return Utility::loadImage("image/items/burner.png");
}
