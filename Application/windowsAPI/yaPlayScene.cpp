#include "yaPlayScene.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaImage.h"
#include "yaPlayerBackGround.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
#include "yaObject.h"
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
		mbg->SetImage(L"1-BbackGround", L"BbackGround.bmp");
		mb->SetImage(L"1-1", L"1-1.bmp");

		ya::object::Instantiate<Player>(eColliderLayer::Player);
		mons[0] = ya::object::Instantiate<Monster>(Vector2{500,700}, eColliderLayer::Monster);
		mons[1] = ya::object::Instantiate<Monster>(Vector2{ 800,700 }, eColliderLayer::Monster);


		//AddGameObject(new Player, eColliderLayer::Player);
		//AddGameObject(new Monster, eColliderLayer::Monster);

		CollisionManager::SetLayar(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayar(eColliderLayer::Player_Projecttile, eColliderLayer::Monster, true);
	}
	void PlayScene::Tick()
	{
		Scene::Tick();
		if (KEY_DOWN(N))
		{
			SceneManager::ChangeScene(eSceneType::End);
		}

		if (KEY_DOWN(P))
		{
			ya::object::Destroy(mons[0]);
		}

		ya::object::Destroy(mons[0], 3.0f);

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