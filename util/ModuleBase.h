#pragma once

#include "util/ObjManager.h"

class AppCore;
class ofxParamPanel;
class UpdateModule : public BaseHasUpdatePrio
{
public:
	void setTarget(AppCore* core) { core_ = core; }
	virtual void bindParam(ofxParamPanel* panel, string grp){}
	void setEnable(bool enable) { setSleep(!enable); }
	void setEnableCB(bool &enable) { setSleep(!enable); }
protected:
	AppCore* core_;
};

class DrawModule : public BaseHasDrawPrio
{
public:
	void setTarget(AppCore* core) { core_ = core; }
	virtual void bindParam(ofxParamPanel* panel, string grp){}
	void setEnable(bool enable) { setSleep(!enable); }
	void setEnableCB(bool &enable) { setSleep(!enable); }
protected:
	AppCore* core_;
};


/* EOF */