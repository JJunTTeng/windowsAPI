#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{
	//ya::Application ya::Application::mInstance;


	void ya::Application::Initalize(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd); 

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initalize();
	}

	void ya::Application::Tick()
	{
		Time::Tick();
		Input::Tick();
		SceneManager::Tick();



		Time::Render(mWindowData.hdc);
		Input::Render(mWindowData.hdc);
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
