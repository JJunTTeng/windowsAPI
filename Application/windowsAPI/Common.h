#pragma once
#include "framework.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stdlib.h>
#include <time.h>
#include "def.h"

#include "Maths.h"

#pragma comment(lib,"msimg32.lib")

//���̺귯�� �߰��ϴ¹� 2�� 1. �������� ���̺귯�� ���͸� ���� �߰����ִ¹� (���� ���α� ���̺귯�� �߰��ϴ¹�) 2. ������ ���ο� (�츮���״� �Ⱥ��δ�) �װ��� ���߰� �Ǿ��ִ� �κ��� �߰��Ҷ� 

//typedef POINT Pos;

struct WindowData
{
	//���� Ÿ��
	// ������ ����
	HWND hWnd;
	HDC hdc;
	HBITMAP backTexture;
	HDC backBuffer;	//���� HDC
	UINT height;
	UINT width;

	void clear()
	{
		hWnd = nullptr;
		hdc = nullptr;
		height = 0;
		width = 0;
	}

	
};

struct PEN
{
	HPEN mPen;
	HPEN oldPen;
	HDC mHDC;

	PEN(HDC hdc)
		:mHDC(hdc),
		mPen(NULL),
		oldPen(NULL)
	{
	}

	PEN(HDC hdc, HPEN pen)
		:mHDC(hdc),
		mPen(pen),
		oldPen(NULL)
	{		
		oldPen = (HPEN)SelectObject(mHDC, pen);
	}
	~PEN()
	{
		SelectObject(mHDC, oldPen);
		DeleteObject(mPen);
	}

	void SetPen(HPEN pen)
	{
		oldPen = (HPEN)SelectObject(mHDC, pen);
	}
};

struct BRUSH
{
	HBRUSH mBrush;
	HBRUSH oldBrush;
	HDC mHDC;

	BRUSH(HDC hdc, HBRUSH Brush)
		:mHDC(hdc),
		mBrush(Brush),
		oldBrush(NULL)
	{
		oldBrush = (HBRUSH)SelectObject(hdc, Brush);
	}
	~BRUSH()
	{
		SelectObject(mHDC, oldBrush);
		DeleteObject(mBrush);
	}
};
