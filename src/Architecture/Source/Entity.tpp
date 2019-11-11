#pragma once

namespace Quantum
{
	template <typename T>
	void Entity::AddComponent()
	{
		if (GetComponent<T> == nullptr)
		{
			Components.PushBack(std::shared_ptr(new T()));
		}
	}

	template <typename T>
	std::shared_ptr<T> Entity::GetComponent()
	{
		auto CurrentComponent = Components.Head();

		do
		{
			if (dynamic_cast<T*>(CurrentComponent->Data.get()) != nullptr)
			{
				return std::shared_ptr<T>(dynamic_cast<T*>(CurrentComponent->Data.get()));
			}
		} while (CurrentComponent->Next != nullptr);

		return nullptr;
	}
}