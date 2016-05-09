//
//  PlaneX.h
//  Space
//
//  Created by Ericko Hartanto on 4/20/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef PlaneX_h
#define PlaneX_h

#include "AbstractPlane.h"
#include <vector>

const int BULLET_SPEED_X = 4;

class PlaneX : public AbstractPlane{
private:
    unsigned int timeLastShot;
    
public:
    PlaneX();
    void shoot(int y);
    void rotate(float rocketX,float rocketY, int y);
};


#endif /* PlaneX_h */
