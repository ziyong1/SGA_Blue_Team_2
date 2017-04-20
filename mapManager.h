#pragma once
#include "gameNode.h"

class kirby;
class enemyManager;
class uiManager;
class Door;
class mapManager : public gameNode
{
protected:
	kirby* _kirby;
	enemyManager* _em;
	uiManager* _uim;
	Door* _door;
	RECT _FocusRectTest;
	//½ÇÇè¿ë
	int x, y;
private:
	//mapImage
	image* currentStage;
	image* currentPixStage;
	image* currentBackGround;
	
public:
	mapManager();
	virtual ~mapManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	image* PixalCrushImage();
	void key();

	void setKirbyMemoryLink(kirby* kirby) { _kirby = kirby; }
	void setEmMemoryLink(enemyManager* em) { _em = em; }
	void setUimMemoryLink(uiManager* uim) { _uim = _uim; }
};

