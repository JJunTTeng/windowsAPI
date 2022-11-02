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
		static Vector2 mResoulution;	//ȭ�� �ػ�
		static Vector2 mLookPosition;	//�ʿ� �� ũ�⿡�� ī�޶� �ٶ� ��ǥ
		static Vector2 mDistance;		//�ػ� �߽���ǥ�� ���� ȭ���� ������
		static GameObject* mTarget;

		static eCameraEffect mEffect;
		static Image* mCutton; //������ �̹���
		static float mAlphaTime;
		static float mCuttonAlpha;
		static float mEndTime;
	};
}

