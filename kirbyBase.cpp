#include "stdafx.h"
#include "kirbyBase.h"
#include "kirby.h"


kirbyBase::kirbyBase()
{
}


kirbyBase::~kirbyBase()
{
}

HRESULT kirbyBase::init()
{

	initImage();

	_motion = KEYANIMANAGER->findAnimation("�븻Ŀ��_RIGHT_STOP");

	return S_OK;
}

void kirbyBase::release()
{
}

void kirbyBase::update()
{

	KEYANIMANAGER->update();
}

void kirbyBase::render()
{
	_image->aniRender(getMemDC(), 100, 100, _motion);
}

void kirbyBase::setMotion(string keyName)
{
	_motion = KEYANIMANAGER->findAnimation(keyName);
	_motion->start();
}

void kirbyBase::setMotion()
{
	STATE state = _kirby->getState();

	switch (state)
	{
	case LEFT_STOP:
		_motion = KEYANIMANAGER->findAnimation("�븻Ŀ��_LEFT_STOP");
		_image = IMAGEMANAGER->findImage("�븻Ŀ��_STOP");
		_motion->start();
		break;
	case RIGHT_STOP:
		_motion = KEYANIMANAGER->findAnimation("�븻Ŀ��_RIGHT_STOP");
		_image = IMAGEMANAGER->findImage("�븻Ŀ��_STOP");
		_motion->start();
		break;
	case LEFT_LOW_STOP_UP:
		break;
	case RIGHT_LOW_STOP_UP:
		break;
	case LEFT_LOW_STOP_DOWN:
		break;
	case RIGHT_LOW_STOP_DOWN:
		break;
	case LEFT_HIGH_STOP_UP:
		break;
	case RIGHT_HIGH_STOP_UP:
		break;
	case LEFT_HIGH_STOP_DOWN:
		break;
	case RIGHT_HIGH_STOP_DOWN:
		break;
	case LEFT_SIT:
		break;
	case RIGHT_SIT:
		break;
	case LEFT_LOW_SIT_DOWN:
		break;
	case RIGHT_LOW_SIT_DOWN:
		break;
	case LEFT_LOW_SIT_UP:
		break;
	case RIGHT_LOW_SIT_UP:
		break;
	case LEFT_HIGH_SIT_DOWN:
		break;
	case RIGHT_HIGH_SIT_DOWN:
		break;
	case LEFT_HIGH_SIT_UP:
		break;
	case RIGHT_HIGH_SIT_UP:
		break;
	case LEFT_MOVE:
		_motion = KEYANIMANAGER->findAnimation("�븻Ŀ��_LEFT_MOVE");
		_image = IMAGEMANAGER->findImage("�븻Ŀ��_MOVE");
		_motion->start();
		break;
	case RIGHT_MOVE:
		_motion = KEYANIMANAGER->findAnimation("�븻Ŀ��_RIGHT_MOVE");
		_image = IMAGEMANAGER->findImage("�븻Ŀ��_MOVE");
		_motion->start();
		break;
	case LEFT_LOW_MOVE:
		break;
	case RIGHT_LOW_MOVE:
		break;
	case LEFT_HIGH_MOVE:
		break;
	case RIGHT_HIGH_MOVE:
		break;
	case LEFT_DASH:
		break;
	case RIGHT_DASH:
		break;
	case LEFT_FLY_UP:
		break;
	case RIGHT_FLY_UP:
		break;
	case LEFT_FLY_DOWN:
		break;
	case RIGHT_FLY_DOWN:
		break;
	case LEFT_FLY:
		break;
	case RIGHT_FLY:
		break;
	case LEFT_JUMP_UP:
		break;
	case RIGHT_JUMP_UP:
		break;
	case LEFT_JUMP_TURN:
		break;
	case RIGHT_JUMP_TURN:
		break;
	case LEFT_JUMP_DOWN:
		break;
	case RIGHT_JUMP_DOWN:
		break;
	case LEFT_KICK:
		break;
	case RIGHT_KICK:
		break;
	case LEFT_EAT:
		break;
	case RIGHT_EAT:
		break;
	case LEFT_THROW:
		break;
	case RIGHT_THROW:
		break;
	case LEFT_FALL:
		break;
	case RIGHT_FALL:
		break;
	case LEFT_ATTACK:
		break;
	case RIGHT_ATTACK:
		break;
	case LEFT_RETURN:
		break;
	case RIGHT_RETURN:
		break;
	case LEFT_CRASH:
		break;
	case RIGHT_CRASH:
		break;
	case LEFT_SWIM:
		break;
	case RIGHT_SWIM:
		break;
	default:
		break;
	}
}

void kirbyBase::initImage()
{
	// �̹��� �߰�

	_image = IMAGEMANAGER->addFrameImage("�븻Ŀ��_STOP", "image\\characters\\kirby\\�븻Ŀ��\\kirby_idle_����.bmp", 58 * 2, 54 * 2, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�븻Ŀ��_HIGH_STOP_UP", "image\\characters\\kirby\\�븻Ŀ��\\kirby_idle_�������_�ö󰥶�.bmp", 58 * 2, 54 * 2, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�븻Ŀ��_HIGH_STOP_DOWN", "image\\characters\\kirby\\�븻Ŀ��\\kirby_idle_�������_��������.bmp", 58 * 2, 54 * 2, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�븻Ŀ��_LOW_STOP_UP", "image\\characters\\kirby\\�븻Ŀ��\\kirby_idle_�������_�ö󰥶�.bmp", 58 * 2, 54 * 2, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�븻Ŀ��_LOW_STOP_DOWN", "image\\characters\\kirby\\�븻Ŀ��\\kirby_idle_�������_��������.bmp", 58 * 2, 54 * 2, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("�븻Ŀ��_SIT", "image\\characters\\kirby\\�븻Ŀ��\\kirby_down_����.bmp", 58, 54, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�븻Ŀ��_HIGH_SIT_UP", "image\\characters\\kirby\\�븻Ŀ��\\kirby_down_�������_�ö󰥶�.bmp", 58 * 2, 54 * 2, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�븻Ŀ��_HIGH_SIT_DOWN", "image\\characters\\kirby\\�븻Ŀ��\\kirby_down_�������_��������.bmp", 58 * 2, 54 * 2, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�븻Ŀ��_LOW_SIT_UP", "image\\characters\\kirby\\�븻Ŀ��\\kirby_down_�������_�ö󰥶�.bmp", 58 * 2, 54 * 2, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�븻Ŀ��_LOW_SIT_DOWN", "image\\characters\\kirby\\�븻Ŀ��\\kirby_down_�������_��������.bmp", 58 * 2, 54 * 2, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("�׶��ѳ븻Ŀ��_STOP", "image\\characters\\kirby\\�븻Ŀ��\\fat_kirby_idle_����.bmp", 58, 52, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�׶��ѳ븻Ŀ��_HIGH_STOP_UP", "image\\characters\\kirby\\�븻Ŀ��\\fat_kirby_idle_�������_�ö󰥶�.bmp", 58 * 2, 58 * 2, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�׶��ѳ븻Ŀ��_HIGH_STOP_DOWN", "image\\characters\\kirby\\�븻Ŀ��\\fat_kirby_idle_�������_��������.bmp", 58 * 2, 58 * 2, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�׶��ѳ븻Ŀ��_LOW_STOP_UP", "image\\characters\\kirby\\�븻Ŀ��\\fat_kirby_idle_�������_�ö󰥶�.bmp", 58 * 2, 52 * 2, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�׶��ѳ븻Ŀ��_LOW_STOP_DOWN", "image\\characters\\kirby\\�븻Ŀ��\\fat_kirby_idle_�������_��������.bmp", 58 * 2, 58 * 2, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("�븻Ŀ��_MOVE", "image\\characters\\kirby\\�븻Ŀ��\\kirby_walk.bmp", 270 * 2, 54 * 2, 10, 2, true, RGB(255, 0, 255));



	// KEYANIMANAGER�� Ű�� �߰�

	// �븻 Ŀ�� STOP ( LEFT / RIGHT ) 
	int arrNormalKirbyRightStop[] = { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int arrNormalKirbyLeftStop[] = { 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_RIGHT_STOP", "�븻Ŀ��_STOP", arrNormalKirbyRightStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_LEFT_STOP", "�븻Ŀ��_STOP", arrNormalKirbyLeftStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_RIGHT_HIGH_STOP_UP", "�븻Ŀ��_HIGH_STOP_UP", arrNormalKirbyRightStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_LEFT_HIGH_STOP_UP", "�븻Ŀ��_HIGH_STOP_UP", arrNormalKirbyLeftStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_RIGHT_HIGH_STOP_DOWN", "�븻Ŀ��_HIGH_STOP_DOWN", arrNormalKirbyRightStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_LEFT_HIGH_STOP_DOWN", "�븻Ŀ��_HIGH_STOP_DOWN", arrNormalKirbyLeftStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_RIGHT_LOW_STOP_UP", "�븻Ŀ��_LOW_STOP_UP", arrNormalKirbyRightStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_LEFT_LOW_STOP_UP", "�븻Ŀ��_LOW_STOP_UP", arrNormalKirbyLeftStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_RIGHT_LOW_STOP_DOWN", "�븻Ŀ��_LOW_STOP_DOWN", arrNormalKirbyRightStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_LEFT_LOW_STOP_DOWN", "�븻Ŀ��_LOW_STOP_DOWN", arrNormalKirbyLeftStop, 13, 6, true);

	// �׶��� �븻 Ŀ�� STOP ( LEFT / RIGHT ) 
	int arrFatNormalKirbyRightStop[] = { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int arrFatNormalKirbyLeftStop[] = { 3, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
	KEYANIMANAGER->addArrayFrameAnimation("�׶��ѳ븻Ŀ��_RIGHT_STOP", "�׶��ѳ븻Ŀ��_STOP", arrFatNormalKirbyRightStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�׶��ѳ븻Ŀ��_LEFT_STOP", "�׶��ѳ븻Ŀ��_STOP", arrFatNormalKirbyLeftStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�׶��ѳ븻Ŀ��_RIGHT_HIGH_STOP_UP", "�׶��ѳ븻Ŀ��_HIGH_STOP_UP", arrFatNormalKirbyRightStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�׶��ѳ븻Ŀ��_LEFT_HIGH_STOP_UP", "�׶��ѳ븻Ŀ��_HIGH_STOP_UP", arrFatNormalKirbyLeftStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�׶��ѳ븻Ŀ��_RIGHT_HIGH_STOP_DOWN", "�׶��ѳ븻Ŀ��_HIGH_STOP_DOWN", arrFatNormalKirbyRightStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�׶��ѳ븻Ŀ��_LEFT_HIGH_STOP_DOWN", "�׶��ѳ븻Ŀ��_HIGH_STOP_DOWN", arrFatNormalKirbyLeftStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�׶��ѳ븻Ŀ��_RIGHT_LOW_STOP_UP", "�׶��ѳ븻Ŀ��_LOW_STOP_UP", arrFatNormalKirbyRightStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�׶��ѳ븻Ŀ��_LEFT_LOW_STOP_UP", "�׶��ѳ븻Ŀ��_LOW_STOP_UP", arrFatNormalKirbyLeftStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�׶��ѳ븻Ŀ��_RIGHT_LOW_STOP_DOWN", "�׶��ѳ븻Ŀ��_LOW_STOP_DOWN", arrFatNormalKirbyRightStop, 13, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�׶��ѳ븻Ŀ��_LEFT_LOW_STOP_DOWN", "�׶��ѳ븻Ŀ��_LOW_STOP_DOWN", arrFatNormalKirbyLeftStop, 13, 6, true);
	
	// �븻 Ŀ�� SIT ( LEFT / RIGHT ) 
	int arrNormalKirbyRightSit[] = { 0, 1 };
	int arrNormalKirbyLeftSit[] = { 3, 2 };
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_RIGHT_SIT", "�븻Ŀ��_SIT", arrNormalKirbyRightSit, 2, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_LEFT_SIT", "�븻Ŀ��_SIT", arrNormalKirbyLeftSit, 2, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_RIGHT_HIGH_SIT_UP", "�븻Ŀ��_HIGH_SIT_UP", arrNormalKirbyRightSit, 2, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_LEFT_HIGH_SIT_UP", "�븻Ŀ��_HIGH_SIT_UP", arrNormalKirbyLeftSit, 2, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_RIGHT_HIGH_SIT_DOWN", "�븻Ŀ��_HIGH_SIT_DOWN", arrNormalKirbyRightSit, 2, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_LEFT_HIGH_SIT_DOWN", "�븻Ŀ��_HIGH_SIT_DOWN", arrNormalKirbyLeftSit, 2, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_RIGHT_LOW_SIT_UP", "�븻Ŀ��_LOW_SIT_UP", arrNormalKirbyRightSit, 2, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_LEFT_LOW_SIT_UP", "�븻Ŀ��_LOW_SIT_UP", arrNormalKirbyLeftSit, 2, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_RIGHT_LOW_SIT_DOWN", "�븻Ŀ��_LOW_SIT_DOWN", arrNormalKirbyRightSit, 2, 6, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_LEFT_LOW_SIT_DOWN", "�븻Ŀ��_LOW_SIT_DOWN", arrNormalKirbyLeftSit, 2, 6, true);

	// �븻 Ŀ�� MOVE ( LEFT / RIGHT )
	int arrNormalKirbyRightMove[] = { 0,1,2,3,4,5,6,7,8,9 };
	int arrNormalKirbyLeftMove[] = { 19,18,17,16,15,14,13,12,11,10 };
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_RIGHT_MOVE", "�븻Ŀ��_MOVE", arrNormalKirbyRightMove, 10, 9, true);
	KEYANIMANAGER->addArrayFrameAnimation("�븻Ŀ��_LEFT_MOVE", "�븻Ŀ��_MOVE", arrNormalKirbyLeftMove, 10, 9, true);


}