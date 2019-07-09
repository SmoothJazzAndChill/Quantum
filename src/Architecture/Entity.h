#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "QuantumArchitecture.h"

class Entity : public Object
{
	std::vector<std::shared_ptr<Component>> Components;

	template<typename T>
	void AddComponent()
	{

	}

	template<typename T>
	std::shared_ptr<Component> GetComponent()
	{

	}
};

#endif //!ENTITY_H