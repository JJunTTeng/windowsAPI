#include "yaCamera.h"
#include "yaApplication.h"
#include "yaGameObject.h"
#include "yaInput.h"
#include "yaTime.h"
namespace ya
{
	 Vector2 Camera::mResoulution = Vector2::Zero;	//화면 해상도
	 Vector2 Camera::mLookPosition = Vector2::Zero;	//맵에 총 크기에서 카메라가 바라볼 좌표
	 Vector2 Camera::mDistance = Vector2::Zero;		//해상도 중심좌표와 현재 화면의 간격차
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