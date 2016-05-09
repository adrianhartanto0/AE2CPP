//
//  Platform.h
//  climb
//
//  Created by Ericko Hartanto on 4/14/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef Platform_h
#define Platform_h

#include <math.h>
#include <SDL2/SDL.h>
#include <vector>
#include "Utility.h"
#include <algorithm>
#include <iostream>

class Platform{

private:
    int sector;
    int size;
    std::string tileName;
    
    
public:
    Platform();
    Platform(int ,std::string start);
    void render(int ,int, SDL_Renderer *);
};


#endif /* Platform_h */
