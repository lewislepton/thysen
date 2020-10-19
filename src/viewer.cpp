//
//  viewer.cpp
//  thysen
//
//  Created by Lewis Lepton on 14/10/2019.
//

#include "viewer.hpp"

//--------------------------------------------------------------
void viewer::setup(string fragment){
  fbo.allocate(ofGetWidth(), ofGetHeight());
  fbo.begin();
  ofClear(255);
  shader.allocate(fbo.getWidth(), fbo.getHeight());
  shader.load(fragment);
  fbo.end();
}

//--------------------------------------------------------------
void viewer::update(){
  fbo.begin();
  if (shaderSelection == 0) {
    shader.load("watercolor.frag");
  } else if (shaderSelection == 1){
    shader.load("morphgrid.frag");
  } else if (shaderSelection == 2){
    shader.load("morphboxes.frag");
  } else if (shaderSelection == 3){
    shader.load("orangeballs.frag");
  }
  
  shader.setUniform2f("u_warp", warp.x, warp.y);
  
  shader.setUniform3f("u_colors", color.x, color.y, color.z);
  
  shader.setUniform3f("u_play", play.x, play.y, play.z);
  
  shader.setUniform1f("u_zoom", zoom);
  
  shader.setUniform1f("u_amount", amount);
  fbo.end();
  
  fbo.begin();
  shader.render();
  shader.draw(0, 0, ofGetWidth(), ofGetHeight());
  fbo.end();
}

//--------------------------------------------------------------
void viewer::draw(){
  fbo.draw(0, 0);
}

//--------------------------------------------------------------
void viewer::windowResized(int w, int h){
  shader.allocate(w, h);
  fbo.allocate(w, h);
}
