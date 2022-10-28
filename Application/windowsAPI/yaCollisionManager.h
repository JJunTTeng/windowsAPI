#pragma once
#include "Common.h"
namespace ya
{
	class Collider;
	class Scene;
	class CollisionManager
	{
	public:
		static void Tick();
		static void SetLayar(eColliderLayer left, eColliderLayer right , bool value);
		static void LayerCollision(Scene* scene, eColliderLayer left, eColliderLayer right);
		static bool Intersect(Collider* left, Collider* right);
	private:
		static WORD mMatrix[_COLLIDER_LAYER];

	};
}
