#include "stdafx.h"
#include "kirby.h"
#include "kirbys.h"

kirby::kirby()
{
}


kirby::~kirby()
{
}

HRESULT kirby::init()
{
	
	_currentKirby = new kirbyBase;
	_currentKirby->setKirbyMemoryLink(this);
	
	_currentKirby->init();

	_state = RIGHT_STOP;
	_currentKirby->setMotion();

	return S_OK;
}

void kirby::release()
{
	_currentKirby->release();
	SAFE_DELETE(_currentKirby);
}

void kirby::update()
{
	_currentKirby->update();
	keyControl();
}

void kirby::render()
{
	_currentKirby->render();
}

void kirby::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_state = LEFT_MOVE;
		_currentKirby->setMotion();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state = LEFT_STOP;
		_currentKirby->setMotion();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_state = RIGHT_MOVE;
		_currentKirby->setMotion();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_state = RIGHT_STOP;
		_currentKirby->setMotion();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{

	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{

	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{

	}
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{

	}



}
