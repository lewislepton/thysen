#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofDisableArbTex();
  ofSetWindowTitle("thysen");
  ofSetFrameRate(60);
  oscIn.setup(INPORT);
//  oscOut.setup(HOST, OUTPORT);
  
  viewer.setup("watercolor.frag");
}

//--------------------------------------------------------------
void ofApp::update(){
  viewer.update();
  
  while (oscIn.hasWaitingMessages()){
    ofxOscMessage message;
    oscIn.getNextMessage(message);
    
    if (message.getAddress() == "/shaderSelect/select") {
      float oscValue = message.getArgAsFloat(0);
      future->shaderSelection = oscValue;
    }
    
    if (message.getAddress() == "/zoom/x"){
      float oscValue = message.getArgAsFloat(0);
      future->zoom = oscValue;
    }
    
    if (message.getAddress() == "/amount/x"){
      float oscValue = message.getArgAsFloat(0);
      future->amount = oscValue;
    }
    
    if (message.getAddress() == "/action/x"){
      float oscValue = message.getArgAsFloat(0);
      future->action = oscValue;
    }
    
    if (message.getAddress() == "/actionSpeed/x"){
      float oscValue = message.getArgAsFloat(0);
      future->actionSpeed = oscValue;
    }
    
    if (message.getAddress() == "/warp/x"){
      float oscValue = message.getArgAsFloat(0);
      future->warp.x = oscValue;
    } else if (message.getAddress() == "/warp/y"){
      float oscValue = message.getArgAsFloat(0);
      future->warp.y = oscValue;
    }
    
    if (message.getAddress() == "/color/x0"){
      float oscValue = message.getArgAsFloat(0);
      future->color.x = oscValue;
    } else if (message.getAddress() == "/color/x1"){
      float oscValue = message.getArgAsFloat(0);
      future->color.y = oscValue;
    } else if (message.getAddress() == "/color/x2"){
      float oscValue = message.getArgAsFloat(0);
      future->color.z = oscValue;
    }
    
    if (message.getAddress() == "/play/x0"){
      float oscValue = message.getArgAsFloat(0);
      future->play.x = oscValue;
    } else if (message.getAddress() == "/play/x1"){
      float oscValue = message.getArgAsFloat(0);
      future->play.y = oscValue;
    } else if (message.getAddress() == "/play/x2"){
      float oscValue = message.getArgAsFloat(0);
      future->play.z = oscValue;
    }
  }
  
  if (future->action){
    float time = 0;
    
    time = ofMap(future->actionSpeed, 0.0, 1.0, 0.001, 0.06);
    
    viewer.zoom = lerp(time, viewer.zoom, future->zoom);
    
    viewer.amount = lerp(time, viewer.amount, future->amount);
    
    viewer.warp.x = lerp(time, viewer.warp.x, future->warp.x);
    viewer.warp.y = lerp(time, viewer.warp.y, future->warp.y);
    
    viewer.color.x = lerp(time, viewer.color.x, future->color.x);
    viewer.color.y = lerp(time, viewer.color.y, future->color.y);
    viewer.color.z = lerp(time, viewer.color.z, future->color.z);
    
    viewer.play.x = lerp(time, viewer.play.x, future->play.x);
    viewer.play.y = lerp(time, viewer.play.y, future->play.y);
    viewer.play.z = lerp(time, viewer.play.z, future->play.z);
    
    viewer.shaderSelection = future->shaderSelection;
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  viewer.draw();
}

//--------------------------------------------------------------
float ofApp::lerp(float value, float min, float max){
  return min + (max - min) * value;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
  viewer.windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}
