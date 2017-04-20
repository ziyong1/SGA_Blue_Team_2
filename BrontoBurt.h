#pragma once
#include "enemyBase.h"

class BrontoBurt :public enemyBase
{
private:

public:
	BrontoBurt();
	~BrontoBurt();

	HRESULT init(float x, float y, float speed, int moveRange);
	void release();
	void update();
	void render();
};

