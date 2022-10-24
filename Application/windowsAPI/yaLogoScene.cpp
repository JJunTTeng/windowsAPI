#include "yaLogoScene.h"
#include "yaPlayer.h"
#include "yaMissile.h"
#include "yameteorManager.h"
#include "yameteor.h"
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
		AddGameObject(new Player());
		for (int i = 0; i < 200; i++)
		{
			meteor* Mmeteor = new meteor;
			AddGameObject(Mmeteor);
		}
	}
	void LogoScene::Tick()
	{
		Scene::Tick();
	}
	void LogoScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

	}
}