//
//  Score.h
//  climb
//
//  Created by Ericko Hartanto on 4/12/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef Score_h
#define Score_h

#include "Text.h"
#include "GameObject.h"

class Score:public GameObject{
private:
    int score;
    Text *txt;
    SDL_Color fontColor;
    
public:
    Score();
    Score(SDL_Color clr);
    SDL_Surface *render();
    void setVal(int);
    
};


#endif /* Score_h */
