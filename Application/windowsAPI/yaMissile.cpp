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
		

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"misile", L"..\\Resources\\Images\\fire.bmp");
		}

		Animator* animator = new Animator;

		//animator->CreateAnimation(mImage,0,)
			
		animator->CreateAnimation(L"misile", mImage,
			Vector2(0.0f, 0.0f), Vector2(mImage->GetWidth() / 3, mImage->GetHeight()),
			Vector2(0.0f, 0.0f), 3,  0.1f, yaRGB(147, 187, 236));

		animator->Play(L"misile", true);
		
		AddComponent(col);
		AddComponent(animator);
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

		float radian = DegreeToRadian(180.0f);
		float degree = RadianToDegree(2 * PI);

		//float speed = 100.0f;
		Vector2 pos = GetPos();
		//Vector2 dir(1.0f, 0.0f);
		mDir = PI / 2.0f;
		
		//pos.x = speed * /*cosf(mDir) */ Time::DeltaTime();
		//pos.y -= speed * /*sinf(mDir) */ Time::DeltaTime();

		pos.x += 500.0f * Time::DeltaTime();
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