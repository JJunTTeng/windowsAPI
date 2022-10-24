#include "yameteor.h"
#include "yaTime.h"

namespace ya
{
	meteor::meteor()
		:mSpeed(10.0f)
	{
			//srand((float)time(NULL));

			SetPos(Vector2{ 0.0f + rand() % 1920, 0.0f - rand() % 3000 });
			SetScales(Vector2{ 30,30 });
	}
	meteor::~meteor()
	{
	}
	void meteor::Tick()
	{
			Vector2 pos = GetPos();

			pos.y += (rand() % 1500) * Time::DeltaTime();
			if (pos.y >= 1500.0f)
				pos.y -= 2000.0f;

			SetPos(pos);

	}
	void meteor::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 Scale = GetScale();

		Rectangle(hdc, pos.x, pos.y, pos.x + Scale.x, pos.y + Scale.y);

	}
}