//
//  AfterBurner.h
//  Space
//
//  Created by Ericko Hartanto on 4/22/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef AfterBurner_h
#define AfterBurner_h

#include "GameObject.h"

class AfterBurner:public GameObject{
public:
    AfterBurner();
    SDL_Surface *render();
};


#endif /* AfterBurner_h */
