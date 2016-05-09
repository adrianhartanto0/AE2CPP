//
//  InputManager.h
//  Space
//
//  Created by Ericko Hartanto on 4/29/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#ifndef InputManager_h
#define InputManager_h

class InputManager{
private:
    int mouseX;
    int mouseY;
    bool clicked;
    const char *key;
public:
    InputManager();
    void setKey(const char *);
    void setMouseX(int);
    void setMouseY(int);
    int getMouseX();
    void setClickedMouse(bool val);
    int getMouseY();
    const char * getKey();
    void clearKey();
    bool getClick();
};


#endif /* InputManager_h */
