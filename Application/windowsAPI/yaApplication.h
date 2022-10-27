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
			static Application mInstance;
			return mInstance;
		}


		void Initalize(WindowData data);
		void Tick();
		WindowData GetWindowData() { return mWindowData; }


	private:
		Application();
		~Application();

		void IntializeWIndow(WindowData data);

	private:
		WindowData mWindowData;
		HPEN mPen[(UINT)ePenColor::End];
		HBRUSH mBrush[(UINT)eBushColor::End];

	};

}
