//
//  Rocket.h
//  Space
//
//  Created by Ericko Hartanto on 4/16/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef Rocket_h
#define Rocket_h

#include <math.h>
#include "GameObject.h"
#include "AfterBurner.h"

//#include "AbstractRocket.h"

const int COLLIDER_WIDTH = 85;
const int COLLIDER_HEIGHT = 160;
const int COLLIDER_OFFSET_X = 20;
const int COLLIDER_OFFSET_Y = -10;

class Rocket:public GameObject{
private:
    bool isCruising;
    float fuelQuantity;
    float healthPoints;
    int prevX;
    int prevY;
    bool hasCollided;
    AfterBurner *burner;

public:
    Rocket();
    void move(int,int);
    SDL_Surface * render();
    int getFuel();
    int getHealth();
    void modifyHealth(int val);
    void modifyFuel(float val);
    void setCruising(bool stat);
    void revertMovement();
    bool isRocketCruising();
    bool getHasCollided();
    void setHasCollided(bool val);
    AfterBurner *getBurner();
};


#endif /* Rocket_h */
