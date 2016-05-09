//
//  PlaneY.h
//  Space
//
//  Created by Ericko Hartanto on 4/20/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef PlaneY_h
#define PlaneY_h

const int BULLET_SPEED_Y = 6;

#include "AbstractPlane.h"
#include <vector>
//#include <algorithm>

class PlaneY : public AbstractPlane{
private:
    unsigned int timeLastShot;
    
public:
    PlaneY();
    void shoot(int y);
    void rotate(float rocketX,float rocketY, int y);
};


#endif /* PlaneY_h */
