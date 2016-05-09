//
//  ItemFactory.h
//  Space
//
//  Created by Ericko Hartanto on 4/17/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef ItemFactory_h
#define ItemFactory_h

#include "ItemTag.h"
#include "Item.h"
#include "RedStoneItem.h"
#include "GreyStoneItem.h"
#include "GreenDiamondItem.h"
#include "FuelTankItem.h"
#include "SmallRedStone.h"
#include "FinalFlagItem.h"

class ItemFactory{
public:
    ItemFactory();
    Item getItem(std::string name);
};


#endif /* ItemFactory_h */
