//
//  thyUI.hpp
//  thysen
//
//  Created by Lewis Lepton on 23/10/2019.
//

#ifndef thyUI_hpp
#define thyUI_hpp

#include "ofMain.h"
#include "ofxGui.h"

class thyUI : public ofBaseApp {
public:
  void setup();
  void update();
  void draw();
  
  ofxPanel gui;
  ofParameterGroup control;
  ofParameter<ofVec3f> uiColor;
  ofParameter<ofVec2f> uiWarp;
  ofParameter<float> uiZoom;
  ofParameter<bool> uiAction;
  ofParameter<float> uiActionSpeed;
};

#endif /* thyUI_hpp */
