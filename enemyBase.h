#pragma once
#include "gameNode.h"
class enemyManager;
class enemyBase : public gameNode
{
protected:
	enemyManager* _em;
public:
	enemyBase();
	virtual ~enemyBase();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEmMemoryLink(enemyManager* em) { _em = em; }
};

