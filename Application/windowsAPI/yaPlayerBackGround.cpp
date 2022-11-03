#include "yaPlayerBackGround.h"
#include "yaResources.h"
#include "yaImage.h"
#include "yaCamera.h"
namespace ya
{
	PlayerBackGround::PlayerBackGround()
		:image(nullptr)
	{
		SetPos(Vector2::Zero);
		SetScales(Vector2::one);
	}
	PlayerBackGround::~PlayerBackGround()
	{
	}
	void PlayerBackGround::Initialize()
	{

	}
	void PlayerBackGround::Tick()
	{
		GameObject::Tick();
	}
	void PlayerBackGround::Render(HDC hdc)
	{

		SetScales(Vector2(2.0f, 2.0f));

		Vector2 pos = GetPos();
		Vector2 Scale = GetScale();


		//Vector2 finalPos;
		//finalPos.x = (pos.x - image->GetWidth() * (Scale.x / 2.0f));
		//finalPos.y = (pos.y - image->GetHeight() * (Scale.y / 2.0f));

		Vector2 rect;
		rect.x = image->GetWidth() * Scale.x;
		rect.y = image->GetHeight() * Scale.y;

	//	finalPos = Camera::CalculatePos(finalPos);
		//TransparentBlt(hdc, 0, 0, rect.x, rect.y,
		//	image->GetDC(), 0, 0, image->GetWidth(), image->GetHeight(),
		//	RGB(147, 187, 236));

		Vector2 finalPos = Vector2::Zero;
	/*	finalPos.x = image->GetWidth() * (Scale.x / 2.0f);
		finalPos.y = image->GetHeight() * (Scale.y / 2.0f);*/

		finalPos = Camera::CalculatePos(finalPos);

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x  , rect.y ,
			image->GetDC(), 0, 0, image->GetWidth(), image->GetHeight(),
			RGB(248, 0, 248));

		//TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y,
		//	mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight(),
		//	RGB(147, 187, 236));
		GameObject::Render(hdc);



	}
	void PlayerBackGround::SetImage(const std::wstring& key, const std::wstring& name)
	{
		std::wstring path;
		path = L"..\\Resources\\Images\\";
		path += name;
		image = Resources::Load<Image>(key, path);
	}
}
