#pragma once
#include "Common.h"
#include "yaEntity.h"
namespace ya
{
	class Animator;
	class Image;
	class Animation : public Entity
	{
	public:
		struct Sprite
		{
			Vector2 leftTop; //¡¬√¯ªÛ¥‹ Ω√¿€ ¡¬«•
			Vector2 size;   //¿ÃπÃ¡ˆ ≥–¿Ã
			Vector2 offset;
			float duration;
			yaRGB color;

			Sprite()
				: leftTop(0.0f, 0.0f)
				, size(0.0f, 0.0f)
				, offset(0.0f, 0.0f)
				, duration(0.0f)
			{

			}
		};

		Animation();
		~Animation();

		 void Tick() ;
		 void Render(HDC hdc) ;

		 void Create(Image* image, Vector2 leftTop, Vector2  size, Vector2 offset, UINT spriteLeghth
			 , float duration, bool bAffectedCamera = true);
		 void Create(Image* image, Vector2 leftTop, Vector2  size, Vector2 offset,  UINT spriteLeghth
			 , float duration, yaRGB COLOR, bool bAffectedCamera = true);

		 void Reset();
		 bool isComplete() { return mbComplete; }
		 void SetAnimator(Animator* animator) { mAnimator = animator; }
	private:
		Animator* mAnimator;
		Image* mImage;
		std::vector<Sprite> mSpriteSheet;
		UINT mSpriteIndex;
		float mTime;

		bool mbComplete;
		bool mStart;
		bool mEnd;
		bool mAffectedCamera;
	};


}

