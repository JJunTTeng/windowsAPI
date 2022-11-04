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
		void CreateAnimation(const std::wstring& name, Image* image,Vector2 leftTop, Vector2  size, Vector2 offset, float coulumnLength, UINT spriteLeghth
							,float duration, bool bAffectedCamera = true);
		void Play(std::wstring& name, bool bLoop);
	public:
		Event mStartEvent;
		Event mompleteEvent;
		Event mEndEvent;

	private:
		Image* mImage;

	private:
		std::map<const std::wstring&, Animation*> mAnimations;
		Animation* mPlayAnimation;
		bool mLoop;
	};
}

