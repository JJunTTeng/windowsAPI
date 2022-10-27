#include "yaTitleScene.h"
#include "yaResources.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaApplication.h"
#include "yaSceneManager.h"

namespace ya
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		//L"..\\Resources\\Images\\

		mImages = Resources::Load<Image>(L"Title", L"..\\Resources\\Images\\mario3.bmp");


	}
	void TitleScene::Tick()
	{
		Scene::Tick();
		if (KEY_PREESE(SPACE))
		{
			SceneManager::SetPlayScene(eSceneType::Logo);
		}


	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		BitBlt(hdc, 0, 0,Application::GetInstance().GetWindowData().width, Application::GetInstance().GetWindowData().height, mImages->GetDC(), 0, 0, SRCCOPY);
		TransparentBlt(hdc, 0, 0, 800, 600,
			mImages->GetDC(), 0, 0, mImages->GetWidth(), mImages->GetHeight(),
			RGB(255, 0, 255));
	}
}


