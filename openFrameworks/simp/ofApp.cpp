#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(40);
    ofSetWindowTitle("MovingTorus");
    
    ofBackground(255, 255, 255);
    ofSetLineWidth(5);
    ofEnableDepthTest();
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    this->cam.begin();
    
    ofColor color;
    
    for(int r = 200; r >= 17; r -= 17){
        ofRotate(ofGetFrameNum() * 0.5);
        
        int v_start = ofGetFrameNum();
        
        for(int v = v_start; v < v_start + 40; v += 8){
            for(int u = 0; u < 360; u += 10){
                
                ofSetColor(255, 255, 130, 180);
                ofFill();
                
                ofBeginShape();
                ofVertex(this->make_point
                         (300, r, u - 9.9, v - 4.9));
                ofVertex(this->make_point
                         (300, r, u + 9.9, v - 4.9));
                ofVertex(this->make_point
                         (300, r, u + 9.9, v + 4.9));
                ofVertex(this->make_point
                         (300, r, u - 9.9, v + 4.9));
                ofEndShape(true);
                
                ofSetColor(39, 52, 154, 220);
                ofNoFill();
                
                ofBeginShape();
                ofVertex(this->make_point
                         (300, r, u - 10, v - 5));
                ofVertex(this->make_point
                         (300, r, u + 10, v - 5));
                ofVertex(this->make_point
                         (300, r, u + 10, v + 5));
                ofVertex(this->make_point
                         (300, r, u - 10, v + 5));
                ofEndShape(true);
            }
        }
    }
    
    this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

glm::vec3 ofApp::make_point(float R, float r, float u, float v){
    
    u *= DEG_TO_RAD;
    v *= DEG_TO_RAD;
    
    float x = (R + r * cos(u)) * cos(v);
    float y = (R + r * cos(u)) * sin(v);
    float z = r * sin(u);
    
    return glm::vec3(x, y, z);
    
}
