//
//  GameStageX.h
//  Space
//
//  Created by Ericko Hartanto on 4/30/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef GameStageX_h
#define GameStageX_h

#include "PlayerManager.h"
#include "ItemManager.h"
#include "MapManager.h"
#include "PlaneManager.H"
#include "Platform.h"
#include "ScreenManager.h"
#include "Utility.h"
#include "BackgroundScroller.h"
#include <SDL2/SDL.h>

const std::string imageName1 = "bg6.png";
const std::string imageName2 = "bg7.png";

class GameStageX{
private:
    ItemManager *itemMgr;
    PlayerManager plyrMgr;
    PlaneManager *plane;
    MapManager *map;
    BackgroundScroller *bgScroller;
    ScreenManager *screen;
    
    SDL_Renderer *renderer;
    bool hasGameStarted;
    bool levelCompleted;
    
public:
    GameStageX();
    GameStageX(SDL_Renderer *);
    void update(InputManager *);
    ~GameStageX();
    bool hasLevelCompleted();
};


#endif /* GameStageX_h */
