#pragma once
#include "yameteorManager.h"

namespace ya
{
	class meteor : public meteorManager
	{
	public:
		meteor();
		~meteor();

		void Tick()override;
		void Render(HDC hdc)override;


	private:
		float mSpeed;
	};
}

