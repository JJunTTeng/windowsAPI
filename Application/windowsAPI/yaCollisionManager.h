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
<<<<<<< HEAD
		static void ColliderCollision(Collider* left, Collider* right);
		static bool Intersect(Collider* left, Collider* right);
	private:
		static WORD mMatrix[_COLLIDER_LAYER];
		static std::map<UINT64, bool> mCollisionInformation;
=======
		static bool Intersect(Collider* left, Collider* right);
	private:
		static WORD mMatrix[_COLLIDER_LAYER];

>>>>>>> c1499e9a8f2a88c34360ca32ac75768ed0bcab38
	};
}
