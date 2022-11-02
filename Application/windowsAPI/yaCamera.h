#pragma once
#include "Common.h"

namespace ya
{
	class Image;
	class GameObject;
	class Camera
	{
	public:
		static void Initialize();
		static void Tick();
		static void Render();
		static Vector2 CalculatePos(Vector2 pos) { return pos - mDistance; }
		static void SetTarget(GameObject* gameObj) { mTarget = gameObj; }

	private:
		Camera() = default;
		~Camera() = default;

	private:
		static Vector2 mResoulution;	//화면 해상도
		static Vector2 mLookPosition;	//맵에 총 크기에서 카메라가 바라볼 좌표
		static Vector2 mDistance;		//해상도 중심좌표와 현재 화면의 간격차
		static GameObject* mTarget;

		static eCameraEffect mEffect;
		static Image* mCutton; //검정색 이미지
		static float mAlphaTime;
		static float mCuttonAlpha;
		static float mEndTime;
	};
}

