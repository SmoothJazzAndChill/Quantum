#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "Object.h"

namespace Quantum
{
	class Entity : public Object
	{
	public:
		LinkedList<std::shared_ptr<Component>> Components;

		template<typename T>
		void AddComponent();
		
		template<typename T>
		std::shared_ptr<T> GetComponent();
	};
}

#include "Source/Entity.tpp"

#endif //!ENTITY_H