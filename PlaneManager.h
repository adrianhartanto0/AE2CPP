//
//  PlaneManager.h
//  Space
//
//  Created by Ericko Hartanto on 4/20/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef PlaneManager_h
#define PlaneManager_h

#include <SDL2/SDL.h>
#include "AbstractPlane.h"
#include "PlaneX.h"
#include "PlaneY.h"
#include "MapManager.h"
#include "PlayerManager.h"
#include "ScreenManager.h"
#include "ItemLocation.h"
#include "ItemManager.h"
#include <vector>
//#include <algorithm>

class PlaneManager{
private:
    SDL_Renderer *render;
    int type;
    std::vector<AbstractPlane *> planes;
    
    std::vector<AbstractPlane *> hiddenPlanes;
    void spawnPlane( std::vector<AbstractPlane *> ,int y,PlayerManager *pl,ScreenManager *mgr, ItemManager i);
    void add(std::vector<ItemLocation> pos,bool hidden);
    
public:
    PlaneManager();
    PlaneManager(int );
    void addPlane(MapManager *map);
    void update(int y,int y1, PlayerManager *pl,ScreenManager *mgr, ItemManager i);
    
    
};


#endif /* PlaneManager_h */
