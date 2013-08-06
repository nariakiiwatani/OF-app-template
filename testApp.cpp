/*!
*/

#include "testApp.h"
#include "ofxParamPanel.h"
#include "Def.h"

namespace {
	s32 x=0;
	s32 y=0;
	f32 scale=1.f;
}

void testApp::setup()
{
	core_.init();

	manager_.addUpdate(&core_, PRIO_UPDATE_CORE_PREPARE);
	manager_.addUpdate(&core_, PRIO_UPDATE_CORE_UPDATE);
	manager_.addUpdate(&core_, PRIO_UPDATE_CORE_CLEANUP);

	panel_.ofxParamPanel::setup("param");
	panel_.beginGroup("screen");
	panel_.addSlider("x", x, 0, SCREEN_WIDTH);
	panel_.addSlider("y", y, 0, SCREEN_HEIGHT);
	panel_.addSlider("scale", scale, 0.f, 3.f);
	panel_.endGroup();
	core_.bindParam(&panel_, "core");
	panel_.load();

#ifdef _DEBUG
	draw_panel_ = true;
#else
	draw_panel_ = false;
#endif
	fbo_.allocate(SCREEN_WIDTH, SCREEN_HEIGHT, GL_RGB);
	ofEnableAlphaBlending();
}

void testApp::update()
{
	manager_.update();
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

void testApp::draw()
{
	ofBackground(0);
	fbo_.begin();
	ofClear(0);
	manager_.draw();
	fbo_.end();
	ofPushMatrix();
	ofTranslate(x,y);
	ofScale(scale, scale);
	fbo_.draw(0,0);
	ofPopMatrix();
	if(draw_panel_) {
		panel_.draw();
	}
}

void testApp::exit()
{
	core_.exit();
}

void testApp::keyPressed(int key) {
	switch(key) {
	case OF_KEY_RETURN:
		draw_panel_ = !draw_panel_;
		break;
	}
}

/* EOF */