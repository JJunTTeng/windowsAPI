#pragma once
#include "Common.h"


namespace ya
{ 
	//∏ﬁ¿Œ «¡∑Œ±◊∑•¿Ã µ… ≥‡ºÆ  ΩÃ±€≈Ê
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
	};

}
