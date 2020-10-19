#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
//  ofSetupOpenGL(1280, 720, OF_WINDOW);      // <-------- setup the GL context

//  ofGLWindowSettings settings;
//  settings.setGLVersion(3, 2);
//  settings.setSize(1280, 720);
//  ofCreateWindow(settings);
//  ofRunApp(new ofApp());
  
  
  
//  settings.setSize(1280, 720);
//  settings.setGLVersion(3, 2);
//  settings.resizable = true;
//  shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
//
//  settings.setSize(640, 360);
//  settings.setPosition(ofVec2f(0,0));
//  settings.resizable = true;
//  shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
//
//  shared_ptr<ofApp> mainApp(new ofApp);
//  shared_ptr<viewer> guiApp(new viewer);
//  mainApp->gui = guiApp;
//
//  ofRunApp(guiWindow, guiApp);
//  ofRunApp(mainWindow, mainApp);
//  ofRunMainLoop();




  ofGLFWWindowSettings settings;

  settings.setSize(1280, 720);
  settings.setGLVersion(3, 2);
  settings.resizable = true;
  shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

  settings.setSize(640, 360);
  settings.setGLVersion(3, 2);
  settings.resizable = true;
  shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);

  shared_ptr<ofApp> mainApp(new ofApp);
  shared_ptr<settingWindow> guiApp(new settingWindow);
  mainApp->future = guiApp;

  ofRunApp(guiWindow, guiApp);
  ofRunApp(mainWindow, mainApp);
  ofRunMainLoop();
}
