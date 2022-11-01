#include "yaPlayScene.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaImage.h"
#include "yaPlayerBackGround.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
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
		PlayerBackGround* mb = new PlayerBackGround;

		AddGameObject(mbg, eColliderLayer::BackGround);
		AddGameObject(mb, eColliderLayer::BackGround);

		mbg->SetImage(L"1-11", L"11.bmp");
		mb->SetImage(L"1-1", L"1-1.bmp");
		AddGameObject(new Player, eColliderLayer::Player);
		AddGameObject(new Monster, eColliderLayer::Monster);
<<<<<<< HEAD


		CollisionManager::SetLayar(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayar(eColliderLayer::Player_Projecttile, eColliderLayer::Monster, true);
=======
>>>>>>> c1499e9a8f2a88c34360ca32ac75768ed0bcab38


		CollisionManager::SetLayar(eColliderLayer::Player, eColliderLayer::Monster, true);
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