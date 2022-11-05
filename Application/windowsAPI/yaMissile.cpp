#include "yaMissile.h"
#include "yaTime.h"
#include "yaCollider.h"
#include "yaGameObject.h"
#include "yaCamera.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaImage.h"
namespace ya
{
	Missile::Missile()
		:mSpeed(1.0f)
		, mAilveTime(1.0f)
	{
		SetPos({ 100.0f,100.0f });
		SetScales({ 20.0f,20.0f });

		Collider* col = new Collider;
		Vector2 colpos = col->GetPos();
		col->SetScale(Vector2(20.0f, 20.0f));
		AddComponent(col);

		Animator* ani = new Animator;
		
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"misile", L"..\\Resources\\Images\\WingMario\\Idle2.bmp");
		}
		ani->CreateAnimation(L"Idle", mImage,
			Vector2(0.0f, 0.0f), Vector2(mImage->GetWidth() / 11, mImage->GetHeight()),
			Vector2(0.0f, 0.0f), 11, 0.1f);

		ani->Play(L"misile", true);
	}
	Missile::~Missile()
	{
	}
	void Missile::Tick()
	{
		GameObject::Tick();
		mAilveTime -= Time::DeltaTime();
		if (mAilveTime <= 0.0f)
		{
			this->Death();
		}

		Vector2 pos = GetPos();		
		pos.x += 1000.0f * Time::DeltaTime();
		SetPos(pos);

	}
	void Missile::Render(HDC hdc)
	{
		//Vector2 Pos = GetPos();
		//Vector2 Scale = GetScale();
		//Pos = Camera::CalculatePos(Pos);

		//Ellipse(hdc, Pos.x, Pos.y , Pos.x + +Scale.x, Pos.y + Scale.y);

		GameObject::Render(hdc);
	}
	void Missile::OnCollisionEnter(Collider* other)
	{
		GameObject* gmaeObj = other->GetOwner();
		this->Death();

		gmaeObj->Death();
	}
	void Missile::OnCollisionStay(Collider* other)
	{
	}
	void Missile::OnCollisionExit(Collider* other)
	{
	}
}