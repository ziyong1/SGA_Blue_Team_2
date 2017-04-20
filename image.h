#pragma once
//======================================================
// 2017. 03. 07 ## image Class ##
//======================================================
#include "animation.h"

class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,		//���ҽ� ����
		LOAD_FILE,			//����
		LOAD_EMPTY,
		LOAD_END
	};

	typedef struct tagImageInfo
	{
		DWORD		resID;
		HDC			hMemDC;
		HBITMAP		hBit;
		HBITMAP		hOBit;
		float		x;
		float		y;
		int			width;
		int			height;
		int			currentFrameX;
		int			currentFrameY;
		int			maxFrameX;
		int			maxFrameY;
		int			frameWidth;
		int			frameHeight;
		BYTE		loadType;

		tagImageInfo()
		{
			resID			= 0;
			hMemDC			= NULL;
			hBit			= NULL;
			hOBit			= NULL;
			x				= 0;
			y				= 0;
			width			= 0;
			height			= 0;
			currentFrameX	= 0;
			currentFrameY	= 0;
			maxFrameX		= 0;
			maxFrameY		= 0;
			frameWidth		= 0;
			frameHeight		= 0;
			loadType		= LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;			//�̹��� ���� ����ü
	CHAR*			_fileName;			//�����̸�
	BOOL			_trans;				//Ư��Į�� �������� ����
	COLORREF		_transColor;		//Ư��Į�� ���۷���
	BOOL			_alpha;
	BOOL			_rotate;


	BLENDFUNCTION	_blendFunc;			//���ĺ��带 ���Ű���� ����
	LPIMAGE_INFO	_blendImage;		//���ĺ��带 ����ϱ� ���� �̹��� ����

	LPIMAGE_INFO _rotateImage; 
	
public:
	image();
	~image();


	HRESULT init(int width, int height);

	HRESULT init(const DWORD resID, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const char* fileName, float x, float y, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor);
	HRESULT init(const char* fileName, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor);

	void release(void);

	void setTransColor(BOOL trans, COLORREF transColor);
	void setAlphaBlend(BOOL alpha);
	void setRotate(BOOL rotate);

	//������ �Լ�        �Ѹ� ��X��ǥ, �Ѹ� �� Y��ǥ
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	void render(HDC hdc, int destX, int destY,int destWidth,int destHeight);

	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	void rotateRender(HDC hdc,float angle);
	void rotateRender(HDC hdc, int destX, int destY,float angle);

	void loopRender(HDC hdc, const LPRECT drawArea, int offSetX, int offSetY);

	void alphaLoopRender(HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha);

	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	void rotateFrameRender(HDC hdc, int destX, int destY,float angle);
	void rotateFrameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY,float angle);

	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	void rotateAlphaRender(HDC hdc, BYTE alpha,float angle);
	void rotateAlphaRender(HDC hdc, int destX, int destY, BYTE alpha,float angle);

	void alphaFrameRender(HDC hdc, int destX, int destY,BYTE alpha);
	void alphaFrameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha);

	void rotateAlphaFrameRender(HDC hdc, int destX, int destY, BYTE alpha,float angle);
	void rotateAlphaFrameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha,float angle);

	void aniRender(HDC hdc, int destX, int destY, animation* ani);

	void alphaAniRender(HDC hdc, int destX, int destY, animation* ani, BYTE alpha);

	void rotateAniRender(HDC hdc, int destX, int destY, animation* ani, float angle);

	void rotateAlphaAniRender(HDC hdc, int destX, int destY, animation* ani, BYTE alpha,float angle);

	inline HDC getMemDC(void) { return _imageInfo->hMemDC; }

	//======================================================
	// �����е��� �̹����� ���ϰ� ����Ű ���� ��Ÿ,��Ÿ
	//======================================================

	inline void setX(float x) { _imageInfo->x = x; }
	inline float getX() { return _imageInfo->x; }

	inline void setY(float y) { _imageInfo->y = y; }
	inline float getY() { return _imageInfo->y; }

	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	inline float getCenterX()
	{
		return _imageInfo->maxFrameX <= 0 ?
			_imageInfo->x + (_imageInfo->width / 2) :
			_imageInfo->x + (_imageInfo->frameWidth / 2);
	}

	inline float getCenterY()
	{
		return _imageInfo->maxFrameY <= 0 ?
			_imageInfo->y + (_imageInfo->height / 2) :
			_imageInfo->y + (_imageInfo->frameHeight / 2);
	
	}

	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;
		if (frameX > _imageInfo->maxFrameX) _imageInfo->currentFrameX = _imageInfo->maxFrameX;
	}

	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (frameY > _imageInfo->maxFrameY) _imageInfo->currentFrameY = _imageInfo->maxFrameY;
	}

	inline int getWidth(void) { return _imageInfo->width; }
	inline int getHeight(void) { return _imageInfo->height; }

	inline int getMaxFrameX(void) { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY(void) { return _imageInfo->maxFrameY; }

	inline int getFrameX(void) { return _imageInfo->currentFrameX; }
	inline int getFrameY(void) { return _imageInfo->currentFrameY; }

	inline int getFrameWidth(void) { return _imageInfo->frameWidth; }
	inline int getFrameHeight(void) { return _imageInfo->frameHeight; }

	inline BYTE getAlpha(void) { return _blendFunc.SourceConstantAlpha; }



};

