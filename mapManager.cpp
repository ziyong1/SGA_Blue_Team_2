#include "stdafx.h"
#include "mapManager.h"
#include "Door.h"


mapManager::mapManager(){}
mapManager::~mapManager(){}

HRESULT mapManager::init()
{
	_door = new Door;
	_door->init();
	//Hub
	IMAGEMANAGER->addImage("Hub", "mapImage/Hub.bmp", WINSIZEX * 2, WINSIZEY * 1.5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("HubBack", "mapImage/HubBack.bmp", WINSIZEX * 2, WINSIZEY * 1.5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("HubPix", "mapImage/HubPix.bmp", WINSIZEX * 2, WINSIZEY * 1.5, true, RGB(255, 0, 255));
	//Stage1
	IMAGEMANAGER->addImage("Stage1", "mapImage/Stage1.bmp", WINSIZEX * 4, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Stage1Back", "mapImage/Stage1Back.bmp", WINSIZEX * 4, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Stage1Pix", "mapImage/Stage1Pix.bmp", WINSIZEX * 4, WINSIZEY, true, RGB(255, 0, 255));
	currentStage = new image;
	currentStage = IMAGEMANAGER->findImage("Hub");
	currentBackGround = new image;
	currentBackGround = IMAGEMANAGER->findImage("HubBack");
	currentPixStage = new image;
	currentPixStage = IMAGEMANAGER->findImage("HubPix");
	
	x = 0;
	y = 0;
	
	return S_OK;
}

void mapManager::release()
{
}

void mapManager::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (x > 0)
		{
			x -= 10;
		}

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (x < currentStage->getWidth() - WINSIZEX)
		{
			x += 10;
		}

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (y >= currentStage->getHeight() - WINSIZEY)return;
		y += 10;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (y > 0)
		{
			y -= 10;
		}

	}
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		x = 0;
		y = 0;
		currentBackGround = IMAGEMANAGER->findImage("Stage1Back");
		currentStage = IMAGEMANAGER->findImage("Stage1");
		currentPixStage = IMAGEMANAGER->findImage("Stage1Pix");
	}
	if (KEYMANAGER->isOnceKeyDown('H'))
	{
		x = 0;
		y = 0;
		currentBackGround = IMAGEMANAGER->findImage("HubBack");
		currentStage = IMAGEMANAGER->findImage("Hub");
		currentPixStage = IMAGEMANAGER->findImage("HubPix");
	}
	_door->update();
}

void mapManager::render()
{
	currentBackGround->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), x, y);
	if (!_debug)
	{
		currentStage->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), x, y);
		if (currentStage == IMAGEMANAGER->findImage("Hub"))
		{
			_door->render();
		}
	}
	else
	{
		currentPixStage->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), 0, 0);
	}
	

}

image* mapManager::PixalCrushImage()
{
	return currentPixStage;
}

