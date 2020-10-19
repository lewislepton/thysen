//
//  Future.hpp
//  thysen
//
//  Created by Lewis Lepton on 14/10/2019.
//

#ifndef settingWindow_hpp
#define settingWindow_hpp

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxShaderFilter.h"
#include "thyUI.hpp"

class settingWindow : public ofBaseApp {
public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  
  void windowResized(int w, int h);
  
  ofFbo fbo;
  
  ofxShaderFilter shader;
  int shaderSelection = 0;
  
  ofVec2f position;
  ofVec3f color;
  ofVec3f play;
  ofVec2f warp;
  float zoom;
  float amount;
  
  bool action;
  float actionSpeed;
};

#endif /* settingWindow_hpp */
