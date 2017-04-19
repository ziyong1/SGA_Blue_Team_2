#pragma once
#include "singletonBase.h"
#include <time.h>

//======================================
// ## 2017. 03. 01 ## randomFunction ##
//======================================

class randomFunction : public singletonBase < randomFunction >
{
public:
	randomFunction(void)
	{
		srand(GetTickCount());
	}
	~randomFunction(void)
	{

	}

	//int�� ������
	inline int getInt(int num) { return rand() % num; }
	//������ ������ ��������  ex) 50 ~ 100
	inline int getFromIntTo(int fromNum, int toNum) { return rand() % (toNum - fromNum + 1) + fromNum; }

	//float�� ���������� ��������� ����
	float getFloat() { return (float)rand() / (float)RAND_MAX; }
	float getFloat(float num) { return ((float)rand() / (float)RAND_MAX) * num; }
	float getFromFloatTo(float fromFloat, float toFloat)
	{
		float rnd = (float)rand() / (float)RAND_MAX;

		return (rnd * (toFloat - fromFloat) + fromFloat);
	}

};