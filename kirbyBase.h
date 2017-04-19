#pragma once
#include "gameNode.h"


class kirbyBase : public gameNode
{
protected:


public:
	kirbyBase();
	virtual ~kirbyBase();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};

