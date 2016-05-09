//
//  AbstractPlane.h
//  Space
//
//  Created by Ericko Hartanto on 4/20/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef AbstractPlane_h
#define AbstractPlane_h

#include <iostream>
#include "GameObject.h"
#include "PlayerManager.h"
#include "Bullet.h"

class AbstractPlane: public GameObject{
protected:
    std::string planeName;
    int bulletType;
    bool isShooting;
    float angle;
    float rotateLeft;
    float bulletAngle;
    float distanceToRocket;
    std::vector<Bullet*> bullets;
    int bulletCount;
    
public:
    SDL_Surface *render();
    virtual void shoot(int y) = 0;
    virtual void rotate(float rocketX, float rocketY,int y) = 0;
    float getAngle();
    void setRotateLeft(bool isleft);
    void setBulletType(int val);
    int getBulletType();
    bool getRotateLeft();
    std::vector<Bullet *> * getbullets();
    int getBulletCount();
    
};

#endif /* AbstractPlane_h */
