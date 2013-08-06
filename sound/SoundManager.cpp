/*!
*/

#include "SoundManager.h"
#include "ofxParamPanel.h"

SoundManager::SoundManager()
	:multiplay_(true)
{
}
void SoundManager::init(string folder)
{
	ofDirectory dir;
	dir.listDir(folder);
	vector<ofFile>& files = dir.getFiles();
	s32 size = files.size();
	player_.resize(size);
	filename_.resize(size);
	playing_.resize(size);
	for(s32 i = 0; i < size; ++i) {
		player_[i].loadSound(folder+"/"+files[i].getFileName());
		filename_[i].setup(files[i].getFileName());
		playing_[i] = false;
	}
}

void SoundManager::bindParam(ofxParamPanel* panel, string grp)
{
	if(grp!="") {
		panel->beginGroup(grp);
	}
	s32 size = filename_.size();
	for(s32 i = 0; i < size; ++i) {
		panel->add(&filename_[i]);
	}
	if(grp!="") {
		panel->endGroup();
	}
}

void SoundManager::updateGui()
{
	s32 size = filename_.size();
	for(s32 i = 0; i < size; ++i) {
		if((ofxToggle)filename_[i]) {
			if(!playing_[i]) {
				play(i);
			}
			if(!player_[i].getIsPlaying()) {
				stop(i);
				(ofxToggle)filename_[i] = false;
			}
		}
		else {
			if(player_[i].getIsPlaying()) {
				stop(i);
			}
		}
	}
}

s32 SoundManager::size()
{
	return player_.size();
}
void SoundManager::setMultiPlay(bool set)
{
	multiplay_ = set;
}
void SoundManager::play(s32 index, bool loop)
{
	if(index < 0 || size() <= index) {
		return;
	}
	if(!multiplay_) {
		stop();
	}
	player_[index].setLoop(loop);
	player_[index].play();
	playing_[index] = true;
}
bool SoundManager::isPlaying()
{
	for(vector<ofSoundPlayer>::iterator it = player_.begin(); it != player_.end(); ++it) {
		if((*it).getIsPlaying()) {
			return true;
		}
	}
	return false;
}
bool SoundManager::isPlaying(s32 index)
{
	return player_[index].getIsPlaying();
}
void SoundManager::stop()
{
	s32 size = player_.size();
	for(s32 i = 0; i < size; ++i) {
		if(player_[i].getIsPlaying()) {
			stop(i);
		}
	}
}
void SoundManager::stop(s32 index)
{
	if(index < 0 || size() <= index) {
		return;
	}
	if(player_[index].getIsPlaying()) {
		player_[index].stop();
	}
	playing_[index] = false;
}

void SoundManager::playCollide(bool multi)
{
	vector<s32> arr;
	for(s32 i = 4; i < 7; ++i) {
		if(multi || !player_[i].getIsPlaying()) { 
			arr.push_back(i);
		}
	}
	if(arr.empty()) {
		return;
	}
	play(arr[(s32)ofRandom(arr.size())]);
}

void SoundManager::playCaugh(bool multi)
{
	vector<s32> arr;
	for(s32 i = 1; i < 4; ++i) {
		if(multi || !player_[i].getIsPlaying()) { 
			arr.push_back(i);
		}
	}
	if(arr.empty()) {
		return;
	}
	play(arr[(s32)ofRandom(arr.size())]);
}

void SoundManager::playBomb()
{
	play(0);
}


/* EOF */