#include "yaSceneManager.h"
#include "yaLogoScene.h"

namespace ya
{
	Scene* SceneManager::mScenes[(UINT)eSceneType::MAX];
	Scene* SceneManager::mPlayScene = nullptr;

	void SceneManager::Initalize()
	{
		//��� ������ �ʱ�ȭ
		mScenes[(UINT)eSceneType::Logo] = new LogoScene();
		mScenes[(UINT)eSceneType::Logo]->Initialize();

		mPlayScene = mScenes[(UINT)eSceneType::Logo];
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
