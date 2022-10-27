#include "yaSceneManager.h"
#include "yaLogoScene.h"
#include "yaTitleScene.h"

namespace ya
{
	Scene* SceneManager::mScenes[(UINT)eSceneType::MAX];
	Scene* SceneManager::mPlayScene = nullptr;
	
	void SceneManager::Initalize()
	{
		//��� ������ �ʱ�ȭ

		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Logo] = new LogoScene();

		for (int i = 0; i <= (UINT)eSceneType::Logo; i++)
		{
			mScenes[i]->Initialize();
		}



		mPlayScene = mScenes[(UINT)eSceneType::Title];
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
}
