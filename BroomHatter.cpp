#include "stdafx.h"
#include "BroomHatter.h"


BroomHatter::BroomHatter()
{
}


BroomHatter::~BroomHatter()
{
}

HRESULT BroomHatter::init(float x, float y, float speed, int moveRange)
{
	_imageEnemy = IMAGEMANAGER->addFrameImage("Enemy", "image//Enemy//BroomHatter//°È±â.bmp", 400, 50, 8, 1, true, RGB(255, 0, 255));
	_imageEnemy->setFrameX(4);
	_imageEnemy->setFrameY(0);
	_enemyMove = new enemyMove;
	_enemyMove->init();
	_currentFrameX = 0;
	_x = x;
	_y = y;
	_fSpeed = speed;
	_count = 0;
	_moveRange = moveRange;

	_enemyMove->move(&_x, &_y, _fSpeed, _moveRange);
	
	return S_OK;
}

void BroomHatter::release()
{
	_enemyMove->release();
	
}

void BroomHatter::update()
{
	_enemyMove->update();

	_count += TIMEMANAGER->getElapsedTime();

	if (_enemyMove->getisRightMoving())
	{
		if (_currentFrameX < 4)
		{
			_currentFrameX = 4;
			_imageEnemy->setFrameX(_currentFrameX);
		}

		if (_count > 0.3)
		{
			_count = 0;
			if (_currentFrameX > _imageEnemy->getMaxFrameX())_currentFrameX = 4;

			_imageEnemy->setFrameX(_currentFrameX);
			++_currentFrameX;

		}
	}

	if (!_enemyMove->getisRightMoving())
	{
		if (_currentFrameX >= 4)
		{
			_currentFrameX = 3;
			_imageEnemy->setFrameX(_currentFrameX);
		}

		if (_count > 0.3)
		{
			_count = 0;
			if (_currentFrameX < 0)_currentFrameX = 3;

			_imageEnemy->setFrameX(_currentFrameX);
			--_currentFrameX;

		}
	}
}

void BroomHatter::render()
{
	_imageEnemy->frameRender(getMemDC(), _x, _y, _imageEnemy->getFrameX(), _imageEnemy->getFrameY());
}

void BroomHatter::move()
{

}