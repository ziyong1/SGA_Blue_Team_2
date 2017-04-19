#pragma once
#include "gameNode.h"

class kirby;
class enemyManager;
class uiManager : public gameNode
{
protected:
	kirby* _kirby;
	enemyManager* _em;

public:
	uiManager();
	virtual ~uiManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setKirbyMemoryLink(kirby* kirby) { _kirby = kirby; }
	void setEmMemoryLink(enemyManager* em) { _em = em; }
};

