#include "yameteor.h"
#include "yaTime.h"

namespace ya
{
	meteor::meteor()
	{
			//srand((float)time(NULL));
		SetSpeed(rand() % 1500);
		SetPos(Vector2{ 0.0f + rand() % 1920, 0.0f - rand() % 3000 });
		SetScales(Vector2{ 30,30 });
	}
	meteor::~meteor()
	{
	}
	void meteor::Tick()
	{
		Vector2 pos = GetPos();

		pos.y += GetSpeed() * Time::DeltaTime();
		if (pos.y >= 1500.0f)
		{
			SetSpeed(rand() % 1500);
			pos.y -= 2000.0f;
		}

		SetPos(pos);

	}
	void meteor::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 Scale = GetScale();

		HPEN mPen = CreatePen(PS_SOLID, 1, RGB(rand() % 256, rand() % 256, rand() % 256));
		PEN pen(hdc, mPen);

		HBRUSH mBrush = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
		BRUSH brush(hdc,mBrush);

		Rectangle(hdc, pos.x, pos.y, pos.x + Scale.x, pos.y + Scale.y);

	}
}