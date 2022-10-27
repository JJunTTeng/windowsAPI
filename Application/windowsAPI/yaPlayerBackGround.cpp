#include "yaPlayerBackGround.h"
#include "yaResources.h"
#include "yaImage.h"
namespace ya
{
	PlayerBackGround::PlayerBackGround()
	{
		SetPos(Vector2(0, 0));
		mimages = Resources::Load<Image>(L"BG", L"..\\Resources\\Images\\11.bmp");
	}
	PlayerBackGround::~PlayerBackGround()
	{
	}
	void PlayerBackGround::Tick()
	{
	}
	void PlayerBackGround::Render(HDC hdc)
	{
		//BitBlt(hdc, GetPos().x, GetPos().y, mimages->GetWidth(), mimages->GetHeight(), mimages->GetDC(), 0, 0, SRCCOPY);

		TransparentBlt(hdc,0, 0, mimages->GetWidth(), mimages->GetHeight(),
			mimages->GetDC(), 0, 0, mimages->GetWidth(), mimages->GetHeight(),
			RGB(255, 0, 255));

	}
}
