#include "yaApplication.h"
#include "yaSceneManager.h"

namespace ya
{
	//ya::Application ya::Application::mInstance;


	void ya::Application::Initalize(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd); 

		SceneManager::Initalize();
	}

	void ya::Application::Tick()
	{
		SceneManager::Tick();
		SceneManager::Render(mWindowData.hdc);
	}

	ya::Application::Application()
	{
		mWindowData.clear();
	}

	ya::Application::~Application()
	{
		SceneManager::Release();
		ReleaseDC(mWindowData.hWnd, mWindowData.hdc);
	}
}
