#include "yaEntity.h"
namespace ya
{
	Entity::Entity()
		:mName(L"")
		,mID((UINT32)this)	//주소값이 랜덤하니까 주소값을 형변환해서 쓰겠다
	{
	}
	Entity::~Entity()
	{
	}
}