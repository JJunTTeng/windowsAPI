#include "yaAnimation.h"
#include "yaImage.h"
#include "yaAnimator.h"
#include "yaGameObject.h"
#include "yaCamera.h"
#include "yaTime.h"
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
        if (mbComplete)
            return;

        mTime += Time::DeltaTime();
        if (mSpriteSheet[mSpriteIndex].duration < mTime)
        {
            mTime = 0.0f;
            if (mSpriteSheet.size() <= mSpriteIndex + 1)
                mbComplete = true;
            
            else
                mSpriteIndex++;     
        }
    }
    void Animation::Render(HDC hdc)
    {
        GameObject* GameObj = mAnimator->GetOwner();
        Vector2 pos = GameObj->GetPos();

        if (mAffectedCamera)
            pos = Camera::CalculatePos(pos);

        //BLENDFUNCTION func = {};
        //func.BlendOp = AC_SRC_OVER;
        //func.BlendFlags = 0;
        //func.AlphaFormat = 0;
        //func.SourceConstantAlpha = 255;

        pos += mSpriteSheet[mSpriteIndex].offset;

        //AlphaBlend(hdc,
        //  (int) pos.x - mSpriteSheet[mSpriteIndex].size.x / 2.0f,
        //  (int) pos.y - mSpriteSheet[mSpriteIndex].size.y / 2.0f,
        //  (int) mSpriteSheet[mSpriteIndex].size.x,
        //  (int) mSpriteSheet[mSpriteIndex].size.y,
        //        mImage->GetDC(),
        //  (int) mSpriteSheet[mSpriteIndex].leftTop.x,
        //  (int) mSpriteSheet[mSpriteIndex].leftTop.y , 
        //  (int) mSpriteSheet[mSpriteIndex].size.x,
        //  (int) mSpriteSheet[mSpriteIndex].size.y, 
        //   func);

        TransparentBlt(hdc,
            (int)pos.x - mSpriteSheet[mSpriteIndex].size.x / 2.0f,
            (int)pos.y - mSpriteSheet[mSpriteIndex].size.y / 2.0f,
            (int)mSpriteSheet[mSpriteIndex].size.x * 2.0f,
            (int)mSpriteSheet[mSpriteIndex].size.y * 2.0f,
            mImage->GetDC(),
            (int)mSpriteSheet[mSpriteIndex].leftTop.x,
            (int)mSpriteSheet[mSpriteIndex].leftTop.y,
            (int)mSpriteSheet[mSpriteIndex].size.x,
            (int)mSpriteSheet[mSpriteIndex].size.y,
            RGB(0, 116, 116));
            //(int)mSpriteSheet[mSpriteIndex].size.x,
            //(int)mSpriteSheet[mSpriteIndex].size.y,
            //func
    }
    void Animation::Create(Image* image, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLeghth,
        float duration, bool bAffectedCamera)
    {
        mImage = image;
        mAffectedCamera = bAffectedCamera;

        for (size_t i = 0; i < spriteLeghth; i++)
        {
            Sprite sprite;
            sprite.leftTop.x = leftTop.x + (size.x * (float)i);
            sprite.leftTop.y = leftTop.y;
            sprite.size = size;
            sprite.offset = offset;
            sprite.duration = duration;

            mSpriteSheet.push_back(sprite);
        }
    }
    void Animation::Reset()
    {
        mSpriteIndex = 0;
        mTime = 0.0f;
        mbComplete = false;
    }
}