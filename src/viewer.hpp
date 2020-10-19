//
//  viewer.hpp
//  thysen
//
//  Created by Lewis Lepton on 14/10/2019.
//

#ifndef viewer_hpp
#define viewer_hpp

#include "ofMain.h"
#include "ofxShaderFilter.h"

class viewer : public ofBaseApp {
public:
  void setup(string fragment);
  void update();
  void draw();
  void windowResized(int w, int h);
  
  ofFbo fbo;
  
  ofxShaderFilter shader;
  int shaderSelection = 0;
  
  ofVec3f color;
  ofVec3f play;
  ofVec2f warp;
  float zoom;
  float amount;
};

#endif /* viewer_hpp */
