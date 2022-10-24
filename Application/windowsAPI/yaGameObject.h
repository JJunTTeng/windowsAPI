#pragma once
#include "Common.h"
#include "yaEntity.h"

namespace ya
{
	class GameObject : public Entity	 
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }
		void SetScales(Vector2 Scale) { mScale = Scale; }
		Vector2 GetScale() { return mScale; }
		void SetSpeed(float Speed) { mSpeed = Speed; }
		float GetSpeed() { return mSpeed; }

	private:
		Vector2 mPos;
		Vector2 mScale;
		float mSpeed;

	};
}
