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

	PEN(HDC hdc, HPEN pen)
		:mHDC(hdc),
		mPen(pen),
		oldPen(NULL)
	{		
		oldPen = (HPEN)SelectObject(hdc, pen);
	}
	~PEN()
	{
		SelectObject(mHDC, oldPen);
		DeleteObject(mPen);
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
