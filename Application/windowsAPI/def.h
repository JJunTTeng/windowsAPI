#pragma once
#define KEY_PREESE(KEY) ya::Input::GetKeyState(ya::eKeyCode::KEY) == ya::eKeyState::PRESSED
#define KEY_DOWN(KEY) ya::Input::GetKeyState(ya::eKeyCode::KEY) == ya::eKeyState::DOWN
#define KEY_UP(KEY) ya::Input::GetKeyState(ya::eKeyCode::KEY) == ya::eKeyState::UP

enum class eSceneType
{
	Title,
	Logo,
	Play,
	End,
	MAX
};

enum class ePenColor
{
	Red,
	Green,
	Blue,
	End
};

enum class eBushColor
{
	Transparent,
	Black,
	Gray,
	WHITE,
	End
};

enum class eComponentType
{
	Animator,
	Collider,
	Sound,
	End,
};

#define _COLLIDER_LAYER 16

enum class eColliderLayer
{
	Default,
	BackGround,
	Tile,
	Player,
	Player_Projecttile,
	Monster,
	Monster_Projecttile,


	UI = _COLLIDER_LAYER - 1,
	End = _COLLIDER_LAYER
};

enum class eCameraEffect
{
	FadeIn,
	FadeOut,
	None
};

//union ex) ���� �ڷ��� int�� �����ϰ� char �ڷ��� ���� 4���� �����ߴ� �׷��� int (4byte) �ڷ��� �ȿ� char (1byte) �ڷ��� ���� 4���� ��ġ �����ϸ鼭 ���ڴ� ���Ը��ؼ� �迭ó�� �Ѳ����� �Ǵ� ���� ���ڴ�
union ColliderID
{
	struct
	{
		UINT32 left;
		UINT32 right;
	};
	UINT64 ID;
};
