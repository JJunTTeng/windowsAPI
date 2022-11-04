#include "yaPlayer.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaMissile.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaCamera.h"
namespace ya
{
	Player::Player()
		: mSpeed(0.01f)
		, mImage(nullptr)
	{
		SetName(L"Player");

		SetPos(Vector2{ 100,700 });
		SetScales(Vector2{ 3.0f,3.0f });

		if (mImage == nullptr)
		{
			//mImage = Resources::Load<Image>(L"mario", L"..\\Resources\\Images\\BigMario\\ClimbFront.bmp");
			mImage = Resources::Load<Image>(L"mario", L"..\\Resources\\Images\\BigMario\\Idle.bmp");

			//Resources<Image>::Load(L"mario", L"..\\Resources\\Images\\mario.bmp");
		}
		AddComponent(new Animator);
		AddComponent(new Collider);

		
		Camera::SetTarget(this);
	}
	Player::~Player()
	{
	}
	void Player::Tick()
	{
		GameObject::Tick();
		Vector2 pos = GetPos();
		//pos = Camera::CalculatePos(pos);
		if (KEY_PREESE(UP))
		{
			pos.y -= 300.0f * Time::DeltaTime();
			
		}
		if (KEY_PREESE(DOWN))
		{
			pos.y += 300.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(LEFT))
		{
			pos.x -= 300.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(RIGHT))
		{
			pos.x += 300.0f * Time::DeltaTime();
		}
		if (KEY_DOWN(A))
		{
			Missile* missile = new Missile();

			Scene* playScene = SceneManager::GetPlayScene();

			playScene->AddGameObject(missile,eColliderLayer::Player_Projecttile);
			missile->SetPos(GetPos());


			missile->SetPos(GetPos());
			missile->SetPos(Vector2(GetPos().x + (mImage->GetWidth()), GetPos().y + (mImage->GetHeight() / 2) - missile->GetScale().y / 2));

		}

		SetPos(pos);
	}
	void Player::Render(HDC hdc)
	{
		//Vector2 pos = Camera::CalculatePos(GetPos());
		//Vector2 Scale = GetScale();

		//HPEN mPen = CreatePen(PS_SOLID, 1, RGB(51, 0, 153));
		//PEN pen(hdc, mPen);

		//HBRUSH mBrush = CreateSolidBrush(RGB(153, 102, 204));
		//BRUSH brush(hdc, mBrush);

		////Rectangle(hdc, pos.x, pos.y, pos.x + Scale.x, pos.y + Scale.y);



		////ũ�⺯�� x
		////BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetDC(), 0, 0, SRCCOPY);

		//Vector2 finalPos;
		//finalPos.x = (pos.x - mImage->GetWidth() * (Scale.x / 2.0f));
		//finalPos.y = (pos.y - mImage->GetHeight() * (Scale.y / 2.0f));

		//Vector2 rect;
		//rect.x = mImage->GetWidth() * Scale.x;
		//rect.y = mImage->GetHeight() * Scale.y;

		////TransparentBlt(hdc, finalPos.x, finalPos.y,rect.x,rect.y,
		////	mImage->GetDC(), 0, 0,mImage->GetWidth(), mImage->GetHeight(), 
		////	RGB(0, 116, 116));

		//		TransparentBlt(hdc, finalPos.x, finalPos.y,rect.x,rect.y,
		//	mImage->GetDC(), 0, 0,mImage->GetWidth(), mImage->GetHeight(), 
		//	RGB(147, 187,236));
		GameObject::Render(hdc);
	}
	void Player::OnCollisionEnter(Collider* other)
	{
	}
	void Player::OnCollisionStay(Collider* other)
	{
	}
	void Player::OnCollisionExit(Collider* other)
	{
	}
}