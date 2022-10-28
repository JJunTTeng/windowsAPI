#include "yaLogoScene.h"
#include "yaPlayer.h"
#include "yaMissile.h"
#include "yameteorManager.h"
#include "yameteor.h"
#include "yaPlayerBackGround.h"
#include "yaSceneManager.h"
#include "yaInput.h"
namespace ya
{
	LogoScene::LogoScene()
	{
	}
	LogoScene::~LogoScene()
	{
	}
	void LogoScene::Initialize()
	{
		PlayerBackGround* bg = new PlayerBackGround;
		bg->Initialize();
		bg->SetImage(L"bg1", L"Logo.bmp");
		AddGameObject(bg, eColliderLayer::BackGround);

	}
	void LogoScene::Tick()
	{
		Scene::Tick();

		if (KEY_DOWN(N))
		{
			SceneManager::ChangeScene(eSceneType::Title);
		}
	}
	void LogoScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] = {};

		swprintf_s(szFloat, 50, L"LogoScene");
		int steLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, steLen);

	}
	void LogoScene::Enter()
	{
	}
	void LogoScene::Exit()
	{
	}
}