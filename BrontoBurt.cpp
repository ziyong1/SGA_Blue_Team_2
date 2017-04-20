#include "stdafx.h"
#include "BrontoBurt.h"


BrontoBurt::BrontoBurt()
{
}


BrontoBurt::~BrontoBurt()
{
}

HRESULT BrontoBurt::init(float x, float y, float speed, int moveRange)
{
	_imageEnemy = IMAGEMANAGER->addFrameImage("Enemy", "image//Enemy//BrontoBurt//°È±â.bmp", 200, 50, 4, 1, true, RGB(255, 0, 255));
	_imageEnemy->setFrameX(2);
	_imageEnemy->setFrameY(0);

	_enemyMove = new enemyMove;
	_enemyMove->init();

	_currentFrameX = 0;
	_moveRange = moveRange;
	_x = x;
	_y = y;
	_fSpeed = speed;
	_count = 0;

	_enemyMove->move(&_x, &_y, _fSpeed, _moveRange);
	return S_OK;
}

void BrontoBurt::release()
{

}

void BrontoBurt::update()
{
	_enemyMove->update();

	_count += TIMEMANAGER->getElapsedTime();

	if (_enemyMove->getisRightMoving())
	{
		if (_currentFrameX < 2)
		{
			_currentFrameX = 2;
			_imageEnemy->setFrameX(_currentFrameX);
		}

		if (_count > 0.3)
		{
			_count = 0;
			if (_currentFrameX > _imageEnemy->getMaxFrameX())_currentFrameX = 2;

			_imageEnemy->setFrameX(_currentFrameX);
			++_currentFrameX;

		}
	}

	if (!_enemyMove->getisRightMoving())
	{
		if (_currentFrameX >= 2)
		{
			_currentFrameX = 1;
			_imageEnemy->setFrameX(_currentFrameX);
		}

		if (_count > 0.3)
		{
			_count = 0;
			if (_currentFrameX < 0)_currentFrameX = 1;

			_imageEnemy->setFrameX(_currentFrameX);
			--_currentFrameX;

		}
	}
}

void BrontoBurt::render()
{
	_imageEnemy->frameRender(getMemDC(), _x, _y, _imageEnemy->getFrameX(), _imageEnemy->getFrameY());
}

