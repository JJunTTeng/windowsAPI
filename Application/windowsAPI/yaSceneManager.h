#pragma once
#include "Common.h"

namespace ya
{
	class Scene;
	class SceneManager
	{
	public:
		static void Initalize();
		static void Tick();
		static void Render(HDC hdc);
		static void Release();

		static Scene* GetPlayScene() { return mPlayScene; }

	private:
		static Scene* mScenes[(UINT)eSceneType::MAX];
		static Scene* mPlayScene;
		

	};
}
