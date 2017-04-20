#pragma once

class enemyManager;
class mapManager;

class kirbyBase;


enum STATE
{

	// 가만히 있을 때

	// 평지
	LEFT_STOP,
	RIGHT_STOP,
	// 낮은 평지
	LEFT_LOW_STOP_UP,
	RIGHT_LOW_STOP_UP,
	LEFT_LOW_STOP_DOWN,
	RIGHT_LOW_STOP_DOWN,
	// 높은 평지
	LEFT_HIGH_STOP_UP,
	RIGHT_HIGH_STOP_UP,
	LEFT_HIGH_STOP_DOWN,
	RIGHT_HIGH_STOP_DOWN,

	// 앉았을 때

	// 평지
	LEFT_SIT,
	RIGHT_SIT,
	// 낮은 평지
	LEFT_LOW_SIT_DOWN,
	RIGHT_LOW_SIT_DOWN,
	LEFT_LOW_SIT_UP,
	RIGHT_LOW_SIT_UP,
	// 높은 평지
	LEFT_HIGH_SIT_DOWN,
	RIGHT_HIGH_SIT_DOWN,
	LEFT_HIGH_SIT_UP,
	RIGHT_HIGH_SIT_UP,


	// 이동

	// 평지
	LEFT_MOVE,
	RIGHT_MOVE,
	// 낮은 평지
	LEFT_LOW_MOVE,
	RIGHT_LOW_MOVE,
	// 높은 평지
	LEFT_HIGH_MOVE,
	RIGHT_HIGH_MOVE,

	// 달리기
	LEFT_DASH,
	RIGHT_DASH,

	// 날기

	// 올라갈때
	LEFT_FLY_UP,
	RIGHT_FLY_UP,
	// 내려갈때
	LEFT_FLY_DOWN,
	RIGHT_FLY_DOWN,
	// 땅에 가만히 있을 때
	LEFT_FLY,
	RIGHT_FLY,


	// 점프

	// 점프 올라갈때 
	LEFT_JUMP_UP,
	RIGHT_JUMP_UP,
	// 점프 중간지점
	LEFT_JUMP_TURN,
	RIGHT_JUMP_TURN,
	// 점프 내려갈때 
	LEFT_JUMP_DOWN,
	RIGHT_JUMP_DOWN,

	// 태클
	LEFT_KICK,
	RIGHT_KICK,

	// 삼키기
	LEFT_EAT,
	RIGHT_EAT,
	// 내뱉기
	LEFT_THROW,
	RIGHT_THROW,

	// 추락
	LEFT_FALL,
	RIGHT_FALL,

	// 공격할 때
	LEFT_ATTACK,
	RIGHT_ATTACK,

	// 변신 해제
	LEFT_RETURN,
	RIGHT_RETURN,

	// 충돌
	LEFT_CRASH,
	RIGHT_CRASH,

	// 수영
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

