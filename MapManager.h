//
//  MapManager.h
//  Space
//
//  Created by Ericko Hartanto on 4/20/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef MapManager_h
#define MapManager_h

#include <vector>
#include "ItemLocation.h"
#include <map>
#include <iostream>
//#include <algorithm>
#include <fstream>

class MapManager{
private:
    std::vector<ItemLocation> planePosition;
    std::vector<ItemLocation> planeHiddenPosition;
    std::vector <ItemLocation> items;
    std::vector <ItemLocation> hiddenItems;
    std::string level;
    int currentScene;
    bool loadHidden;
    
public:
    MapManager();
    MapManager(std::string );
    std::vector<ItemLocation> getPlanePosition();
    std::vector<ItemLocation> getHiddenPlanePosition();
    std::vector <ItemLocation> getItemLocations();
    std::vector <ItemLocation> getHiddenItem();
    void load();
    bool getLoadHiddent();
    void moveContents();
    void modify(int i,int j, int val);
    
};


#endif /* MapManager_h */
