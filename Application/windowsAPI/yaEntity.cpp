#include "yaEntity.h"
namespace ya
{
	Entity::Entity()
		:mName(L"")
		,mID((UINT32)this)	//�ּҰ��� �����ϴϱ� �ּҰ��� ����ȯ�ؼ� ���ڴ�
	{
	}
	Entity::~Entity()
	{
	}
}