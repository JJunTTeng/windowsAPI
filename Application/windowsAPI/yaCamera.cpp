#include "yaCamera.h"
#include "yaApplication.h"
#include "yaGameObject.h"
#include "yaInput.h"
#include "yaTime.h"
namespace ya
{
	 Vector2 Camera::mResoulution = Vector2::Zero;	//ȭ�� �ػ�
	 Vector2 Camera::mLookPosition = Vector2::Zero;	//�ʿ� �� ũ�⿡�� ī�޶� �ٶ� ��ǥ
	 Vector2 Camera::mDistance = Vector2::Zero;		//�ػ� �߽���ǥ�� ���� ȭ���� ������
	 GameObject* Camera::mTarget = nullptr;



	void Camera::Initialize()
	{
		WindowData data = Application::GetInstance().GetWindowData();

		mResoulution = Vector2(data.width, data.height);
		mLookPosition = mResoulution / 2.0f;

		mLookPosition.x += 50;
	}
	void Camera::Tick()
	{
		//Vector2 pos = Camera::CalculatePos(GetPos());
		//if (KEY_PREESE(W))
		//{
		//	mLookPosition.y -= 1200.0f * Time::DeltaTime();

		//}
		//if (KEY_PREESE(S))
		//{
		//	mLookPosition.y += 1200.0f * Time::DeltaTime();
		//}
		//if (KEY_PREESE(A))
		//{
		//	mLookPosition.x -= 1200.0f * Time::DeltaTime();
		//}
		//if (KEY_PREESE(D))
		//{
		//	mLookPosition.x += 1200.0f * Time::DeltaTime();
		//}

		if (mTarget != nullptr)
			mLookPosition = mTarget->GetPos();

		mDistance = mLookPosition - mResoulution / 2.0f;

	}
	void Camera::Render()
	{
	}
}