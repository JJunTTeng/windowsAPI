#pragma once
#include "yaGameObject.h"
namespace ya
{
	class Image;
	class Monster : public GameObject
	{
	public:
		Monster();
		~Monster();

		virtual void Tick()override;
		virtual void Render(HDC hdc)override;

<<<<<<< HEAD

		virtual void OnCollisionEnter(Collider* other)override;
		virtual void OnCollisionStay(Collider* other)override;
		virtual void OnCollisionExit(Collider* other)override;

=======
>>>>>>> c1499e9a8f2a88c34360ca32ac75768ed0bcab38
	private:
		float mSpeed;
		Image* mImage;
	};

}