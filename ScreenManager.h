//
//  ScreenManager.h
//  Space
//
//  Created by Ericko Hartanto on 4/22/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef ScreenManager_h
#define ScreenManager_h

//#include "PlayerManager.h"
#include "Score.h"
#include "GameObject.h"
#include "IndicatorBar.h"
#include "Utility.h"
#include <vector>
#include <map>
//#include <algorithm>

class ScreenManager{
private:
    int leftEdge;
    IndicatorBar *fuelbar;
    IndicatorBar *healthBar;
    Score *sc;
    std::vector<GameObject *> objects;
    int rightEdge;
    int height;
    SDL_Renderer *render;
    void load();
    bool isLoaded;
    std::vector<GameObject *> temp;
    
public:
    ScreenManager();
    ScreenManager(int left,int right,int height, SDL_Renderer*render);
    void addObjectToscreen(GameObject *,double angle = 0.0,int y = 0, SDL_RendererFlip k = SDL_FLIP_NONE);
    void modifyHealthBar(float val);
    void modfyFuelBar(float val);
    void modifyScore(int val);
    void update();
    bool isWithinScreen(int x, int y);
    bool isWithinHorizontal(int x, int x1);
    bool isWithinVerical(int y1);
    void renderBackground(SDL_Surface *, SDL_Rect);
    void addMessageToScreen(std::string ,std::string = "" );
};


#endif /* ScreenManager_h */
