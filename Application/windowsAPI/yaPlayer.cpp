#include "yaPlayer.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaMissile.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaImage.h"
#include "yaResouces.h"
namespace ya
{
	Player::Player()
		: mSpeed(0.01f)
	{
		SetPos(Vector2{ 100,100 });
		SetScales(Vector2{ 50,50 });

		if (mImage == nullptr)
		{
			mImage = Resources<Image>::Load(L"mario", L"..\\Resources\\Images\\mario.bmp");
		//	Resources<Image>::Load(L"mario", L"..\\Resources\\Images\\mario.bmp");
		}
	}
	Player::~Player()
	{
	}
	void Player::Tick()
	{
		Vector2 pos = GetPos();
		
		if (KEY_PREESE(UP))
		{
			pos.y -= 1000.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(DOWN))
		{
			pos.y += 1000.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(LEFT))
		{
			pos.x -= 1000.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(RIGHT))
		{
			pos.x += 1000.0f * Time::DeltaTime();
		}
		if (KEY_DOWN(A))
		{
			Missile* missile = new Missile();

			Scene* playScene = SceneManager::GetPlayScene();

			playScene->AddGameObject(missile);
			missile->SetPos(GetPos());


			missile->SetPos(Vector2(GetPos().x + (mImage->GetWidth()), GetPos().y + (mImage->GetHeight() / 2) - missile->GetScale().y / 2));

		}

		SetPos(pos);
	}
	void Player::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 Scale = GetScale();

		HPEN mPen = CreatePen(PS_SOLID, 1, RGB(51, 0, 153));
		PEN pen(hdc, mPen);

		HBRUSH mBrush = CreateSolidBrush(RGB(153, 102, 204));
		BRUSH brush(hdc, mBrush);

		//Rectangle(hdc, pos.x, pos.y, pos.x + Scale.x, pos.y + Scale.y);


		

		BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetDC(), 0, 0, SRCCOPY);
	}
}