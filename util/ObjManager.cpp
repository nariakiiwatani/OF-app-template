#include "ObjManager.h"

#include "ofLog.h"

void ObjManager::addUpdate(BaseHasUpdatePrio* obj, int key)
{
	update_.insert(pair<int, BaseHasUpdatePrio*>(key, obj));
}
void ObjManager::addDraw(BaseHasDrawPrio* obj, int key)
{
	draw_.insert(pair<int, BaseHasDrawPrio*>(key, obj));
}
void ObjManager::addObject(void* obj, int key)
{
	obj_[key].push_back(obj);
}

void ObjManager::removeUpdate(int key)
{
	update_.erase(key);
}
void ObjManager::removeUpdate(BaseHasUpdatePrio* obj)
{
	for(multimap<int, BaseHasUpdatePrio*>::iterator it = update_.begin(); it != update_.end(); ++it) {
		if((*it).second == obj) {
			update_.erase(it);
			return;
		}
	}
//	ofLog(OF_LOG_WARNING, "couldn't find object. %s(%s)", __FILE__, __LINE__);
}
void ObjManager::removeUpdateAll()
{
	update_.clear();
}
void ObjManager::removeDraw(int key)
{
	draw_.erase(key);
}
void ObjManager::removeDraw(BaseHasDrawPrio* obj)
{
	for(multimap<int, BaseHasDrawPrio*>::iterator it = draw_.begin(); it != draw_.end(); ++it) {
		if((*it).second == obj) {
			draw_.erase(it);
			return;
		}
	}
//	ofLog(OF_LOG_WARNING, "couldn't find object. %s(%s)", __FILE__, __LINE__);
}
void ObjManager::removeDrawAll()
{
	draw_.clear();
}
void ObjManager::removeObject(void* obj, int key)
{
	vector<void*>::iterator it = find(obj_[key].begin(), obj_[key].end(), obj);
	if(it != obj_[key].end()) {
		obj_[key].erase(it);
		return;
	}
//	ofLog(OF_LOG_WARNING, "couldn't find object. %s(%s)", __FILE__, __LINE__);
}
void ObjManager::removeObject(int key)
{
	obj_[key].clear();
}
void ObjManager::removeObjectAll()
{
	obj_.clear();
}

void ObjManager::update()
{
	for(multimap<int, BaseHasUpdatePrio*>::iterator it=update_.begin(); it!=update_.end(); ++it) {
		if((*it).second->isAwake()) {
			(*it).second->updatePrio((*it).first);
		}
	}
}
void ObjManager::draw(bool clear)
{
	for(multimap<int, BaseHasDrawPrio*>::iterator it=draw_.begin(); it!=draw_.end(); ++it) {
		if((*it).second->isAwake()) {
			(*it).second->drawPrio((*it).first);
		}
	}
	if(clear) {
		clearDraw();
	}
}
void ObjManager::clearDraw()
{
	draw_.clear();
}

const vector<void*>& ObjManager::getObjectRef(int key)
{
	return obj_[key];
}
vector<void*> ObjManager::getObject(int key)
{
	return obj_[key];
}

/* EOF */