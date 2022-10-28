#include "yaSceneManager.h"
#include "yaLogoScene.h"
#include "yaTitleScene.h"
#include "yaPlayScene.h"
#include "yaEndScene.h"

namespace ya
{
	Scene* SceneManager::mScenes[(UINT)eSceneType::MAX];
	Scene* SceneManager::mPlayScene = nullptr;
	
	void SceneManager::Initalize()
	{
		//��� ������ �ʱ�ȭ

		mScenes[(UINT)eSceneType::Logo] = new LogoScene();
		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		mScenes[(UINT)eSceneType::End] = new EndScene();

		for (int i = 0; i <= (UINT)eSceneType::End; i++)
		{
			if (mScenes[i] == nullptr)
				continue;

			mScenes[i]->Initialize();
		}



		ChangeScene(eSceneType::Play);
		//��ĳ����
		//�ٿ�ĳ����

	}
	void SceneManager::Tick()
	{
		//���� ���� ������Ʈ
		mPlayScene->Tick();
	}
	void SceneManager::Render(HDC hdc)
	{
		//���� ���� ����
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
	void SceneManager::ChangeScene(eSceneType type)
	{
		if (mPlayScene == nullptr)
		{
			mPlayScene = mScenes[(UINT)eSceneType::Play];
		}

		else
		{
			mPlayScene->Exit();
			mPlayScene = mScenes[(UINT)type];
		}

		mPlayScene->Enter();
	}
}
