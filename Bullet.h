//
//  Bullet.h
//  Space
//
//  Created by Ericko Hartanto on 4/21/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef Bullet_h
#define Bullet_h

#include "GameObject.h"

class Bullet:public GameObject{
private:
    std::string name;
    float angle;
    int originX;
    int originY;
    float distance;
    int speed;
    
public:
    Bullet();
    Bullet(int x,int y ,float angle);
    void calculatePath(float y, bool left);
    SDL_Surface *render();
    void setSpeed(int );
    void setColor(std::string);
};


#endif /* Bullet_h */
