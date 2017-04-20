#pragma once
#include "gameNode.h"

class kirby;
class kirbyBase : public gameNode
{
protected:
	animation* _motion;
	kirby* _kirby;

	image* _image;

public:
	kirbyBase();
	virtual ~kirbyBase();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setMotion(string keyName);
	void setMotion();
	void initImage();

	inline void setKirbyMemoryLink(kirby* kirby) { _kirby = kirby; }



	
};

