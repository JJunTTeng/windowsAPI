#include "yaMonster.h"
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
	Monster::Monster()
		: mSpeed(0.01f)
	{
		SetName(L"Monster");

		SetPos(Vector2{ 500,100 });
		SetScales(Vector2{ 3.0f,3.0f });

		if (mImage == nullptr)
		{
			//mImage = Resources::Load<Image>(L"mario", L"..\\Resources\\Images\\BigMario\\ClimbFront.bmp");
			mImage = Resources::Load<Image>(L"firemario", L"..\\Resources\\Images\\FireMario\\Idle.bmp");

			//Resources<Image>::Load(L"mario", L"..\\Resources\\Images\\mario.bmp");
		}

		AddComponent(new Animator);
		AddComponent(new Collider);
	}
	Monster::~Monster()
	{
	}
	void Monster::Tick()
	{
		GameObject::Tick();
		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void Monster::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 Scale = GetScale();

		Vector2 finalPos;
		finalPos.x = (pos.x - mImage->GetWidth() * (Scale.x / 2.0f));
		finalPos.y = (pos.y - mImage->GetHeight() * (Scale.y / 2.0f));

		Vector2 rect;
		rect.x = mImage->GetWidth() * Scale.x;
		rect.y = mImage->GetHeight() * Scale.y;

		finalPos = Camera::CalculatePos(finalPos);

		/*TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight(),
			RGB(0, 116, 116));*/

			TransparentBlt(hdc, finalPos.x, finalPos.y,rect.x,rect.y,
		mImage->GetDC(), 0, 0,mImage->GetWidth(), mImage->GetHeight(), 
		RGB(147, 187,236));
		GameObject::Render(hdc);
	}

	void Monster::OnCollisionEnter(Collider* other)
	{
	}
	void Monster::OnCollisionStay(Collider* other)
	{
	}
	void Monster::OnCollisionExit(Collider* other)
	{
	}

}