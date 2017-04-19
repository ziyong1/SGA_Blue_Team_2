#pragma once
#include <vector>

//===============================
// ## Animation ## 17.04.05 �ĸ���
//===============================

typedef void(*CALLBACK_FUNCTION)(void);
typedef void(*CALLBACK_FUNCTION_PARAMETER)(void*);

//void* ���̵� ������
//���� : �� ���� �� �ִ�.
//���� : ����Ҷ� ĳ������ �ݵ�� ������Ѵ�

class animation
{
public:
	//�����ӿ� ���������� �������Ϸ��� �ۺ�
	typedef vector<POINT> _vFrameList;
	typedef vector<int> _vPlayList;

private:
	int				_frameNum;

	_vFrameList		_frameList;
	_vPlayList		_playList;

	int				_frameWidth;
	int				_frameHeight;

	BOOL			_loop;

	float			_frameUpdateSec;
	float			_elapsedSec;

	DWORD			_nowPlayIdx;
	BOOL			_play;

	void* _obj;
	CALLBACK_FUNCTION _callbackFunction;
	CALLBACK_FUNCTION_PARAMETER _callbackFunctionParameter;

public:
	animation();
	~animation();

	HRESULT init(int totalW, int totalH, int frameW, int frameH);
	void release();
	//����Ʈ �ִϸ��̼�
	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);
	void setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	//�迭 �ִϸ��̼�
	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);
	void setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	//������� �ִϸ��̼�
	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);
	void setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	void setFPS(int framePerSec);

	void frameUpdate(float elapsedTime);

	void start(void);
	void stop(void);
	void pause(void);
	void resume(void);

	inline BOOL isPlay(void) { return _play; }

	inline POINT getFramePos(void) { return _frameList[_playList[_nowPlayIdx]]; }

	inline int getFrameWidth(void) { return _frameWidth; }
	inline int getFrameHeight(void) { return _frameHeight; }


};

