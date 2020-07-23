//
//  ripple.hpp
//  ofGame
//
//  Created by shu on 2020/07/23.
//

#ifndef ripple_hpp
#define ripple_hpp

#include <stdio.h>
#include "ofMain.h"

class ripple{
public:
    //属性 property, member
    ofVec2f pos;
    float radius;
    ofColor color;
    
    float size;
    
    //振る舞い method
    void setup();
    void update();
    void draw();
    
    void setColor(ofColor col);
    
    void setRadius(float rad);
    
    //constructor
    ripple();
};

#endif /* ripple_hpp */
