#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaCollisionManager.h"
#include "yaCamera.h"

namespace ya
{
	//ya::Application ya::Application::mInstance;


	void ya::Application::Initalize(WindowData data)
	{
		IntializeWIndow(data);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initalize();
		Camera::Initialize();
	}

	void ya::Application::Tick()
	{
		Time::Tick();
		Input::Tick();
		Camera::Tick();


		SceneManager::Tick();
		CollisionManager::Tick();


		//clear
		BRUSH brush(mWindowData.backBuffer, mBrush[(UINT)eBushColor::Gray]);
		Rectangle(mWindowData.backBuffer, -1, -1, mWindowData.width+1, mWindowData.height+1);


		SceneManager::Render(mWindowData.backBuffer);
		Input::Render(mWindowData.backBuffer);
		Time::Render(mWindowData.backBuffer);

		//�̹��� ȭ�鿡 ������ִ� �Լ�
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
		ReleaseDC(mWindowData.hWnd, mWindowData.backBuffer);
		Resources::Release();

	}
	void Application::IntializeWIndow(WindowData data)
	{

		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);

		//��Ʈ�� �ػ󵵸� �����ϱ����� ���� ������ ũ�� ���
		RECT rect = { 0,0,mWindowData.width,mWindowData.height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		//������ ũ�� ����
		SetWindowPos(mWindowData.hWnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);

		ShowWindow(mWindowData.hWnd, true);

		mWindowData.backTexture = CreateCompatibleBitmap(mWindowData.hdc, mWindowData.width, mWindowData.height);
		mWindowData.backBuffer = CreateCompatibleDC(mWindowData.hdc);

		//���Ӱ� �׷��ֱ��� ȭ�� �����ִ� �۾�
		HBITMAP dafaultBitmap = (HBITMAP)SelectObject(mWindowData.backBuffer, mWindowData.backTexture);

		DeleteObject(dafaultBitmap);


		mPen[(UINT)ePenColor::Red] = CreatePen(BS_SOLID, 1, RGB(255, 0, 0));
		mPen[(UINT)ePenColor::Blue] = CreatePen(BS_SOLID, 1, RGB(0, 0, 255));
		mPen[(UINT)ePenColor::Green] = CreatePen(BS_SOLID, 1, RGB(0, 255, 0));

		mBrush[(UINT)eBushColor::Transparent] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
		mBrush[(UINT)eBushColor::Black] = (HBRUSH)GetStockObject(BLACK_BRUSH);
		mBrush[(UINT)eBushColor::Gray] = CreateSolidBrush(RGB(71, 71, 71));
		mBrush[(UINT)eBushColor::WHITE] = (HBRUSH)GetStockObject(WHITE_BRUSH);


	}
}
