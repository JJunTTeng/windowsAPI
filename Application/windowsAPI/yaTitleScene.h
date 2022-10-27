#pragma once
#include "yaScene.h"

namespace ya
{
	class Image;
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize()override;
		void Tick()override;
		void Render(HDC hdc)override;


	private:
		Image* mImages;
	};
}
