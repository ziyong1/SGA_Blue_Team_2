#include "stdafx.h"
#include "Door.h"


Door::Door()
{
}


Door::~Door()
{
}

HRESULT Door::init()
{
	//HubDoor
	_DoorCount = 0.0f;
	IMAGEMANAGER->addFrameImage("Door", "mapImage/Door4f.bmp",224 * 2, 24 * 2.5, 4, 1, true, RGB(255, 0, 255));
	
	return S_OK;
}

void Door::release()
{
}

void Door::update()
{
	DoorCount();
	
}

void Door::render()
{
	IMAGEMANAGER->findImage("Door")->frameRender(getMemDC(), 700, 490);
}
void Door::DoorCount()
{
	_DoorCount += TIMEMANAGER->getElapsedTime();
	if (_DoorCount > 1.0f)
	{
		if (IMAGEMANAGER->findImage("Door")->getFrameX() > IMAGEMANAGER->findImage("Door")->getMaxFrameX() - 1)
		{
			IMAGEMANAGER->findImage("Door")->setFrameX(0);
			OutputDebugString("a\n");
		}
		else
		{
			IMAGEMANAGER->findImage("Door")->setFrameX(IMAGEMANAGER->findImage("Door")->getFrameX() + 1);
		}
		_DoorCount = 0.0f;
	}
}