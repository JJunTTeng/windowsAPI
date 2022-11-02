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
					//�浹 �� �Ǿ����� �ȵǾ������� �˻������ ��.
					LayerCollision(playScene, (eColliderLayer)row, (eColliderLayer)col);
				}
			}
		}
	}
	void CollisionManager::SetLayar(eColliderLayer left, eColliderLayer right, bool value)
	{
		//�� ���� ���ڸ� ������ �� ū���ڸ� ����
		UINT row = 0;	//��
		UINT col = 0;	//��

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
		//��� left ������Ʈ��� right ������Ʈ���� �����ͼ� ������� �Ѵ�.
		std::vector<GameObject*>& lefts = scene->GetGameObjects(left);
		std::vector<GameObject*>& rights = scene->GetGameObjects(right);

		//auto�� ���� ���� iterator �� �ʹ� ��ϱ� 
		for (auto leftObject : lefts)
		{
			Collider* leftColider = leftObject->GetComponent<Collider>();
			if (leftColider == nullptr)
				if (leftObject->GetComponent<Collider>() == nullptr)
					continue;

			for (auto rightObject : rights)
			{

				Collider* rightColider = rightObject->GetComponent<Collider>();


				if (rightColider == nullptr)
					if (rightObject->GetComponent<Collider>() == nullptr)
						continue;

				if (leftObject == rightObject)
					continue;

				ColliderCollision(leftColider, rightColider);

			}
		}
	}
	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		//�� �浹ü�� Layer ��ȣ�� �ϴ� Ȯ�����ش�
		ColliderID id;
		id.left = left->GetID();
		id.right = right->GetID();

		std::map<UINT64, bool>::iterator iter = mCollisionInformation.find(id.ID);

		//�浹������ ���ٸ� �浹������ �������ְڴ�.
		if (iter == mCollisionInformation.end())
		{
			mCollisionInformation.insert(std::make_pair(id.ID, false));
			iter = mCollisionInformation.find(id.ID);
		}

		if (Intersect(left, right))
		{
			//�浹������ ���� �浹�� �����߳�? �ƴϸ� �浹�� ��� ���� ���̿��� ���ǹ�
			
			

			if (iter->second == false)
			{
				//�浹�� �����ߴ�

				//�浹�Լ� ȣ��
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);

				iter->second = true;
			}

			else
			{
				//�浹 ���̴�
				//OnCliisionStay();
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}


		}
		else
		{
			//�浹 x
			if (iter->second)
			{
				//�浹�� ���� �����ϰڴ�

				//�浹�Լ� ȣ��
				//OnCliisionExit();

				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}
	}


	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		if (left->GetOwner()->IsDeath() || right->GetOwner()->IsDeath())
			return false;


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