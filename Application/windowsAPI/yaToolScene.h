#pragma once
#include "yaScene.h"

namespace ya
{
	class Image;
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		void Initialize()override;
		void Tick()override;
		void Render(HDC hdc)override;

		virtual void Enter(); //�������� ���� ����������
		virtual void Exit();


	private:
		
	};
}


