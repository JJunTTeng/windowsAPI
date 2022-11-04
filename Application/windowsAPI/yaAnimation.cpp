#include "yaAnimation.h"
#include "yaImage.h"
#include "yaAnimator.h"
#include "yaGameObject.h"
#include "yaCamera.h"
namespace ya
{
    Animation::Animation()
    {
    }
    Animation::~Animation()
    {
    }
    void Animation::Tick()
    {
    }
    void Animation::Render(HDC hdc)
    {
        GameObject* GameObj = mAnimator->GetOwner();
        Vector2 pos = GameObj->GetPos();

        if (mAffectedCamera)
            pos = Camera::CalculatePos(pos);

        BLENDFUNCTION func = {};
        func.BlendOp = AC_SRC_OVER;
        func.BlendFlags = 0;
        func.AlphaFormat = 0;
        func.SourceConstantAlpha = (BYTE)(255.0f * mCuttonAlpha);

        AlphaBlend(hdc,
          (int) pos.x - mSpriteSheet[mSpriteIndex].size.x / 2.0f,
          (int) pos.y - mSpriteSheet[mSpriteIndex].size.y / 2.0f,
          (int) mSpriteSheet[mSpriteIndex].size.x,
          (int) mSpriteSheet[mSpriteIndex].size.y,
                mImage->GetDC(),
          (int) mSpriteSheet[mSpriteIndex].leftTop.x,
          (int) mSpriteSheet[mSpriteIndex].leftTop.y , 
          (int) mSpriteSheet[mSpriteIndex].size.x,
          (int) mSpriteSheet[mSpriteIndex].size.y, 
           func);
    }
    void Animation::Create(Image* image, Vector2 leftTop, Vector2 size, Vector2 offset, float coulumnLength, UINT spriteLeghth,
        float duration, bool bAffectedCamera)
    {
        mImage = image;
        mAffectedCamera = bAffectedCamera;

        for (size_t i = 0; i < spriteLeghth; i++)
        {
            Sprite sprite;
            sprite.leftTop.x = leftTop.x + (coulumnLength * (float)i);
            sprite.leftTop.y = leftTop.y;
            sprite.size = size;
            sprite.offset = offset;
            sprite.duration = duration;

            mSpriteSheet.push_back(sprite);
        }
    }
    void Animation::Reset()
    {
    }
}