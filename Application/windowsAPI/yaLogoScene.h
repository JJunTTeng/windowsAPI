#pragma once
#include "yaScene.h"

namespace ya
{

	class LogoScene : public Scene
	{
	public:
		LogoScene();
		~LogoScene();

		void Initialize()override;
		void Tick()override;
		void Render(HDC hdc)override;

		virtual void Enter(); //내씬으로 변경 됬을때마다
		virtual void Exit();
	private:
	};
}

