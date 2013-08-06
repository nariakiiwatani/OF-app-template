#pragma once

#include "ofTypes.h"
#include <map>

class BaseObj
{
public:
	BaseObj():is_sleep_(false){}
	void setSleep(bool sleep) { is_sleep_ = sleep; }
	void sleep() { is_sleep_ = true; }
	void awake() { is_sleep_ = false; }
	bool isSleep() { return is_sleep_; }
	bool isAwake() { return !is_sleep_; }
private:
	bool is_sleep_;
};

class BaseHasUpdatePrio : public BaseObj
{
friend class ObjManager;
protected:
	virtual void updatePrio(int prio)=0;
};

class BaseHasDrawPrio : public BaseObj
{
friend class ObjManager;
protected:
	virtual void drawPrio(int prio)=0;
};

class ObjManager
{
public:
	void addUpdate(BaseHasUpdatePrio* obj, int key=0);
	void addDraw(BaseHasDrawPrio* obj, int key=0);
	void addObject(void* obj, int key);

	void removeUpdate(BaseHasUpdatePrio* obj);
	void removeUpdate(int key);
	void removeUpdateAll();
	void removeDraw(BaseHasDrawPrio* obj);
	void removeDraw(int key);
	void removeDrawAll();
	void removeObject(void* obj, int key);
	void removeObject(int key);
	void removeObjectAll();

	const vector<void*>& getObjectRef(int key);
	vector<void*> getObject(int key);

public:
	void update();
	void draw(bool clear=false);
	void clearDraw();

private:
	map<int, vector<void*>> obj_;
	multimap<int, BaseHasUpdatePrio*> update_;
	multimap<int, BaseHasDrawPrio*> draw_;
};

/* EOF */