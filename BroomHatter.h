#pragma once
#include "enemyBase.h"

class BroomHatter : public enemyBase
{
private:
public:
	BroomHatter();
	virtual ~BroomHatter();

	virtual HRESULT init(float x, float y, float speed, int moveRange);
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
};

