#include "yaSceneManager.h"
#include "yaLogoScene.h"
#include "yaTitleScene.h"
#include "yaPlayScene.h"
#include "yaToolScene.h"
#include "yaEndScene.h"
#include "yaObject.h"

namespace ya
{
	Scene* SceneManager::mScenes[(UINT)eSceneType::MAX];
	Scene* SceneManager::mPlayScene = nullptr;
	
	void SceneManager::Initalize()
	{
		//모든 씬들을 초기화

		mScenes[(UINT)eSceneType::Logo] = new LogoScene();
		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		mScenes[(UINT)eSceneType::Tool] = new ToolScene();
		mScenes[(UINT)eSceneType::End] = new EndScene();
		


		for (UINT i = (UINT)eSceneType::Logo; i <= (UINT)eSceneType::End; i++)
		{
			if (mScenes[i] == nullptr)
				continue;

			mScenes[i]->Initialize();
		}

		ChangeScene(eSceneType::Play);

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
	void SceneManager::DestroyGameObject()
	{
		ya::object::Release();
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
	void SceneManager::ChangeScene(eSceneType type)
	{
		if (mScenes[(UINT)type] == nullptr)
			return;
		
			mPlayScene->Exit();
			mPlayScene = mScenes[(UINT)type];
		

		mPlayScene->Enter();
	}
}
