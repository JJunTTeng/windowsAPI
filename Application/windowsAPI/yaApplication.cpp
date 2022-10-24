#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{
	//ya::Application ya::Application::mInstance;


	void ya::Application::Initalize(WindowData data)
	{
		IntializeWindow(data);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initalize();
	}

	void ya::Application::Tick()
	{
		Time::Tick();
		Input::Tick();

		//clear
		Rectangle(mWindowData.backBuffer, -1, -1, mWindowData.width + 1, mWindowData.height + 1);
		SceneManager::Tick();

		Time::Render(mWindowData.backBuffer);
		Input::Render(mWindowData.backBuffer);
		SceneManager::Render(mWindowData.backBuffer);

		//이미지 화면에 출력해주는 함수
		BitBlt(mWindowData.hdc, 0, 0, mWindowData.width, mWindowData.height, mWindowData.backBuffer, 0, 0, SRCCOPY);
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

	void Application::IntializeWindow(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);

		//비트맵 해상도를 설정하기위한 실제 윈도우 크기 계산
		RECT rect = { 0,0,mWindowData.width,mWindowData.height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		//윈도우 크기 변경
		SetWindowPos(mWindowData.hWnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);

		ShowWindow(mWindowData.hWnd, true);

		mWindowData.backTexture = CreateCompatibleBitmap(mWindowData.hdc, mWindowData.width, mWindowData.height);
		mWindowData.backBuffer = CreateCompatibleDC(mWindowData.hdc);

		//새롭게 그려주기전 화면 지워주는 작업
		HBITMAP dafaultBitmap = (HBITMAP)SelectObject(mWindowData.backBuffer, mWindowData.backTexture);

		DeleteObject(dafaultBitmap);

	}
}



