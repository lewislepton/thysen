//
//  thyUI.cpp
//  thysen
//
//  Created by Lewis Lepton on 23/10/2019.
//

#include "thyUI.hpp"

void thyUI::setup(){
  control.setName("control");
  control.add(uiAction.set("action", false));
  control.add(uiActionSpeed.set("action speed", 0.0, 0.0, 1.0));
  control.add(uiColor.set("color", ofVec3f(1.0, 1.0, 1.0), ofVec3f(0.0, 0.0, 0.0), ofVec3f(1.0, 1.0, 1.0)));
  control.add(uiWarp.set("warp", ofVec2f(0.0, 0.0), ofVec2f(0.0, 0.0), ofVec2f(10.0, 10.0)));
  control.add(uiZoom.set("zoom", 0.0, 0.0, 1.0));
  gui.setup(control);
}

void thyUI::update(){
  
}

void thyUI::draw(){
  gui.draw();
}
