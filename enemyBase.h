#pragma once
#include "gameNode.h"
#include "enemyInterface.h"

class enemyManager;
class enemyBase : public gameNode
{
protected:
	enemyManager* _em;
	enemyMove* _enemyMove;
	int _nEnemyHP;
	int _moveRange;
	float _fSpeed;
	float _x, _y;
	float _angle;
	float _gravity;
	RECT _rc;
	bool bDie;
	image* _imageEnemy;

	//프레임으로 이미지 돌리기 위한 변수들
	int _currentFrameX;
	int _currentFrameY;
	float _count;

public:
	enemyBase();
	virtual ~enemyBase();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void setEmMemoryLink(enemyManager* em) { _em = em; }
};

