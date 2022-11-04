#pragma once
#include "Common.h"
#include "yaEntity.h"
#include "yaComponent.h"

namespace ya
{
	class Collider;
	class GameObject : public Entity	 
	{
	public:
		GameObject();
		GameObject(Vector2 position);
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }
		void SetScales(Vector2 Scale) { mScale = Scale; }
		Vector2 GetScale() { return mScale; }
		void SetSpeed(float Speed) { mSpeed = Speed; }
		float GetSpeed() { return mSpeed; }
		void Death() { mDead = true; }
		bool IsDeath() { return mDead; }
		void AddComponent(Component* component);
		void SetDeathTime(float time);


		template <typename T>
		__forceinline T* GetComponent()
 		{
			T* prev;
			for (Component* component : mComponents)
			{
				prev = dynamic_cast<T*>(component);
				
				if (prev != nullptr)
					return prev;
			}

			return nullptr;
		}

		void DeathLoop();

	private:
		std::vector<Component*> mComponents;
		Vector2 mPos;
		Vector2 mScale;
		float mSpeed;
		bool mDead;
		float mDeathTime;
		bool mDeathTimeOn;

		int hp;
	};
}
