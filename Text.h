//
//  Text.h
//  climb
//
//  Created by Ericko Hartanto on 4/10/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef Text_h
#define Text_h

#include <SDL2_ttf/SDL_ttf.h>
#include <string>
#include "GameObject.h"

class Text:public GameObject{
private:
    SDL_Surface *surface;
    std::string txt;
    int size;
    SDL_Color clr;
    
public:
    Text();
    Text(std::string ,int size,SDL_Color clr);
    Text(std::string,int size);
    SDL_Surface* render();
    void clearSurface();
    int getWidth();
    int getHeight();
    SDL_Surface * render1();
    void removeSurface();
    void setColor(SDL_Color);
};

#endif /* Text_h */
