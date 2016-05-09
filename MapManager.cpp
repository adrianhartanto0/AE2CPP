//
//  MapManager.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/20/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "MapManager.h"

//const int STONE_RED = 3;
//const int STONE_GREY = 4;
//const int GREEN_DIAMOND = 2;
//const int FUEL_TANK = 1;
const int PLANE_POSITION = 5;
const int PLANE_POSITION1 = 6;

std::string fileName[8] = {"map1.txt","map2.txt","map3.txt","map4.txt","map5.txt","map6.txt","map7.txt","map8.txt"};

MapManager::MapManager(){

}

MapManager::MapManager(std::string x){
    this->level = x;
    this->currentScene = 0;
    this->loadHidden = false;
    this->load();
}

void MapManager::load(){
    
    char c;
    
    int counterX = 0;
    int counterY = 0;
    this->planePosition.clear();
    this->planeHiddenPosition.clear();
    this->items.clear();
    this->hiddenItems.clear();
    
    std::vector<int> num;
    
    std::ifstream myfile("map/"+this->level+"/"+fileName[this->currentScene]);
    if(myfile.is_open()){
        while(myfile.get(c)){
            if(c== '\n'){
                continue;
            }else{
                int val = c -48;
                 ItemLocation l =ItemLocation(counterX, counterY, val);
                if(val == PLANE_POSITION || val == PLANE_POSITION1){
                  
                    if(((this->currentScene+1) % 2) ==  0){
                       
                        (this->planePosition).push_back(l);
                    }else{
                        this->planeHiddenPosition.push_back(l);
                    }
                    
                }else if(val != 0){
                    if(((this->currentScene+1) % 2) == 0){
                        this->hiddenItems.push_back(l);
                    }else{
                        this->items.push_back(l);
                    }
                }
                
                
                if(counterX == 7){
                
                    counterY++;
                    counterX = 0;
                    continue;
                }
                counterX++;
            }
        }
    }
    
    myfile.close();
    this->currentScene++;
    
}

std::vector<ItemLocation> MapManager::getHiddenItem(){
    return this->hiddenItems;
}

bool MapManager::getLoadHiddent(){
    return this->loadHidden;
}

std::vector<ItemLocation> MapManager::getItemLocations(){
    return this->items;
}

std::vector<ItemLocation> MapManager::getPlanePosition(){
    return this->planePosition;
}

std::vector<ItemLocation> MapManager::getHiddenPlanePosition(){
    return this->planeHiddenPosition;
}

//void MapManager::modify(int i, int j,  int val){
//    this->items[i][j] = val;
//}


