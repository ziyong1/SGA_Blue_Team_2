#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <tchar.h>

#include "randomFunction.h"
#include "commonMacroFunction.h"
#include "keyManager.h"
#include "imageManager.h"
#include "effectManager.h"
#include "soundManager.h"
#include "sceneManager.h"
#include "keyAniManager.h"
#include "timeManager.h"
#include "txtData.h"
#include "database.h"
#include "utils.h"

using namespace std;
using namespace BLUE_UTIL;

//====================================
// - 2017. 02. 28 ## �����ι� ##
//====================================

#define WINNAME (LPTSTR)(TEXT("BLUE Team"))
#define WINSTARTX 0
#define WINSTARTY 10
#define WINSIZEX 800	
#define WINSIZEY 800
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define KEYANIMANAGER keyAniManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define DATABASE database::getSingleton()

//======================================
// - 2017. 02. 28 ## ��ũ�� �Լ� ##
//======================================

#define SAFE_DELETE(p)			{if(p) { delete(p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) { delete[](p); (p) = NULL;}}
#define SAFE_RELEASE(p)			{if(p) { (p)->Release(); (p) = NULL;}}

//========================================
// - 2017. 02. 28 ## ���� ���� ##
//========================================

extern HWND _hWnd;
extern HINSTANCE _hInstance;

extern POINT _ptMouse;
extern BOOL _debug;
