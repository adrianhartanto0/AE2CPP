//
//  InputManager.cpp
//  Space
//
//  Created by Ericko Hartanto on 4/29/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "InputManager.h"

InputManager::InputManager(){
    this->mouseX = 0;
    this->mouseY = 0;
    this->key = nullptr;
}

void InputManager::setMouseX(int val){
    this->mouseX = val;
}

void InputManager::setMouseY(int val){
    this->mouseY = val;
}

void InputManager::setKey(const char *k){
    this->key = k;
}

int InputManager::getMouseX(){
    return this->mouseX;
}

int InputManager::getMouseY(){
    return this->mouseY;
}

const char * InputManager::getKey(){
    return this->key;
}

void InputManager::clearKey(){
    this->key = nullptr;
}

void InputManager::setClickedMouse(bool val){
    this->clicked = val;
}

bool InputManager::getClick(){
    return this->clicked;
}
