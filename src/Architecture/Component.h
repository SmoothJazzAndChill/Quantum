#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

#include "Object.h"

namespace Quantum
{
	class Component : public Object
	{
	public:
		virtual ~Component() = 0;
	};
}

#endif //!COMPONENT_H