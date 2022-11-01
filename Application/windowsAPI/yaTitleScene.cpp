#include "yaTitleScene.h"
#include "yaResources.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaPlayerBackGround.h"

namespace ya
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		PlayerBackGround* bg = new PlayerBackGround;
		bg->Initialize();
		bg->SetImage(L"bg2", L"Logo.bmp");
		AddGameObject(bg, eColliderLayer::BackGround);

	}
	void TitleScene::Tick()
	{
		Scene::Tick();
		if (KEY_DOWN(N))
		{
			SceneManager::ChangeScene(eSceneType::Play);
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		//BitBlt(hdc, 0, 0,Application::GetInstance().GetWindowData().width, Application::GetInstance().GetWindowData().height, mImages->GetDC(), 0, 0, SRCCOPY);
		//TransparentBlt(hdc, 0, 0, 800, 600,
		//	mImages->GetDC(), 0, 0, mImages->GetWidth(), mImages->GetHeight(),
		//	RGB(255, 0, 255));

		wchar_t szFloat[50] = {};

		swprintf_s(szFloat, 50, L"TitleScene");
		int steLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, steLen);
	}
	void TitleScene::Enter()
	{
	}
	void TitleScene::Exit()
	{
	}
}


