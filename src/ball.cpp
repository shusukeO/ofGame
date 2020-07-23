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
        
        //エフェクトで波紋を出す
        ripple tmpRipple;
        tmpRipple.pos.set(pos.x, pos.y);
        ripples.push_back(tmpRipple);
        
        //体力減らす
        hp[0] --;
    }else if(pos.x > ofGetWidth()){
        //ボールの速度を初期値に戻す
        vel.x = -3;
        
        
        //エフェクトで波紋を出す
        ripple tmpRipple;
        tmpRipple.pos.set(pos.x, pos.y);
        ripples.push_back(tmpRipple);
        
        //体力減らす
        hp[1] --;
    }
    
    if(pos.y < 0 || pos.y > ofGetHeight()) vel.y *= -1.0;
    
    
    //エフェクトupdate
    for(int i = 0; i < ripples.size(); i++){
        ripples[i].update();
        
        if(ripples[i].size > 500){
            ripples.erase(ripples.begin() + i);
        }
    }
}


void ball::draw(){
    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, radius);
    
    
    //エフェクトdraw
    for(int i = 0; i < ripples.size(); i++){
        ripples[i].draw();
    }
}

void ball::setColor(ofColor col){
    color = col;
}

void ball::setRadius(float rad){
    radius = rad;
}
