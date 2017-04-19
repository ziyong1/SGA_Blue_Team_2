#pragma once

class enemyManager;
class mapManager;

class kirbyBase;
class kirby
{
protected:
	enemyManager* _em;
	mapManager* _mm;

	kirbyBase* _currentKirby;

	float _cx;
	float _cy;

public:
	kirby();
	virtual ~kirby();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEmMemoryLink(enemyManager* em) { _em = em; }
	void setMmMemoryLink(mapManager* mm) { _mm = mm; }
};

