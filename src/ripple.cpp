//
//  ripple.cpp
//  ofGame
//
//  Created by shu on 2020/07/23.
//

#include "ripple.hpp"

//constructor
ripple::ripple(){
    setup();
}

void ripple::setup(){
    size = 0;
    
    setRadius(size);
}

void ripple::update(){
    
    size += 3;
    setRadius(size);
}


void ripple::draw(){
    ofSetColor(color);
    ofNoFill();
    ofDrawCircle(pos.x, pos.y, radius);
    ofFill();
}

void ripple::setColor(ofColor col){
    color = col;
}

void ripple::setRadius(float rad){
    radius = rad;
}
