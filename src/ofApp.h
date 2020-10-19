#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOsc.h"
#include "ofxShader.h"
#include "ofxShaderFilter.h"
#include "viewer.hpp"
#include "settingWindow.hpp"

#define INPORT 12345
#define OUTPORT 8000
#define HOST "lepton.local"

class ofApp : public ofBaseApp {
public:
  void setup();
  void update();
  void draw();

  float lerp(float value, float min, float max);

  void keyPressed(int key);
  void keyReleased(int key);
  void windowResized(int w, int h);
  void gotMessage(ofMessage msg);
  
//  CONTROLS
  ofxPanel gui;
  
  ofxOscReceiver oscIn;
//  ofxOscSender oscOut;
  
  ofxShaderFilter curShader;
  ofxShaderFilter futShader;
  
  viewer viewer;
  
  shared_ptr<settingWindow> future;
};
