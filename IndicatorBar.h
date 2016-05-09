//
//  IndicatorBar.h
//  Space
//
//  Created by Ericko Hartanto on 4/23/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef IndicatorBar_h
#define IndicatorBar_h

#include "GameObject.h"

class IndicatorBar:public GameObject{
    
private:
    SDL_Color clr;
    float val;
    
public:
    IndicatorBar();
    IndicatorBar(int x, SDL_Color clr);
    SDL_Surface *render();
    void setVal(float val);
};


#endif /* IndicatorBar_h */
