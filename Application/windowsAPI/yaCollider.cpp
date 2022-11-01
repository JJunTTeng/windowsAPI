#include "yaCollider.h"
#include "yaGameObject.h"
#include "yaApplication.h"
namespace ya
{
	Collider::Collider()
		:Component(eComponentType::Collider)
		, mOffset(Vector2::Zero)
		, mPos(Vector2::Zero)
		, mScale(Vector2::one)
		, mCollisionCount(0)
	{
		mScale = Vector2(100.0f, 100.0f);
	}
	Collider::~Collider()
	{
	}
	void Collider::Tick()
	{
		GameObject* owner = GetOwner();
		mPos = owner->GetPos() + mOffset;
	}
	void Collider::Render(HDC hdc)
	{
		HBRUSH tr = Application::GetInstance().GetBrush(eBushColor::Transparent);
		BRUSH brush(hdc, tr);

		HPEN green = CreatePen(PS_SOLID, 1, RGB(0,255, 0));
		HPEN red = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN oldPen;

		if (mCollisionCount > 0)
			oldPen = (HPEN)SelectObject(hdc, red);
		else
			oldPen = (HPEN)SelectObject(hdc, green);

		Rectangle(hdc, mPos.x - mScale.x / 2, mPos.y - mScale.y / 2, mPos.x + mScale.x / 2, mPos.y + mScale.y / 2);

		SelectObject(hdc, oldPen);
		DeleteObject(green);
		DeleteObject(red);

	}
	void Collider::OnCollisionEnter(Collider* other)
	{
		mCollisionCount++;

		GetOwner()->OnCollisionEnter(other);
	}
	void Collider::OnCollisionStay(Collider* other)
	{
		GetOwner()->OnCollisionStay(other);

	}
	void Collider::OnCollisionExit(Collider* other)
	{
		GetOwner()->OnCollisionExit(other);

		mCollisionCount--;
	}
}
