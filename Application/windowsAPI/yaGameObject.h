#pragma once
#include "Common.h"
#include "yaEntity.h"
#include "yaComponent.h"

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

		void AddComponent(Component* component);

	private:
		std::vector<Component*> mComponents;
		Vector2 mPos;
		Vector2 mScale;
		float mSpeed;

	};
}
