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
		HPEN red = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		PEN pen(hdc, red);

		HBRUSH tr = Application::GetInstance().GetBrush(eBushColor::Transparent);
		BRUSH brush(hdc, tr);

		Rectangle(hdc, mPos.x - mScale.x / 2, mPos.y - mScale.y / 2, mPos.x + mScale.x / 2, mPos.y + mScale.y / 2);
	}
}
