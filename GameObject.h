//
//  GameObject.h
//  climb
//
//  Created by Ericko Hartanto on 4/7/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef GameObject_h
#define GameObject_h

#include "Utility.h"
#include "ItemTag.h"
#include <SDL2/SDL.h>

class GameObject{
    
protected:
    std::string tag;
    float x;
    float y;

public:
    void setCoor(float,float);
    float getX();
    float getY();
    std::string getTag();
    void setTag(std::string );
    virtual SDL_Surface *render() = 0;
};


#endif /* GameObject_h */
