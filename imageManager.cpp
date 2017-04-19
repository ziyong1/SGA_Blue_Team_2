#include "stdafx.h"
#include "imageManager.h"


imageManager::imageManager()
{
}


imageManager::~imageManager()
{
}

HRESULT imageManager::init(void)
{
	addImage("fade", WINSIZEX, WINSIZEY);

	return S_OK;
}

void imageManager::release(void)
{

}

//�� ��Ʈ�� �̹���
image* imageManager::addImage(string strKey, int width, int height)
{
	image* img = findImage(strKey);

	//�̹����� ������ �װ� �Ѱܶ�
	if (img) return img;

	img = new image;


	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	//make_pair(first, second) <- �˾Ƽ� ���� ã�Ƽ� �־��ش�
	//pair<��1, ��2>(��1, ��2)  <- ���� �������ְ� ��´�
	//pair�� �ֽ��? �Ҽ��ִµ� ���ͳ�, Ŭ�������� �ʹ� ���� ��ȣ�Ҷ� ��
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

//���ҽ� �̹���
image* imageManager::addImage(string strKey, const DWORD resID, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//�̹����� ������ �װ� �Ѱܶ�
	if (img) return img;

	img = new image;


	if (FAILED(img->init(resID, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	//make_pair(first, second) <- �˾Ƽ� ���� ã�Ƽ� �־��ش�
	//pair<��1, ��2>(��1, ��2)  <- ���� �������ְ� ��´�
	//pair�� �ֽ��? �Ҽ��ִµ� ���ͳ�, Ŭ�������� �ʹ� ���� ��ȣ�Ҷ� ��
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

//���� �̹���
image* imageManager::addImage(string strKey, const char* fileName, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//�̹����� ������ �װ� �Ѱܶ�
	if (img) return img;

	img = new image;


	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	//make_pair(first, second) <- �˾Ƽ� ���� ã�Ƽ� �־��ش�
	//pair<��1, ��2>(��1, ��2)  <- ���� �������ְ� ��´�
	//pair�� �ֽ��? �Ҽ��ִµ� ���ͳ�, Ŭ�������� �ʹ� ���� ��ȣ�Ҷ� ��
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

//���� �̹���
image* imageManager::addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//�̹����� ������ �װ� �Ѱܶ�
	if (img) return img;

	img = new image;


	if (FAILED(img->init(fileName, x, y, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	//make_pair(first, second) <- �˾Ƽ� ���� ã�Ƽ� �־��ش�
	//pair<��1, ��2>(��1, ��2)  <- ���� �������ְ� ��´�
	//pair�� �ֽ��? �Ҽ��ִµ� ���ͳ�, Ŭ�������� �ʹ� ���� ��ȣ�Ҷ� ��
	_mImageList.insert(make_pair(strKey, img));

	return img;
}


//������ �̹��� 
image* imageManager::addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//�̹����� ������ �װ� �Ѱܶ�
	if (img) return img;

	img = new image;


	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	//make_pair(first, second) <- �˾Ƽ� ���� ã�Ƽ� �־��ش�
	//pair<��1, ��2>(��1, ��2)  <- ���� �������ְ� ��´�
	//pair�� �ֽ��? �Ҽ��ִµ� ���ͳ�, Ŭ�������� �ʹ� ���� ��ȣ�Ҷ� ��
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//�̹����� ������ �װ� �Ѱܶ�
	if (img) return img;

	img = new image;


	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	//make_pair(first, second) <- �˾Ƽ� ���� ã�Ƽ� �־��ش�
	//pair<��1, ��2>(��1, ��2)  <- ���� �������ְ� ��´�
	//pair�� �ֽ��? �Ҽ��ִµ� ���ͳ�, Ŭ�������� �ʹ� ���� ��ȣ�Ҷ� ��
	_mImageList.insert(make_pair(strKey, img));

	return img;
}


//�̹��� ã�ƿ��� �Լ�
image* imageManager::findImage(string strKey)
{
	//�ʿ��� �ش� Ű�� ã�Ƽ� ���ͷ����Ϳ� �����Ѵ�
	mapImageIter key = _mImageList.find(strKey);

	//Ű���� ������
	if (key != _mImageList.end())
	{
		return key->second;
	}

	return NULL;
}


//�̹��� ��������
BOOL imageManager::deleteImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	//�ش� �̹����� ������
	if (key != _mImageList.end())
	{
		//ã�Ƽ� ������
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);

		return true;
	}

	return false;
}

//�̹��� ������ ����
BOOL imageManager::deleteAll(void)
{
	mapImageIter iter = _mImageList.begin();

	for (; iter != _mImageList.end();)
	{
		if (iter->second != NULL)
		{
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	_mImageList.clear();

	return TRUE;
}


void imageManager::render(string strKey, HDC hdc)
{
	image* img = findImage(strKey);

	if (img) img->render(hdc);
}

void imageManager::render(string strKey, HDC hdc, int destX, int destY)
{
	image* img = findImage(strKey);

	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	image* img = findImage(strKey);

	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}

void imageManager::alphaRender(string strKey, HDC hdc, BYTE alpha)
{
	image* img = findImage(strKey);

	if (img) img->alphaRender(hdc, alpha);
}

void imageManager::alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha)
{
	image* img = findImage(strKey);

	if (img) img->alphaRender(hdc, destX, destY, alpha);
}

void imageManager::alphaRender(string strkey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
	image* img = findImage(strkey);

	if (img) img->alphaRender(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight, alpha);
}
