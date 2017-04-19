#pragma once
#include "gameNode.h"

class kirby;
class enemyManager;
class uiManager;

class mapManager : public gameNode
{
protected:
	kirby* _kirby;
	enemyManager* _em;
	uiManager* _uim;
public:
	mapManager();
	virtual ~mapManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setKirbyMemoryLink(kirby* kirby) { _kirby = kirby; }
	void setEmMemoryLink(enemyManager* em) { _em = em; }
	void setUimMemoryLink(uiManager* uim) { _uim = _uim; }
};

