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
		virtual void Initialize()override;
		virtual void Tick()override;
		virtual void Render(HDC hdc)override;
		
		void SetImage(const std::wstring& key, const std::wstring& name);
	private:

		Image* image;
	};
}
