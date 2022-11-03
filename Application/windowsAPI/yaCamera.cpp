#include "yaCamera.h"
#include "yaApplication.h"
#include "yaGameObject.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaImage.h"
namespace ya
{
	 Vector2 Camera::mResoulution = Vector2::Zero;	//화면 해상도
	 Vector2 Camera::mLookPosition = Vector2::Zero;	//맵에 총 크기에서 카메라가 바라볼 좌표
	 Vector2 Camera::mDistance = Vector2::Zero;		//해상도 중심좌표와 현재 화면의 간격차
	 GameObject* Camera::mTarget = nullptr;

	  eCameraEffect Camera::mEffect = eCameraEffect::None;
	  Image* Camera::mCutton = nullptr; //검정색 이미지
	  float Camera::mAlphaTime = 0.0f;
	  float Camera::mCuttonAlpha = 0.0f;
	  float Camera::mEndTime = 5.0f;

	void Camera::Initialize()
	{
		WindowData data = Application::GetInstance().GetWindowData();

		mResoulution = Vector2(data.width, data.height);
		mLookPosition = mResoulution / 2.0f;

		mEffect = eCameraEffect::FadeIn;
 		mCutton = Image::Create(L"CameraCutton",1920,1080);


	}
	void Camera::Tick()
	{
		if (mAlphaTime <= mEndTime)
		{
			mAlphaTime += Time::DeltaTime();

			//알파값 계산
			float ratio = (mAlphaTime / mEndTime);

			if (eCameraEffect::FadeIn == mEffect)
			{
				mCuttonAlpha = 1.0f - ratio;
			}

			else if (eCameraEffect::FadeOut == mEffect)
			{
				mCuttonAlpha = ratio;
			}


		}


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
	void Camera::Render(HDC hdc)
	{
		if (mCuttonAlpha <= 0.0f)
			return;

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = 0;
		func.SourceConstantAlpha = (BYTE)(255.0f * mCuttonAlpha);

		AlphaBlend(hdc, 0, 0, mCutton->GetWidth(), mCutton->GetHeight(), mCutton->GetDC(), 0, 0, mCutton->GetWidth(), mCutton->GetHeight(), func);

	}
}