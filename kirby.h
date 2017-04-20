#pragma once

class enemyManager;
class mapManager;

class kirbyBase;


enum STATE
{

	// ������ ���� ��

	// ����
	LEFT_STOP,
	RIGHT_STOP,
	// ���� ����
	LEFT_LOW_STOP_UP,
	RIGHT_LOW_STOP_UP,
	LEFT_LOW_STOP_DOWN,
	RIGHT_LOW_STOP_DOWN,
	// ���� ����
	LEFT_HIGH_STOP_UP,
	RIGHT_HIGH_STOP_UP,
	LEFT_HIGH_STOP_DOWN,
	RIGHT_HIGH_STOP_DOWN,

	// �ɾ��� ��

	// ����
	LEFT_SIT,
	RIGHT_SIT,
	// ���� ����
	LEFT_LOW_SIT_DOWN,
	RIGHT_LOW_SIT_DOWN,
	LEFT_LOW_SIT_UP,
	RIGHT_LOW_SIT_UP,
	// ���� ����
	LEFT_HIGH_SIT_DOWN,
	RIGHT_HIGH_SIT_DOWN,
	LEFT_HIGH_SIT_UP,
	RIGHT_HIGH_SIT_UP,


	// �̵�

	// ����
	LEFT_MOVE,
	RIGHT_MOVE,
	// ���� ����
	LEFT_LOW_MOVE,
	RIGHT_LOW_MOVE,
	// ���� ����
	LEFT_HIGH_MOVE,
	RIGHT_HIGH_MOVE,

	// �޸���
	LEFT_DASH,
	RIGHT_DASH,

	// ����

	// �ö󰥶�
	LEFT_FLY_UP,
	RIGHT_FLY_UP,
	// ��������
	LEFT_FLY_DOWN,
	RIGHT_FLY_DOWN,
	// ���� ������ ���� ��
	LEFT_FLY,
	RIGHT_FLY,


	// ����

	// ���� �ö󰥶� 
	LEFT_JUMP_UP,
	RIGHT_JUMP_UP,
	// ���� �߰�����
	LEFT_JUMP_TURN,
	RIGHT_JUMP_TURN,
	// ���� �������� 
	LEFT_JUMP_DOWN,
	RIGHT_JUMP_DOWN,

	// ��Ŭ
	LEFT_KICK,
	RIGHT_KICK,

	// ��Ű��
	LEFT_EAT,
	RIGHT_EAT,
	// �����
	LEFT_THROW,
	RIGHT_THROW,

	// �߶�
	LEFT_FALL,
	RIGHT_FALL,

	// ������ ��
	LEFT_ATTACK,
	RIGHT_ATTACK,

	// ���� ����
	LEFT_RETURN,
	RIGHT_RETURN,

	// �浹
	LEFT_CRASH,
	RIGHT_CRASH,

	// ����
	LEFT_SWIM,
	RIGHT_SWIM,


};

enum MODE
{

};

class kirby
{
protected:
	enemyManager* _em;
	mapManager* _mm;

	kirbyBase* _currentKirby;

	float _cx;
	float _cy;

	STATE _state;



public:
	kirby();
	virtual ~kirby();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void keyControl();

	inline STATE getState() { return _state; }

	inline void setEmMemoryLink(enemyManager* em) { _em = em; }
	inline void setMmMemoryLink(mapManager* mm) { _mm = mm; }
};

