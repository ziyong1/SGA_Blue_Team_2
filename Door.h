#pragma once
#include "gameNode.h"
class Door : public gameNode
{
private:
	float _DoorCount;
public:
	Door();
	~Door();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void DoorCount();
};

