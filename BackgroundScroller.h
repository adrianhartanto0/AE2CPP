//
//  BackgroundScroller.h
//  Space
//
//  Created by Ericko Hartanto on 4/27/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef BackgroundScroller_h
#define BackgroundScroller_h

#include "ScreenManager.h"

class BackgroundScroller{
private:
    int scrollQuantity;
    bool revert;
    int numberOfLevel;
    int bgHeight;
    int bgWidth;
    int firstY;
    int secondY;
    std::string name;
    std::string name1;
    
public:
    BackgroundScroller();
    BackgroundScroller(std::string ,std::string pic = NULL);
    void update();
    void render(ScreenManager *screen);
    bool isLoadPoint();
    int getBgWidth();
    int getBgHeight();
    int getFirstY();
    int getSecondY();
};


#endif /* BackgroundScroller_h */
