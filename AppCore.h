#pragma once

#include "Def.h"
#include "util/ObjManager.h"

class ofxParamPanel;
class AppCore : public BaseHasUpdatePrio
{
public:
	void init();
	void exit();
	void bindParam(ofxParamPanel* panel, string grp="");
private:
	void updatePrio(s32 prio);

	void prepare(){}
	void update();
	void cleanup(){}

};
/* EOF */