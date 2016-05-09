//
//  SelectLevel.h
//  Space
//
//  Created by Ericko Hartanto on 4/30/16.
//  Copyright © 2016 adrian. All rights reserved.
//


#include <SDL2/SDL.h>

#include "InputManager.h"
#include "Text.h"

#include "Utility.h"

#ifndef SelectLevel_h
#define SelectLevel_h

class SelectLevel{
    
private:
    bool notYetChoosen;
    SDL_Renderer *render;
    SDL_Color txt1;
    int option;
    SDL_Color txt2;
    
public:
    SelectLevel();
    SelectLevel(SDL_Renderer *);
    void update(InputManager *);
    int getOption();
    
};


#endif /* SelectLevel_h */
