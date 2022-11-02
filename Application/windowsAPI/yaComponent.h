#pragma once
#include "yaEntity.h"
#include "Common.h"
#
namespace ya
{
	class GameObject;
	class Component : public Entity
	{
	public:
		friend class GameObject;	//게임오브젝트에서는 지금 이클래스를 퍼블릭처럼 써라
		Component(eComponentType type);
		Component() = delete;
		virtual ~Component();

		virtual void Tick();
		virtual void Render(HDC hdc);

		GameObject* GetOwner() { return mOwner; }

	private:
		const eComponentType mType;
		GameObject* mOwner;
	};
}
