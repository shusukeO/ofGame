//
//  ball.cpp
//  ofGame
//
//  Created by shu on 2020/07/21.
//

#include "ball.hpp"

ball::ball(){
    setup();
}


void ball::setup(){
    pos.set(ofGetWidth()/2, ofGetHeight()/2);
    vel.set(-3, -1);
    setRadius(15.0);
    setColor(ofColor(255));
    
    //各チームの体力初期化
    hp[0] = hp[1] = 15;
}

void ball::update(){
    pos += vel;
    
    //壁との反射
    if(pos.x < 0){
        //ボールの速度を初期値に戻す
        vel.x = 3;
        
        //体力減らす
        hp[0] --;
    }else if(pos.x > ofGetWidth()){
        //ボールの速度を初期値に戻す
        vel.x = -3;
        
        //体力減らす
        hp[1] --;
    }
    if(pos.y < 0 || pos.y > ofGetHeight()) vel.y *= -1.0;
}


void ball::draw(){
    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, radius);
}

void ball::setColor(ofColor col){
    color = col;
}

void ball::setRadius(float rad){
    radius = rad;
}
