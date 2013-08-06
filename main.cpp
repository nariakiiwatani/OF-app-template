
#include "ofMain.h"
#include "testApp.h"
#include "Def.h"
#include "ofAppGlutWindow.h"

void main()
{
    ofAppGlutWindow window;
	ofSetupOpenGL(&window, SCREEN_WIDTH, SCREEN_HEIGHT, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	testApp* app =  new testApp();
//	ofSetWindowPosition(1280,0);
//	ofSetFrameRate(30);
	ofRunApp(app);
	delete app;
}

/* EOF */