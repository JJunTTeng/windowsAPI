#include "yaMissile.h"
#include "yaTime.h"
#include "yaCollider.h"
#include "yaGameObject.h"

namespace ya
{
	Missile::Missile()
		:mSpeed(1.0f)
	{
		SetPos({ 100.0f,100.0f });
		SetScales({ 20.0f,20.0f });

		Collider* col = new Collider;
		Vector2 colpos = col->GetPos();
		col->SetScale(Vector2(20.0f, 20.0f));
		AddComponent(col);
	}
	Missile::~Missile()
	{
	}
	void Missile::Tick()
	{
		Vector2 pos = GetPos();
		
		pos.x += 1000.0f * Time::DeltaTime();

		SetPos(pos);

		GameObject::Tick();
	}
	void Missile::Render(HDC hdc)
	{
		Vector2 Pos = GetPos();
		Vector2 Scale = GetScale();

		Ellipse(hdc, Pos.x, Pos.y , Pos.x + +Scale.x, Pos.y + Scale.y);

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