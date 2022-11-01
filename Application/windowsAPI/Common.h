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

//라이브러리 추가하는법 2개 1. 설정에서 라이브러리 디렉터리 에서 추가해주는법 (내가 새로깐 라이브러리 추가하는법) 2. 윈도우 내부에 (우리한테는 안보인다) 그것중 안추가 되어있는 부분을 추가할때 

//typedef POINT Pos;

struct WindowData
{
	//랜더 타겟
	// 프레임 버퍼
	HWND hWnd;
	HDC hdc;
	HBITMAP backTexture;
	HDC backBuffer;	//복제 HDC
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
