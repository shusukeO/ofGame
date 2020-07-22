//
//  player.hpp
//  ofGame
//
//  Created by shu on 2020/07/21.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "ofMain.h"

class player{
    
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
    player();
};

#endif /* player_hpp */
