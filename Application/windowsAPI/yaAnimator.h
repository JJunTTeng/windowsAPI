#pragma once
#include "yaComponent.h"
#include "yaAnimation.h"
namespace ya
{
	class Image;
	class Animator : public Component
	{
	public:

		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}


			void operator()()
			{
				if (mEvent)
					mEvent();
			}
			

			std::function<void()>mEvent;
		};
		Animator();
		~Animator();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		Animation* FindAnimation(const std::wstring& name);
		void CreateAnimation(const std::wstring& name, Image* image,Vector2 leftTop, Vector2  size, Vector2 offset,  UINT spriteLeghth
							,float duration, bool bAffectedCamera = true);
		void Play(const std::wstring& name, bool bLoop = false);
	public:
		Event mStartEvent;
		Event mCompleteEvent;
		Event mEndEvent;

	private:
		Image* mImage;

	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mPlayAnimation;
		bool mbLoop;
	};
}

