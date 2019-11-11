#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "Object.h"

namespace Quantum
{
	class Level : public Object
	{
	public:
		Quantum::LinkedList<std::shared_ptr<Entity>> Entities;
	};
}

#endif //!LEVEL_H