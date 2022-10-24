#pragma once
#include "yaGameObject.h"
namespace ya
{
	class meteorManager : public GameObject
	{
	public:
		meteorManager();
		virtual ~meteorManager();

		virtual void Initialize()override;
		virtual void Tick()override;
		virtual void Render(HDC hdc)override;


	};
}

