#include "yaCollisionManager.h"
#include "yaScene.h"
#include "yaSceneManager.h"
#include "yaGameObject.h"
#include "yaCollider.h"
namespace ya
{
	WORD CollisionManager::mMatrix[_COLLIDER_LAYER] = {};
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
	void CollisionManager::SetLayar(eColliderLayer left, eColliderLayer right , bool value)
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
			if (leftObject->GetComponent<Collider>() == nullptr)
				continue;

			for (auto rightObject : rights)
			{
				if (rightObject->GetComponent<Collider>() == nullptr)
					continue;

				if (leftObject == rightObject)
					continue;

				if (Intersect(leftObject->GetComponent<Collider>(), rightObject->GetComponent<Collider>()))
				{
					//�浹
					int a = 0;
				}
				else
				{
					//�浹 x
				}
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