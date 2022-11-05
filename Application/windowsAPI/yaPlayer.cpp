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
		 //mImage[10](nullptr)
	{
		SetName(L"Player");

		SetPos(Vector2{ 100,700 });
		SetScales(Vector2{ 3.0f,3.0f });

		if (mImage[0] == nullptr)
		{
			//mImage = Resources::Load<Image>(L"mario", L"..\\Resources\\Images\\BigMario\\ClimbFront.bmp");
			//mImage = Resources::Load<Image>(L"mario", L"..\\Resources\\Images\\BigMario\\Idle.bmp");
			mImage[0] = Resources::Load<Image>(L"WingMario", L"..\\Resources\\Images\\WingMario\\Idle2.bmp");
			mImage[1] = Resources::Load<Image>(L"WingMario1", L"..\\Resources\\Images\\WingMario\\L\\Walk.bmp");
			mImage[2] = Resources::Load<Image>(L"WingMario2", L"..\\Resources\\Images\\WingMario\\R\\Walk.bmp");


			//Resources<Image>::Load(L"mario", L"..\\Resources\\Images\\mario.bmp");
		}
		
		mAnimator = new Animator();
		mAnimator->CreateAnimation(L"Idle", mImage[0],
			Vector2(0.0f,0.0f), Vector2(mImage[0]->GetWidth() / 11, mImage[0]->GetHeight()),
			Vector2(0.0f, 0.0f), 11, 0.1f);

		mAnimator->CreateAnimation(L"LWalk", mImage[1],
			Vector2(0.0f, 0.0f), Vector2(mImage[1]->GetWidth() / 18, mImage[1]->GetHeight()/2),
			Vector2(0.0f, 0.0f), 18, 0.1f);

		mAnimator->CreateAnimation(L"RWalk", mImage[2],
			Vector2(0.0f, 0.0f), Vector2(mImage[2]->GetWidth() / 18, mImage[2]->GetHeight()/2),
			Vector2(0.0f, 0.0f), 18, 0.1f);


		mAnimator->Play(L"Idle", true);

		mAnimator->mCompleteEvent = std::bind(&Player::WalkComplite, this);
			
			//0 116 116 , 1761 * 148 / 11 , 160.09

		AddComponent(mAnimator);
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


		if (KEY_DOWN(UP))
		{
			//pos.y -= 300.0f * Time::DeltaTime();

		}
		if (KEY_DOWN(DOWN))
		{
			//pos.y += 300.0f * Time::DeltaTime();

		}
		if (KEY_DOWN(LEFT))
		{
		//	pos.x -= 300.0f * Time::DeltaTime();
			mAnimator->Play(L"LWalk", true);
		}
		if (KEY_DOWN(RIGHT))
		{
			//pos.x += 300.0f * Time::DeltaTime();
			mAnimator->Play(L"RWalk", true);
		}


		if (KEY_DOWN(A))
		{
			Missile* missile = new Missile();

			Scene* playScene = SceneManager::GetPlayScene();

			playScene->AddGameObject(missile,eColliderLayer::Player_Projecttile);
			missile->SetPos(GetPos());


			missile->SetPos(GetPos());
			missile->SetPos(Vector2(GetPos().x + (mImage[0]->GetWidth()), GetPos().y + (mImage[0]->GetHeight() / 2) - missile->GetScale().y / 2));

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



		////크기변경 x
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
	void Player::WalkComplite()
	{
	}
}