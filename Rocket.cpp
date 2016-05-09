//
//  Rocket.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/16/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#define PI 3.14159265

//const int MAX_PARTICLE = 40;



#include "Rocket.h"

Rocket::Rocket(){
    this->setCoor(580.0, 530);
    this->fuelQuantity = 170.0;
    this->healthPoints = 200.0;
    this->isCruising = false;
    this->burner = new AfterBurner();
    this->burner->setCoor(this->x+2, this->y+140);
    this->hasCollided = false;
    this->isCruising = false;
    this->prevX = 0;
    this->prevY = 0;
}

void Rocket::move(int x,int y){
    


    
    if(this->isCruising){
        
        float distance = sqrt(pow(this->getX()-x,2) + (pow(this->getY()-y,2)));
        
            float xCoor = this->getX();
            float yCoor = this->getY();
        
            this->prevX = xCoor;
            this->prevY = yCoor;
        
            // Adopted from https://www.youtube.com/watch?v=E4T2Wq2HgZs
            // Slight adjustments have to be made in the video's code.
     
            if(this->getX() > x || (this->getX() < x - 30)){
                xCoor = this->getX() - (((this->getX() - x)/distance)*13.0f);
            }
            
            if(this->getY() > y){
                yCoor = this->getY() - (((this->getY() - y)/distance)*13.0f);
            }
        
            if(y-70 > this->getY()){
                if(x > this->getX() && x < this->getX()+176){
                    yCoor = this->getY() - (((this->getY() - y)/distance)*13.0f);
                }

            }
        
            this->setCoor(xCoor, yCoor);

    }


    this->burner->setCoor(this->x, this->y+140);
}

void Rocket::revertMovement(){
    this->setCoor(this->prevX, this->prevY);
    this->burner->setCoor(this->prevX, this->prevY+140);
}

SDL_Surface * Rocket::render(){
    
    SDL_Surface *s = Utility::loadImage("image/items/rocket5.png");
    
    return s;
}

int Rocket::getFuel(){
    return this->fuelQuantity;
}

int Rocket::getHealth(){
    return this->healthPoints;
}

void Rocket::modifyFuel(float val){
    this->fuelQuantity += val;
}

void Rocket::modifyHealth(int val){
    this->healthPoints += val;
}

void Rocket::setCruising(bool val){
    this->isCruising = val;
}

bool Rocket::isRocketCruising(){
    return this->isCruising;
}

bool Rocket::getHasCollided(){
    return this->hasCollided;
}

void Rocket::setHasCollided(bool val){
    this->hasCollided = val;
}

AfterBurner * Rocket::getBurner(){
    return this->burner;
}
