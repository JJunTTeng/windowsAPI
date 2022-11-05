#include "yaAnimator.h"
#include "yaCamera.h"
#include "yaGameObject.h"
#include "yaImage.h"
#include "yaResources.h"

namespace ya
{
	Animator::Animator()
		:Component(eComponentType::Animator)
		, mPlayAnimation(nullptr)
		,mbLoop(false)
	{
		//mImage = Resources::Load<Image>(L"mario", L"..\\Resources\\Images\\BigMario\\Idle.bmp");
	}
	Animator::~Animator()
	{
	}
	void Animator::Tick()
	{
		if (mPlayAnimation != nullptr)
		{
			mPlayAnimation->Tick();

			if (mbLoop && mPlayAnimation->isComplete())
			{
				mCompleteEvent();
				mPlayAnimation->Reset();
			}
		}
	}
	void Animator::Render(HDC hdc)
	{
		if (mPlayAnimation != nullptr)
		{
			mPlayAnimation->Render(hdc);
		}
	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<const std::wstring, Animation*>::iterator iter = mAnimations.find(name);
		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}
	void Animator::CreateAnimation(const std::wstring& name, Image* image, Vector2 leftTop, Vector2 size, Vector2 offset,
		 UINT spriteLeghth, float duration, bool bAffectedCamera)	//568 48
	{
		Animation* animation = FindAnimation(name);
		if (animation != nullptr)
		{
			MessageBox(nullptr, L"중복 키 애니메이션 생성", L"이미지 애니메이션 실패!", MB_OK);
			return;
		}

		animation = new Animation();
		animation->Create(image, leftTop, size, offset,
			 spriteLeghth, duration, bAffectedCamera);
		
		animation->SetName(name);
		animation->SetAnimator(this);
		mAnimations.insert(std::make_pair(name, animation));
	}
	void Animator::Play(const std::wstring& name, bool bLoop)
	{
		mStartEvent();

		Animation* prevAnimation = mPlayAnimation;
		mPlayAnimation = FindAnimation(name);
		mPlayAnimation->Reset();
		mbLoop = bLoop;

		if (prevAnimation != mPlayAnimation)
		{
			mEndEvent();
		}
	}
}