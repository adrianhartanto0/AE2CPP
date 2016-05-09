//
//  PlaneManager.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/20/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "PlaneManager.h"

PlaneManager::PlaneManager(){

}

PlaneManager::PlaneManager(int val){
    this->type = val;
}

void PlaneManager::addPlane(MapManager *map){
    
    std::vector<ItemLocation> plane1 = map->getPlanePosition();
    std::vector<ItemLocation> hiddenPlane = map->getHiddenPlanePosition();

    
    add(plane1,false);
    add(hiddenPlane,true);

}


void PlaneManager::add(std::vector<ItemLocation> pos, bool hidden){
    
    AbstractPlane *plane;
    
    for(ItemLocation t:pos){
        if(t.getKey() == 6){
            plane = new PlaneY();
        }else{
            plane = new PlaneX();
        }
        
        SDL_Surface *img = plane->render();
        
        int x = (t.getX())*100 + 100-(img->w)/2;
        int y = (t.getY() * 100);
        
        plane->setRotateLeft(x >= 400);
        plane->setCoor(x, y);
        plane->setBulletType(this->type);
        
        
        if(hidden){
            this->hiddenPlanes.push_back(plane);
        }else{
            this->planes.push_back(plane);
            
        }
        
        
        SDL_FreeSurface(img);
    }
}



void PlaneManager::update(int y,int y2, PlayerManager *pl,ScreenManager *mgr, ItemManager i){
    
    if ( y  >  800  ){
        this->planes.clear();
    }
    
    if(y2 > 800){
        this->hiddenPlanes.clear();
    }
    
    spawnPlane(this->planes, y,pl,mgr,i);
    spawnPlane(this->hiddenPlanes,y2,pl,mgr,i);

}

void PlaneManager::spawnPlane( std::vector<AbstractPlane *> planes, int y,PlayerManager *pl,ScreenManager *mgr, ItemManager iM){
    for(AbstractPlane * &plane:planes){
        
        plane->rotate((pl->getRocket()).getX(), (pl->getRocket()).getY(), y);
        float angle = plane->getRotateLeft()?plane->getAngle():-(plane->getAngle()-10);
        mgr->addObjectToscreen(plane,angle,y,SDL_FLIP_VERTICAL);
        
        if(pl->isRocketFlying()){
            plane->shoot(y);
            if( plane->getBulletCount() > 0){
                int i =0;
                
                for(Bullet *b:*(plane->getbullets())){
                    
                    float midY = (plane->getY()+y) + (150.0 / 2.0);
                    b->calculatePath(midY,plane->getRotateLeft());
                    
                    if(pl->isInside(b->getX(), b->getY())){
                        pl->addObject(b->getTag());
                        (*(plane->getbullets())).erase( (*(plane->getbullets())).begin() + i);
                        continue;
                    }
                    
                    if(mgr->isWithinScreen(b->getX(),b->getY())){
                        (*(plane->getbullets())).erase( (*(plane->getbullets())).begin() + i);
                        continue;
                    }
                    
                    mgr->addObjectToscreen(b);
                    i++;
                }
            }
        }
    }
}


