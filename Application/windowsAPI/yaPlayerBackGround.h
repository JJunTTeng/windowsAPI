#pragma once
#include "yaGameObject.h"
namespace ya
{
	class Image;
	class PlayerBackGround : public GameObject
	{

	public:
		PlayerBackGround();
		~PlayerBackGround();

		virtual void Tick()override;
		virtual void Render(HDC hdc)override;
		Image* GetBgImage() { return mimages; }
		void SetBgImage(Image* Image) { mimages = Image; }
	private:

		Image* mimages;
	};
}
