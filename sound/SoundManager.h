/*!
*/
#pragma once

#include "Def.h"
#include "ofSoundPlayer.h"
#include "ofxParamPanel.h"
#include "ofxParamToggle.h"

class ofxParamPanel;

class SoundManager
{
public:
	SoundManager();
	void init(string folder="sound");
	void bindParam(ofxParamPanel* panel, string grp="");
	void updateGui();
	void setMultiPlay(bool set);
	s32 size();
	void play(s32 index, bool loop=false);
	bool isPlaying();
	bool isPlaying(s32 index);
	void stop();
	void stop(s32 index);

	void playCollide(bool multi=true);
	void playCaugh(bool multi=true);
	void playBomb();

private:
	vector<ofSoundPlayer> player_;
	vector<ofxParamToggle> filename_;
	vector<bool> playing_;
	bool multiplay_;
};

/* EOF */