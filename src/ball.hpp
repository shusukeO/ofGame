//
//  ball.hpp
//  ofGame
//
//  Created by shu on 2020/07/21.
//

#ifndef ball_hpp
#define ball_hpp

#include <stdio.h>
#include "ofMain.h"

#include "ripple.hpp"

class ball{
    
public:
    
    //属性 property, member
    ofVec2f pos;
    ofVec2f vel;
    float radius;
    ofColor color;
    
    //振る舞い method
    void setup();
    void update();
    void draw();
    
    void setColor(ofColor col);
    
    void setRadius(float rad);
    
    //constructor
    ball();
    
    int hp[2];
    
    vector<ripple> ripples;
};

#endif /* ball_hpp */
