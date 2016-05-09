//
//  ItemFactory.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/17/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "ItemFactory.h"


Item ItemFactory::getItem(std::string name){
    Item t;
    if(name == ItemTagConstants::RED_STONE){
        t = RedStoneItem();
    }else if(name == ItemTagConstants::GREY_STONE){
        t = GreyStoneItem();
    }else if(name == ItemTagConstants::GREEN_DIAMOND){
        t = GreenDiamondItem();
    }else if(name == ItemTagConstants::FUEL_TANK){
        t = FuelTankItem();
    }else if(name == ItemTagConstants::SMALL_RED){
        t = SmallRedStone();
    }else if(name == ItemTagConstants::FINAL_FLAG){
        t = FinalFlagItem();
    }


    return t;
}

ItemFactory::ItemFactory(){
    
}
