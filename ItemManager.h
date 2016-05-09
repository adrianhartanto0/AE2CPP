//
//  ItemManager.h
//  climb
//
//  Created by Ericko Hartanto on 4/9/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef ItemManager_h
#define ItemManager_h

#include <vector>
//#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include "ItemFactory.h"
#include "PlayerManager.h"
#include "ItemLocation.h"
#include "MapManager.h"
#include <utility>

class ItemManager{
private:
    std::vector <ItemLocation> items;
    std::vector <ItemLocation> hiddentItems;
    ItemFactory factory;
    SDL_Renderer *renderer;
    int numOfDiamonds;
    bool checkCollision(int x, int y,int x2,PlayerManager );
    void parseMap(std::vector<ItemLocation> *map, PlayerManager *pl, int y);
    void add(std::vector<ItemLocation> items, bool hidden);
    
public:
    ItemManager();
    ItemManager(SDL_Renderer *);
    void update( int y,int y2,PlayerManager *pl);
    void addItems(MapManager *map);
    bool checkCollision(GameObject j, int y);
    int getNumberOfDiamonds();
    
};


#endif /* ItemManager_h */
