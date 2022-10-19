#include "yaApplication.h"

namespace ya
{
	ya::Application ya::Application::mInstance;

	ya::Application::Application()
	{
		mWindowData.clear();
	}

	ya::Application::~Application()
	{
		ReleaseDC(mWindowData.hWnd, mWindowData.hdc);
	}

	void ya::Application::Initalize(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);
	}

	void ya::Application::Tick()
	{
	}
}
