#include "stdafx.h"
#include "enemyManager.h"
#include "enemy.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (int i = 0; i < _vEnemy.size();)
	{
		_vEnemy[i]->update();
		if (_vEnemy[i])	//enemy Á×¾îÀÖÀ¸¸é
		{
			removeEnemy(i);
		}
		else
		{
			++i;
		}
	}
}

void enemyManager::render()
{
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		_vEnemy[i]->render();
	}
}

void enemyManager::removeEnemy(int index)
{
	_vEnemy[index]->release();
	SAFE_DELETE(_vEnemy[index]);
	_vEnemy.erase(_vEnemy.begin() + index);
}

void enemyManager::addEnemy()
{

}
