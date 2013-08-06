/*!
*/
#pragma once

#include "ofBaseApp.h"
#include "AppCore.h"
#include "util/ObjManager.h"
#include "ofxParamPanel.h"

class testApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	void exit();
	void keyPressed(int key);
private:
	AppCore core_;
	ObjManager manager_;
	ofxParamPanel panel_;
	bool draw_panel_;
	ofFbo fbo_;
};

/* EOF */