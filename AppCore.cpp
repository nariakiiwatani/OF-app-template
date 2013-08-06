#include "AppCore.h"
#include "ofxParamPanel.h"

void AppCore::init()
{
}

void AppCore::exit()
{
}

void AppCore::bindParam(ofxParamPanel* panel, string grp)
{
	if(grp != "") {
		panel->beginGroup(grp);
	}
	if(grp != "") {
		panel->endGroup();
	}
}

void AppCore::update()
{
}

void AppCore::updatePrio(s32 prio)
{
	switch(prio) {
	case PRIO_UPDATE_CORE_PREPARE:
		prepare();
		break;
	case PRIO_UPDATE_CORE_UPDATE:
		update();
		break;
	case PRIO_UPDATE_CORE_CLEANUP:
		cleanup();
		break;
	}
}

/* EOF */