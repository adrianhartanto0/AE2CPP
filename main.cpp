//
//  main.cpp
//  climb
//
//  Created by Ericko Hartanto on 3/26/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include <iostream>
#include "GameManager.h"


int main(int argc, const char * argv[]) {

    GameManager mg = GameManager();
    
//    unsigned int time = 0;
//    unsigned int curr_time;
    
    while(mg.isGameRunning()){
        
//        curr_time = SDL_GetTicks();
        mg.receiveInput();
        mg.update();
        mg.render();
//        time = cur;
        
//        time = curr_time;
        
    }
    
    mg.quit();

    return 0;
}
