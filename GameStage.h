//
//  MountainGameStage.h
//  climb
//
//  Created by Ericko Hartanto on 4/6/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef GameStage_h
#define GameStage_h



#include "PlayerManager.h"
#include "ItemManager.h"
#include "MapManager.h"
#include "PlaneManager.H"
#include "Platform.h"
#include "ScreenManager.h"
#include "Utility.h"
#include "BackgroundScroller.h"
#include <SDL2/SDL.h>

const std::string imageName = "space2.png";

class InputManager;

class GameStage{
//
    ItemManager *itemMgr;
    PlayerManager *plyrMgr;
    PlaneManager *plane;
    MapManager *map;
    BackgroundScroller *bgScroller;
    ScreenManager *screen;

    SDL_Renderer *renderer;
    bool hasGameStarted;   
    
public:
    GameStage();
   GameStage(SDL_Renderer *);
    void update(InputManager *);
    ~GameStage();
};

#endif /* GameStage_h */
