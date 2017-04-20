#include "stdafx.h"
#include "gameScene.h"

#include "kirby.h"
#include "enemyManager.h"
#include "mapManager.h"
#include "uiManager.h"

gameScene::gameScene()
{
}


gameScene::~gameScene()
{
}

HRESULT gameScene::init()
{
	_kirby = new kirby;
	_kirby->init();

	_em = new enemyManager;
	_em->init();

	_mm = new mapManager;
	_mm->init();

	_uim = new uiManager;
	_uim->init();

	_kirby->setEmMemoryLink(_em);
	_kirby->setMmMemoryLink(_mm);

	_em->setEmMemoryLink(_mm);

	_mm->setEmMemoryLink(_em);
	_mm->setKirbyMemoryLink(_kirby);
	_mm->setUimMemoryLink(_uim);

	_uim->setKirbyMemoryLink(_kirby);
	_uim->setEmMemoryLink(_em);



	return S_OK;
}

void gameScene::release()
{
	_kirby->release();
	_em->release();
	_mm->release();
	_uim->release();

	SAFE_DELETE(_kirby);
	SAFE_DELETE(_em);
	SAFE_DELETE(_mm);
	SAFE_DELETE(_uim);
}

void gameScene::update()
{
	_kirby->update();
	_em->update();
	_mm->update();
	_uim->update();
}

void gameScene::render()
{
	_mm->render();
	_kirby->render();
	_em->render();
	_uim->render();
}
