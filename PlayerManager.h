//
//  PlayerManager.h
//  climb
//
//  Created by Ericko Hartanto on 4/9/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef PlayerManager_h
#define PlayerManager_h

#include "ScreenManager.h"
#include "ItemTag.h"

#include "Rocket.h"

//class InputManager;
#include "InputManager.h"

class PlayerManager{
private:
    Rocket *rc;
    int points;
    bool flicker;
    bool playerHasWon;
    
public:
    PlayerManager();
    PlayerManager(ScreenManager *mgr);
    void update(InputManager *, ScreenManager *mgr);
    bool isRocketFlying();
    bool isRocketCollided();
    bool isRocketDead();
    bool getHasPlayerWon();
    void addObject(std::string );
    bool checkCollision(SDL_Rect rt);
    Rocket getRocket();
    bool isInside(int x,int y);

};


#endif /* PlayerManager_h */
