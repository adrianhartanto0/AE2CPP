//
//  GameManager.h
//  climb
//
//  Created by Ericko Hartanto on 3/31/16.
//  Copyright © 2016 adrian. All rights reserved.
//

//#include "GameStage.h"
#include "GameStage.h"
//#include "AIManager.h"
#include "SelectLevel.h"
#include "GameStageX.h"
#include "InputManager.h"

class GameManager{
    
private:
    bool _isRunning;
    GameStage *stg;
    GameStageX *stg1;
    InputManager *input;
    SelectLevel *level;
    
public:
    GameManager();
    void cleanup();
    bool isGameRunning();
    void quit();
    void receiveInput();
    void update();
    void render();
    
};
