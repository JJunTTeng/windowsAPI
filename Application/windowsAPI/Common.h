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
	HWND hWnd;
	HDC hdc;
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
