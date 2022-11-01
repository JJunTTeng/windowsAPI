#include "yaCollisionManager.h"
#include "yaScene.h"
#include "yaSceneManager.h"
#include "yaGameObject.h"
#include "yaCollider.h"
namespace ya
{
	WORD CollisionManager::mMatrix[_COLLIDER_LAYER] = {};
	std::map<UINT64, bool> CollisionManager::mCollisionInformation;

	void CollisionManager::Tick()
	{
		Scene* playScene = SceneManager::GetPlayScene();

		for (size_t row = 0; row < _COLLIDER_LAYER; row++)
		{
			for (size_t col = 0; col < _COLLIDER_LAYER; col++)
			{
				if (mMatrix[row] & (1 << col)) 
				{
					//충돌 이 되었는지 안되었는지를 검사해줘야 함.
					LayerCollision(playScene, (eColliderLayer)row, (eColliderLayer)col);
				}
			}
		}
	}
	void CollisionManager::SetLayar(eColliderLayer left, eColliderLayer right , bool value)
	{
		//더 작은 숫자를 행으로 더 큰숫자를 열로
		UINT row = 0;	//행
		UINT col = 0;	//열

		UINT iLeft = (UINT)left;
		UINT iRight = (UINT)right;

		if (iLeft < iRight)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		if (value == true)
			mMatrix[row] |= (1 << col);
		else
			mMatrix[row] &= ~(1 << col);

		
	}
	void CollisionManager::LayerCollision(Scene* scene, eColliderLayer left, eColliderLayer right)
	{
		//모든 left 오브젝트들과 right 오브젝트들을 가져와서 비교해줘야 한다.
		std::vector<GameObject*>& lefts = scene->GetGameObjects(left);
		std::vector<GameObject*>& rights = scene->GetGameObjects(right);

		//auto를 쓰는 이유 iterator 이 너무 기니까 
		for (auto leftObject : lefts)
		{
			Collider* leftColider = leftObject->GetComponent<Collider>();
			if (leftColider == nullptr)
				continue;

			for (auto rightObject : rights)
			{

				Collider* rightColider = rightObject->GetComponent<Collider>();


				if (rightColider == nullptr)
					continue;

				if (leftObject == rightObject)
					continue;

				ColliderCollision(leftColider, rightColider);

			}
		}
	}
	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		//두 충돌체의 Layer 번호를 일단 확인해준다
		ColliderID id;
		id.left = left->GetID();
		id.right = right->GetID();

		std::map<UINT64, bool>::iterator iter = mCollisionInformation.find(id.ID);

		//충돌정보가 없다면 충돌정보를 생성해주겠다.
		if (iter == mCollisionInformation.end())
		{
			mCollisionInformation.insert(std::make_pair(id.ID, false));
			iter = mCollisionInformation.find(id.ID);
		}

		if (Intersect(left, right))
		{
			//충돌했을때 이제 충돌을 시작했나? 아니면 충돌이 계속 진행 중이였나 조건문
			if (iter->second == false)
			{
				//충돌을 시작했다
				
				//충돌함수 호출
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);

				iter->second = true;
			}

			else
			{
				//충돌 중이다
				//OnCliisionStay();
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}


		}
		else
		{
			//충돌 x
			if (iter->second)
			{
				//충돌을 이제 종료하겠다

				//충돌함수 호출
				//OnCliisionExit();

				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}

	}
	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Vector2 leftPos = left->GetPos();
		Vector2 rightPos = right->GetPos();

		Vector2 leftScale = left->GetScale();
		Vector2 rightScale = right->GetScale();

		if (fabs(left->GetPos().x - right->GetPos().x) < (left->GetScale().x / 2.0f + right->GetScale().x / 2.0f) &&
			fabs(left->GetPos().y - right->GetPos().y) < (left->GetScale().y / 2.0f + right->GetScale().y / 2.0f))
		{
			return true;
		}

		return false;
	}
}