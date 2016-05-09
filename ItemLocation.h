//
//  ItemLocation.h
//  Space
//
//  Created by Ericko Hartanto on 4/23/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef ItemLocation_h
#define ItemLocation_h

class ItemLocation{
private:
    int x;
    int y;
    int key;
public:
    ItemLocation();
    ItemLocation(int x,int y,int key);
    int getX();
    int getY();
    int getKey();
};


#endif /* ItemLocation_h */
