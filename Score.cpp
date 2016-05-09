//
//  Score.cpp
//  climb
//
//  Created by Ericko Hartanto on 4/12/16.
//  Copyright © 2016 adrian. All rights reserved.
//

#include "Score.h"

Score::Score(){
    
}

Score::Score(SDL_Color clr){
    this->score = 0;
    this->fontColor = clr;
}

SDL_Surface * Score::render(){

    std::string sc = "Score: ";
    Text txt = Text(sc.append(std::to_string(this->score)), 30,this->fontColor);
    return txt.render();
}

void Score::setVal(int val1){
    this->score = val1;
}

