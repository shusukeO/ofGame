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
//    pos.set(0, ofGetHeight()/2);
//    vel.set(-3, -1);
    
    size = 0;
    
    setColor(ofColor(255));
    setRadius(size);
}

void ripple::update(){
    
    size += 2;
    setRadius(size);
}


void ripple::draw(){
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
