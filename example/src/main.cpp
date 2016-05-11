#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main( ){
    ofGLWindowSettings settings;
    settings.setGLVersion(2,1); // last version where fixed pipeline was default
    // settings.setGLVersion(3,2); // use programmable renderer
    ofCreateWindow(settings);
    
    ofRunApp(new testApp());
}
