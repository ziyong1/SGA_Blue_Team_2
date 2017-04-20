#include "stdafx.h"
#include "enemyManager.h"
#include "BroomHatter.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{

	BroomHatter* _broomHatter;
	_broomHatter = new BroomHatter;
	_broomHatter->init(WINSIZEX / 2, WINSIZEY / 2, 1, 300);

	_vEnemy.push_back(_broomHatter);
	
	BrontoBurt* _BrontoBurt;
	_BrontoBurt = new BrontoBurt;
	_BrontoBurt->init(WINSIZEX / 2, WINSIZEY / 2 - 200, 1, 200);

	_vEnemy.push_back(_BrontoBurt);

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
		//if (_vEnemy[i])	//enemy 죽어있으면
		//{
		//	removeEnemy(i);
		//}
		//else
		//{
			++i;
		//}
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
