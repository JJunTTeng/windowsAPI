#include "yaSceneManager.h"
#include "yaLogoScene.h"
#include "yaTitleScene.h"

namespace ya
{
	Scene* SceneManager::mScenes[(UINT)eSceneType::MAX];
	Scene* SceneManager::mPlayScene = nullptr;
	
	void SceneManager::Initalize()
	{
		//모든 씬들을 초기화

		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Logo] = new LogoScene();

		for (int i = 0; i <= (UINT)eSceneType::Logo; i++)
		{
			mScenes[i]->Initialize();
		}



		mPlayScene = mScenes[(UINT)eSceneType::Title];
		//업캐스팅
		//다운캐스팅

	}
	void SceneManager::Tick()
	{
		//현재 씬을 업데이트
		mPlayScene->Tick();
	}
	void SceneManager::Render(HDC hdc)
	{
		//현재 씬을 랜더
		mPlayScene->Render(hdc);
	}
	void SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			delete scene;
			scene = nullptr;
		}
	}
}
