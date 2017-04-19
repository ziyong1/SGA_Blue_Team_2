#pragma once
#include <vector>

class enemyBase;
class mapManager;

class enemyManager
{
protected:
	vector<enemyBase*> _vEnemy;
	mapManager* _mm;

public:
	enemyManager();
	virtual ~enemyManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void removeEnemy(int index);
	void addEnemy();

	void setEmMemoryLink(mapManager* mm) { _mm = mm; }
};

