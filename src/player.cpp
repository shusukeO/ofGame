//
//  player.cpp
//  ofGame
//
//  Created by shu on 2020/07/21.
//

#include "player.hpp"

//constructor
player::player(){
    setup();
}

void player::setup(){
//    pos.set(0, ofGetHeight()/2);
//    vel.set(-3, -1);
//    setColor(ofColor(255));
    setRadius(25);
}

void player::update(){
    
    
    pos += vel;
    
    //はみ出さないようにする
    if(pos.x - radius < 0){
        pos.x = radius;;
    }else if(pos.x + radius > ofGetWidth()){
        pos.x = ofGetWidth() - radius;
    }
    
    if(pos.y - radius < 0){
        pos.y = radius;
    }else if(pos.y + radius > ofGetHeight()){
        pos.y = ofGetHeight() - radius;
    }
    
    
    
}


void player::draw(){
    ofSetColor(color);
//    ofDrawRectangle(pos.x, pos.y - 40, 30, 80);
    ofDrawCircle(pos.x, pos.y, radius);
}

void player::setColor(ofColor col){
    color = col;
}

void player::setRadius(float rad){
    radius = rad;
}


