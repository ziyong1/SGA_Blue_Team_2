#include "stdafx.h"
#include "sceneManager.h"
#include "gameNode.h"


DWORD CALLBACK loadingThread(LPVOID prc)
{
	//��ü ��� ���� �� �ʱ�ȭ
	sceneManager::_readyScene->init();

	sceneManager::_currentScene = sceneManager::_readyScene;

	sceneManager::_loadingScene->release();
	sceneManager::_loadingScene = NULL;
	sceneManager::_readyScene = NULL;

	//��ȯ���� DWORD ���̶� ������ ��ȯ
	return 0;
}

gameNode* sceneManager::_currentScene = NULL;
gameNode* sceneManager::_loadingScene = NULL;
gameNode* sceneManager::_readyScene = NULL;

sceneManager::sceneManager()
{
}


sceneManager::~sceneManager()
{
}

HRESULT sceneManager::init()
{
	_currentScene = _loadingScene = _readyScene = NULL;
	_fadeIn = _fadeOut = false;
	_alpha = 255;

	_fadeIn_cbFunction = _fadeOut_cbFunction = NULL;
	_fadeOut_cbFunctionParameter = _fadeIn_cbFunctionParameter = NULL;
	_obj = NULL;

	return S_OK;
}

void sceneManager::release()
{
	mapSceneIter miSceneList = _mSceneList.begin();

	//�� ���� ���Ƽ�
	for (; miSceneList != _mSceneList.end();)
	{
		//���� �����Ѵٸ�
		if (miSceneList->second != NULL)
		{
			if (miSceneList->second == _currentScene) miSceneList->second->release();

			SAFE_DELETE(miSceneList->second);

			miSceneList = _mSceneList.erase(miSceneList);
		}
		else ++miSceneList;
	}

	_mSceneList.clear();
}

void sceneManager::update()
{
	if (_currentScene) _currentScene->update();

	if (_fadeIn)
	{
		_alpha -= 5;
		if (_alpha <= 0)
		{
			_alpha = 0;
			_fadeIn = false;
			if (_obj == NULL)
			{
				if (_fadeIn_cbFunction != NULL) _fadeIn_cbFunction();
				_fadeIn_cbFunction = NULL;
			}
			else
			{
				_fadeIn_cbFunctionParameter(_obj);
				_fadeIn_cbFunctionParameter = NULL;
				_obj = NULL;
			}
		}
	}
	if (_fadeOut)
	{
		_alpha += 5;
		if (_alpha >= 255)
		{
			_alpha = 255;
			_fadeOut = false;
			if (_obj == NULL)
			{
				if (_fadeOut_cbFunction != NULL) _fadeOut_cbFunction();
				_fadeOut_cbFunction = NULL;
			}
			else
			{
				_fadeOut_cbFunctionParameter(_obj);
				_fadeOut_cbFunctionParameter = NULL;
				_obj = NULL;
			}
		}
	}
}

void sceneManager::render()
{
	if (_currentScene) _currentScene->render();

	if (_fadeIn || _fadeOut)
	{
		IMAGEMANAGER->findImage("fade")->alphaRender(_currentScene->getMemDC(), _alpha);
	}
}

//�� �߰�
gameNode* sceneManager::addScene(string sceneName, gameNode* scene)
{
	//���� ���ٸ� �ΰ� ��ȯ
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}

//�ε� �� �߰�
gameNode* sceneManager::addLoadingScene(string loadingSceneName, gameNode* scene)
{
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(loadingSceneName, scene));

	return scene;
}

HRESULT sceneManager::changeScene(string sceneName)
{
	//���ͷ����ͷ� �ٲٰ��� �ϴ� ���� ã�´�
	mapSceneIter find = _mSceneList.find(sceneName);

	//���ٸ� FAIL
	if (find == _mSceneList.end()) return E_FAIL;
	//�ٲٷ��� ���� ������̸� S_OK
	if (find->second == _currentScene) return S_OK;

	//�� �ٲٴ°� �����ϸ�
	if (SUCCEEDED(find->second->init()))
	{
		if (_currentScene) _currentScene->release();
		//��ü�� ���� ������� �־��ش�
		_currentScene = find->second;

		return S_OK;
	}

	return E_FAIL;
}

HRESULT sceneManager::changeScene(string sceneName, string loadingSceneName)
{
	//���ͷ����ͷ� �ٲٰ��� �ϴ� ���� ã�´�
	mapSceneIter find = _mSceneList.find(sceneName);

	//���ٸ� FAIL
	if (find == _mSceneList.end()) return E_FAIL;
	//�ٲٷ��� ���� ������̸� S_OK
	if (find->second == _currentScene) return S_OK;
	//
	mapSceneIter findLoading = _mLoadingSceneList.find(loadingSceneName);

	if (find == _mLoadingSceneList.end()) return changeScene(loadingSceneName);

	//�� �ٲٴ°� �����ϸ�
	if (SUCCEEDED(find->second->init()))
	{
		if (_currentScene) _currentScene->release();

		_loadingScene = findLoading->second;

		_readyScene = find->second;
		
		CloseHandle(CreateThread(NULL, 0, loadingThread, NULL, 0, &_loadThreadID));
	}

	return E_FAIL;
}

void sceneManager::fadeIn(CALLBACK_FUNCTION cbFunction)
{
	if (_fadeIn || _fadeOut) return;
	_fadeIn_cbFunction = cbFunction;
	_fadeIn_cbFunctionParameter = NULL;
	_obj = NULL;
	_fadeIn = true;
	_alpha = 255;
}

void sceneManager::fadeOut(CALLBACK_FUNCTION cbFunction)
{
	if (_fadeIn || _fadeOut) return;
	_fadeOut_cbFunction = cbFunction;
	_fadeOut_cbFunctionParameter = NULL;
	_obj = NULL;
	_fadeOut = true;
	_alpha = 0;
}

void sceneManager::fadeIn(CALLBACK_FUNCTION_PARAMETER cbFunction, void * obj)
{
	if (_fadeIn || _fadeOut) return;
	_fadeIn_cbFunction = NULL;
	_fadeIn_cbFunctionParameter = cbFunction;
	_obj = obj;
	_fadeIn = true;
	_alpha = 255;
}

void sceneManager::fadeOut(CALLBACK_FUNCTION_PARAMETER cbFunction, void * obj)
{
	if (_fadeIn || _fadeOut) return;
	_fadeOut_cbFunction = NULL;
	_fadeOut_cbFunctionParameter = cbFunction;
	_obj = obj;
	_fadeOut = true;
	_alpha = 0;
}
