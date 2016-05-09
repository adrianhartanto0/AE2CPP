//
//  ItemManager.cpp
//  climb
//
//  Created by Ericko Hartanto on 4/9/16.
//  Copyright © 2016 adrian. All rights reserved.
//

// if map loaded is:




#include "ItemManager.h"

const int STONE_RED = 3;
const int STONE_GREY = 4;
const int GREEN_DIAMOND = 2;
const int FUEL_TANK = 1;
const int FINAL_FLAG = 7;

void ItemManager::addItems(MapManager *map){
    
    std::vector<ItemLocation> items = map->getItemLocations();
    std::vector<ItemLocation> hidden = map->getHiddenItem();
    
    add(items,false);
    add(hidden,true);
}

void ItemManager::add(std::vector<ItemLocation> map, bool hidden){
    
    for(ItemLocation x : map){
        
        if(x.getKey() == GREEN_DIAMOND){
            this->numOfDiamonds++;
        }
        
        if(hidden){
            this->hiddentItems.push_back(x);
        }else{
          this->items.push_back(x);
            
        }
    }
}


void ItemManager::update(int y,int y2, PlayerManager *pl){
    
    if(y > 800){
        this->items.clear();
    }

    if(y2 >= 800){
        this->hiddentItems.clear();
    }
    
    parseMap(&this->items,pl, y);
    parseMap(&this->hiddentItems, pl, y2);
}

void ItemManager::parseMap(std::vector<ItemLocation> *map, PlayerManager * pl, int y){
    
    Item t;
    int i = 0;
    
    for(ItemLocation x : (*map)){
        switch (x.getKey()) {
            case STONE_GREY:
                t = factory.getItem(ItemTagConstants::GREY_STONE);
                break;
            case STONE_RED:
                t = factory.getItem(ItemTagConstants::RED_STONE);
                break;
            case GREEN_DIAMOND:
                t = factory.getItem(ItemTagConstants::GREEN_DIAMOND);
                break;
            case FINAL_FLAG:
                t= factory.getItem(ItemTagConstants::FINAL_FLAG);
                break;
            case FUEL_TANK:
                t = factory.getItem(ItemTagConstants::FUEL_TANK);
                break;
            default:
                break;
        }
        
        SDL_Surface *img = t.render();
        int x1 = (x.getX()) * 100;
        int y1 =(x.getY()*100)+y;
        SDL_Rect rect = {x1,y1,img->w,img->h};
        
        
        if(pl->checkCollision(rect)){
            pl->addObject(t.getTag());
            if(t.getTag() == ItemTagConstants::GREEN_DIAMOND || t.getTag() == ItemTagConstants::FUEL_TANK || t.getTag() == ItemTagConstants::FINAL_FLAG){
                    map->erase(map->begin() + i);
            }
        }
        
        RenderInfo g = RenderInfo(NULL, rect, 0.0, SDL_FLIP_NONE);
        Utility::renderToScreen(this->renderer, img, g);
        SDL_FreeSurface(img);
        
        i++;
    }
}

bool  ItemManager::checkCollision(GameObject b, int y){
    
//    for(ItemLocation t : this->hiddentItems ){
//        if(t.getKey() == STONE_RED || t.getKey() == STONE_GREY){
//            int tX = (t.getX())*100;
//            int tY = t.getY() * 100;
//    
//            if(b.getX() > tX && (b.getX() + 60 < tX+101)){
//                
//                
//                if(b.getX() > tX && (b.getX() + 60 < tX+101)){
//                    
//                    
//                    if(b.getY() < (tY+y)){
//                        if ((((tY + y) - (b.getY() + 60)) < -19) && (((tY + y) - (b.getY() + 60)) > -24)) {
//                            return true;
//                        }
//                    }
//                    
//                    if(b.getY() > (tY+y+84)){
//                        if (((b.getY() - (tY + y  +84 ) ) < -10) &&  ((b.getY() - (tY + y  +84 ) ) > -16)  ) {
//                            return true;
//                        }
//                    }
//                }
//                
//                if(b.getX() > tX && (b.getX() + 60 > tX+101)){
//                    
//                    
//                    if(b.getY() < (tY+y)){
//                        if ((((tY + y) - (b.getY() + 60)) < -19) && (((tY + y) - (b.getY() + 60)) > -24)) {
//                            return true;
//                        }
//                    }
//                    
//                    if(b.getY() > (tY+y+84)){
//                        if (((b.getY() - (tY + y  +84 ) ) < -19) &&  ((b.getY() - (tY + y  +84 ) ) > -24)  ) {
//                            return true;
//                        }
//                    }
//                }
//                
//
//            }
//        }
//    }
    
    for(ItemLocation t: this->items){
        
        
        
        if(t.getKey() == STONE_RED || t.getKey() == STONE_GREY){
            int tX = (t.getX())*100;
            int tY = (t.getY() * 100) + y;
            
            if(b.getX() > tX && (b.getX() + 60 < tX+101)){
                
                
                if(b.getY() < (tY+y)){
                    if ((((tY) - (b.getY() + 60)) < -19) && (((tY)- (b.getY() + 60)) > -24)) {
                        return true;
                    }
                }
                
                if(b.getY() > (tY+y+84)){
                    if (((b.getY() - (tY  +84 ) ) < -10) &&  ((b.getY() - (tY +84 ) ) > -16)  ) {
                        return true;
                    }
                }
            }
            
            if(b.getX() > tX && (b.getX() + 60 > tX+101)){
                
                
                if(b.getY() > (tY) && (b.getY() + 60) < (tY+84) ){
                    if((b.getX() - (tX + 101) < -10) && (b.getX() - (tX + 101) > -20)){
                        return true;
                    }
                }
                
                if(b.getY() > (tY) && (b.getY() > (tY+84) )){
                    if((b.getX() - (tX + 101) < -20 ) && (b.getX() - (tX + 101) > -80)){
                        return true;
                    }
                }

            }
            
            
            
            
            
            
            
        }
    }
    
    return false;
}



ItemManager::ItemManager(){
    
}

ItemManager::ItemManager(SDL_Renderer *render){

    this->factory = ItemFactory();
    this->renderer = render;
    
}






