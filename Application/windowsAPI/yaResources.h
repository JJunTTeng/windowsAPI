#pragma once
#include"Common.h"
#include "yaResource.h"
namespace ya
{

	
	class Resources
	{
	public:

		typedef std::map<std::wstring, Resource*>::iterator ResourceIter;		//왼쪽 자료형을 오른쪽으로 바꿔주겠다

		template <typename T>
		static void insert(const std::wstring& key, T* resource)
		{
			if (resource == nullptr || key == L"")
				return;

			mResources.insert(std::make_pair(key, resource));
		}
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			ResourceIter iter = mResources.find(key);

			// 리소스가 이미 map안에 존재한다
			if (iter != mResources.end())
			{
				return dynamic_cast<T*>(iter->second);
			}

			return nullptr;
		}
		template <typename T>
		static T* Load(const std::wstring& key,const std::wstring& path)
		{
			T* resource = Find<T>(key);
			//해당 키로 이미 로딩된게 있으면 리소스를 반환
			if (resource != nullptr)
			{
				return resource;
			}

			// 리소스가 없다
			resource = new T();

			if (FAILED(resource->Load(path)))
			{
				MessageBox(nullptr, L"Image Load Failed!!!", L"Error", MB_OK);
				return nullptr;
			}
		
			resource->SetKey(key);
			resource->SetPath(path);

			mResources.insert(std::make_pair(key, resource));

			return dynamic_cast<T*>(resource);
		}

		static void Release()
		{
			ResourceIter iter = mResources.begin();
			for (;iter != mResources.end(); ++iter)
			{
				if (iter->second == nullptr)
					continue;

				
				delete (iter->second);
				iter->second = nullptr;
			}
		}
	private:

		 static std::map<std::wstring, Resource*> mResources;
	};



}


