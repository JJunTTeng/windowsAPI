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

