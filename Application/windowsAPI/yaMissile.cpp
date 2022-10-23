#include "yaMissile.h"
#include "yaTime.h"

namespace ya
{
	Missile::Missile()
		:mSpeed(1.0f)
	{
		SetPos({ 100.0f,100.0f });
		SetScales({ 50.0f,50.0f });
	}
	Missile::~Missile()
	{
	}
	void Missile::Tick()
	{
		Vector2 pos = GetPos();

		pos.x += 1000.0f * Time::DeltaTime();

		SetPos(pos);
	}
	void Missile::Render(HDC hdc)
	{
		Vector2 Pos = GetPos();
		Vector2 Scale = GetScale();

		Ellipse(hdc, Pos.x, Pos.y , Pos.x + +Scale.x, Pos.y + Scale.y);
	}
}