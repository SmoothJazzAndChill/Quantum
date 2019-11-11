#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include "Object.h"

namespace Quantum
{
	template<typename T>
	class InterfaceContainer
	{
	public:
		InterfaceContainer()
		{
			Data = std::shared_ptr<std::vector<std::shared_ptr<T>>>(new std::vector<std::shared_ptr<T>>);
		}

		std::shared_ptr<std::vector<std::shared_ptr<T>>> Data;
	};

	class System : public Object
	{
	public:
		virtual void Awake() {};
		virtual void Start() {};

		std::shared_ptr<Level> CurrentLevel;
		std::shared_ptr<std::vector<std::shared_ptr<System>>> AllSystems;
		
		template<typename T>
		void FetchComponents(LinkedList<std::shared_ptr<T>>* Container)
		{
			if (CurrentLevel == nullptr)
			{
				throw std::runtime_error("Missing level");
			}

			auto CurrentEntity = CurrentLevel->Entities.Head();

			do
			{
				std::shared_ptr<T> NewComponent = CurrentEntity->Data->GetComponent<T>();
				if (NewComponent != nullptr)
				{
					Container->PushBack(NewComponent);
				}
				CurrentEntity = CurrentEntity->Next;
			} while (CurrentEntity->Next != nullptr);
		}

		template<typename T>
		void ConnectInterface(InterfaceContainer<T>* Container)
		{
			for (std::shared_ptr<System> System : *AllSystems)
			{
				if (dynamic_cast<T*>(System.get()) != nullptr)
				{
					Container->Data->push_back(std::shared_ptr<T>(dynamic_cast<T*>(System.get())));
				}
			}
		}
	};
}

#endif //!SYSTEM_H