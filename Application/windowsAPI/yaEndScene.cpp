#include "yaEndScene.h"
namespace ya
{
	EndScene::EndScene()
	{
	}
	EndScene::~EndScene()
	{
	}
	void EndScene::Initialize()
	{
	}
	void EndScene::Tick()
	{
	}
	void EndScene::Render(HDC hdc)
	{
		wchar_t szFloat[50] = {};

		swprintf_s(szFloat, 50, L"EndScene ");
		int steLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, steLen);
	}
	void EndScene::Enter()
	{
	}
	void EndScene::Exit()
	{
	}
}
