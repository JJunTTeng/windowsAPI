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

//union ex) 내가 자료형 int를 선언하고 char 자료형 변수 4개를 선언했다 그러면 int (4byte) 자료형 안에 char (1byte) 자료형 변수 4개를 가치 공유하면서 쓰겠다 쉽게말해서 배열처럼 한꺼번에 또는 나눠 쓰겠다
union ColliderID
{
	struct
	{
		UINT32 left;
		UINT32 right;
	};
	UINT64 ID;
};
