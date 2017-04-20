#include "stdafx.h"
#include "mainGame.h"

#include "titleScene.h"
#include "gameScene.h"
#include "settingScene.h"
#include "menuScene.h"

BOOL _debug = false;

mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}
////////////////////////////////////
//������ �Ҹ��� ���̺���
////////////////////////////////////

//�ʱ�ȭ ���ִ� �Լ�
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	_winSizeX = WINSIZEX;
	_winSizeY = WINSIZEY;

	SCENEMANAGER->addScene("titleScene", new titleScene);
	SCENEMANAGER->addScene("menuScene", new menuScene);
	SCENEMANAGER->addScene("settingScene", new settingScene);
	SCENEMANAGER->addScene("gameScene", new gameScene);

	SCENEMANAGER->changeScene("titleScene");
	
	return S_OK;
}

//�޸� �����Լ�
void mainGame::release(void)
{
	gameNode::release();

}

//���� �ϴ� ��
void mainGame::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();	

	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		_debug = !_debug;
	}

	RECT temp;
	GetClientRect(_hWnd, &temp);

	_winSizeX = (temp.right - temp.left);
	_winSizeY = (temp.bottom - temp.top);

}

//�׷��ִ� ��
void mainGame::render()
{
	//��� ��ȭ�� ������ �ʿ���
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	SCENEMANAGER->render();

	if(_debug)
		TIMEMANAGER->render(getMemDC());


	//����ۿ� �Ű� �׷��� �� �ǵ������� ���
	this->getBackBuffer()->render(getHDC(), 0, 0,_winSizeX,_winSizeY);

}
