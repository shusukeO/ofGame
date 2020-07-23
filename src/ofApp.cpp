#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //背景
    ofBackground(10, 10, 50);
    
    
    for(int i = 0; i < numPlayer; i++){
        player player;
        players.push_back(player);
    }
    
    //プレイヤー1
    players[0].pos.set(players[0].radius, ofGetHeight()/2);
    players[0].setColor(ofColor(177, 0, 0));
    //プレイヤー2
    players[1].pos.set(ofGetWidth() - players[1].radius, ofGetHeight()/2);
    players[1].setColor(ofColor(0, 0, 177));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ball.update();
    
    //ボールのプレイヤーとの反射
    for(int i= 0; i < players.size(); i++){
        if(players[i].pos.distance(ball.pos) < players[i].radius){
            ball.vel.x *= -1.1;
        }
    }
    
    for(int i= 0; i < players.size(); i++){
        players[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    
    if(ball.hp[0] > 0 && ball.hp[1] > 0){
        ofDrawBitmapString("HP" + to_string(ball.hp[0]), 50, 50);
        ofDrawBitmapString("HP" + to_string(ball.hp[1]), ofGetWidth() - 100, 50);
    } else if (ball.hp[0] >0){
        ofDrawBitmapString("WIN", 50, 50);
        ofDrawBitmapString("LOSE", ofGetWidth() - 100, 50);
        ofDrawBitmapString("SPACE->RESET", ofGetWidth()/2, 50);
    }else{
        ofDrawBitmapString("LOSE", 50, 50);
        ofDrawBitmapString("WIN", ofGetWidth() - 100, 50);
        ofDrawBitmapString("SPACE->RESET", ofGetWidth()/2, 50);
    }
    
    
    //中心のライン
    ofDrawLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
    ofNoFill();
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
    ofFill();
    
    
    ball.draw();
    
    for(int i= 0; i < players.size(); i++){
        players[i].draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //プレイヤー1操作
    switch (key) {
        case 'w':
             players[0].vel.set(0, -5);
            break;
        case 's':
             players[0].vel.set(0, 5);
            break;
        case 'd':
             players[0].vel.set(5, 0);
            break;
        case 'a':
             players[0].vel.set(-5, 0);
            break;
    }
    
    //プレイヤー2操作
    switch (key) {
        case OF_KEY_UP:
            players[1].vel.set(0, -5);
            break;
        case OF_KEY_DOWN:
             players[1].vel.set(0, 5);
            break;
        case OF_KEY_RIGHT:
             players[1].vel.set(5, 0);
            break;
        case OF_KEY_LEFT:
             players[1].vel.set(-5, 0);
            break;
        
    }
    
    //スコアリセット
    if(key == ' ' && (ball.hp[0] < 0 || ball.hp[1] < 0)){
        ball.hp[0] = ball.hp[1] = 15;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
