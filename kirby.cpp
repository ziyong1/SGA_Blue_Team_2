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
	_currentKirby->init();
	return S_OK;
}

void kirby::release()
{
	_currentKirby->release();
	SAFE_DELETE(_currentKirby);
}

void kirby::update()
{

}

void kirby::render()
{

}
