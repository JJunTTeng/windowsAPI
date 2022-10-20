#include "yaPlayer.h"
namespace ya
{
	Player::Player()
		: mSpeed(0.01f)
	{
		SetPos(Vector2{ 100,100 });
		SetScales(Vector2{ 100,100 });
	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
		
	}
	void Player::Tick()
	{
		Vector2 pos = GetPos();

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			pos.y -= 0.01f;
			if (GetAsyncKeyState('a') & 0x8000)
			{
				pos.y -= mSpeed;
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			pos.y += 0.01f;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			pos.x -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			pos.x += 0.01f;
		}

		SetPos(pos);
	}
	void Player::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 Scale = GetScale();

		Rectangle(hdc, pos.x, pos.y, pos.x + Scale.x, pos.y + Scale.y);
	}
}