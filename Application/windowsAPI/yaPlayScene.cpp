#include "yaPlayScene.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaImage.h"
#include "yaPlayerBackGround.h"
namespace ya
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		PlayerBackGround* mbg = new PlayerBackGround;

		AddGameObject(mbg);

		mbg->SetImage(L"1-1", L"11.bmp");
		AddGameObject(new Player);

	}
	void PlayScene::Tick()
	{
		Scene::Tick();
		if (KEY_DOWN(N))
		{
			SceneManager::ChangeScene(eSceneType::End);
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] = {};

		swprintf_s(szFloat, 50, L"PlayScene");
		int steLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, steLen);
	}
	void PlayScene::Enter()
	{
	}
	void PlayScene::Exit()
	{
	}
}