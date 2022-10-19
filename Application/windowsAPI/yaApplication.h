#pragma once
#include "Common.h"


namespace ya
{ 
	//���� ���α׷��� �� �༮  �̱���
	class Application
	{
	public:
		static Application& GetInstance()
		{
			return mInstance;
		}

		Application();
		~Application();

		void Initalize(WindowData data);
		void Tick();

	private:
		static Application mInstance;
		WindowData mWindowData;
	};

}
