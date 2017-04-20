//�������
#include "stdafx.h"
#include "mainGame.h"

//��������
HINSTANCE _hInstance;
HWND _hWnd;

//���콺 ����Ʈ ��
POINT _ptMouse;

mainGame _mg;

LPTSTR _lpszClass = TEXT("BLUE_API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void setWindowsSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int cmdShow)
{

	MSG message;		//������ �޽��� ���� ����ü
	WNDCLASS wndClass;	//������ ������ ���� ����ü

	_hInstance = hInstance;

	wndClass.cbClsExtra = 0;											//Ŭ���� ���� �޸�
	wndClass.cbWndExtra = 0;											//������ ���� �޸�
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		//������ ��׶��� ����
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//������ Ŀ�� ���
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);					//������ ������ ���
	wndClass.hInstance = hInstance;										//������ �ν��Ͻ�
	wndClass.lpfnWndProc = (WNDPROC)WndProc;							//���ν���
	wndClass.lpszClassName = WINNAME;								//Ŭ���� �̸�
	wndClass.lpszMenuName = NULL;										//�޴� �̸�
	wndClass.style = CS_HREDRAW | CS_VREDRAW;							//������ ��Ÿ��

																		//������ ������ ���
	RegisterClass(&wndClass);

	//������ â ����
	_hWnd = CreateWindow(
		WINNAME,				//������ Ŭ���� �̸�
		WINNAME,				//������ Ÿ��Ʋ �ٿ� �̸�
		WS_OVERLAPPEDWINDOW,	//������ ��Ÿ��
		WINSTARTX,				//������ â ���� X��ǥ
		WINSTARTY,				//������ â ���� Y��ǥ
		WINSIZEX,				//������ â ����ũ��
		WINSIZEY,				//������ â ����ũ��
		NULL,					//�θ� ������ ����
		(HMENU)NULL,			//�޴� �ڵ�
		hInstance,				//�ν��Ͻ� ������ ����
		NULL);

	setWindowsSize(WINSTARTX, WINSTARTY, 800, 600);


	//ȭ�鿡 ������ â�� �����ش�
	ShowWindow(_hWnd, cmdShow);

	//���ΰ��� �ʱ�ȭ ���и�
	if (FAILED(_mg.init()))
	{
		return 0; //������!
	}

	//���ӿ� ������ ���� ������ �� ��.
	while (true)
	{
		if (PeekMessage( &message, NULL, 0, 0, PM_REMOVE ))
		{
			if (message.message == WM_QUIT)break;
			TranslateMessage( &message );
			DispatchMessage( &message );
		}
		else
		{
			//             ���� �ڱⰡ 120�ϰ������ �ٲ�
			TIMEMANAGER->update(60.0f);
			_mg.update();
			_mg.render();
		}
	}
	
	

	/*
	//�޽��� ó�� ����
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);	//Ű���� �Է� �޽��� ó�� ���
		DispatchMessage(&message);//������ ������� �޽��� ó��
	}
	*/

	//�޽��� ���� �ٵ�������
	_mg.release(); //���ΰ��� ����
				   //������ ��ϵȰ� ����
	UnregisterClass(WINNAME, hInstance);

	return message.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return _mg.MainProc(hWnd, iMessage, wParam, lParam);
}

//Ŭ���̾�Ʈ ���� ������ �Լ�
void setWindowsSize(int x, int y, int width, int height)
{
	RECT winRect;

	winRect.left = 0;
	winRect.top = 0;
	winRect.right = width;
	winRect.bottom = height;

	//���۾� ������ ������ �۾� �������� ũ�⸸ ������.
	AdjustWindowRect(&winRect, WINSTYLE, false);

	SetWindowPos(_hWnd, NULL, x, y, (winRect.right - winRect.left),
		(winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);
}