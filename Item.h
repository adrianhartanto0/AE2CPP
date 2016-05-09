//
//  Item.h
//  climb
//
//  Created by Ericko Hartanto on 3/29/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#pragma once

#include "GameObject.h"
#include "ItemTag.h"
#include <iostream>

class Item :public GameObject{
    
protected:
    std::string tag;
    std::string imageName;
    
public:
    SDL_Surface *render();
    std::string getTag();
};

