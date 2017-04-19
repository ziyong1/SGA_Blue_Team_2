#pragma once
#include "singletonBase.h"
#include <string>
#include <map>

class gameNode;

using namespace std;

typedef void(*CALLBACK_FUNCTION)(void);
typedef void(*CALLBACK_FUNCTION_PARAMETER)(void*);

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*> mapSceneList;
	typedef map<string, gameNode*>::iterator mapSceneIter;

private:
	static gameNode* _currentScene;
	static gameNode* _loadingScene;
	static gameNode* _readyScene;

	mapSceneList _mSceneList;
	mapSceneList _mLoadingSceneList;

	DWORD _loadThreadID;
	bool _fadeIn;
	bool _fadeOut;
	int _alpha;

	CALLBACK_FUNCTION _fadeOut_cbFunction;
	CALLBACK_FUNCTION _fadeIn_cbFunction;
	CALLBACK_FUNCTION_PARAMETER _fadeOut_cbFunctionParameter;
	CALLBACK_FUNCTION_PARAMETER _fadeIn_cbFunctionParameter;
	void* _obj;

public:
	
	sceneManager();
	~sceneManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//�� �߰�
	gameNode* addScene(string sceneName, gameNode* scene);

	//�ε� �� �߰�
	gameNode* addLoadingScene(string loadingSceneName, gameNode* scene);

	HRESULT changeScene(string sceneName);
	HRESULT changeScene(string sceneName, string loadingSceneName);


	friend DWORD CALLBACK loadingThread(LPVOID prc);

	void fadeIn(CALLBACK_FUNCTION cbFunction);
	void fadeOut(CALLBACK_FUNCTION cbFunction);
	void fadeIn(CALLBACK_FUNCTION_PARAMETER cbFunction,void* obj);
	void fadeOut(CALLBACK_FUNCTION_PARAMETER cbFunction,void* obj);

};

