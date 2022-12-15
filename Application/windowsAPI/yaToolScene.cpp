#include "yaToolScene.h"

namespace ya
{
	ToolScene::ToolScene()
	{
	}

	ToolScene::~ToolScene()
	{
	}

	void ToolScene::Initialize()
	{
	}

	void ToolScene::Tick()
	{
	}

	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] = {};

		swprintf_s(szFloat, 50, L"ToolScene");
		int steLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, steLen);
	}

	void ToolScene::Enter()
	{
	}

	void ToolScene::Exit()
	{
	}
}
