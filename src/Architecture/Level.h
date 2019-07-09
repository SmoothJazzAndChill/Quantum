#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "QuantumArchitecture.h"

class Level : public Object
{
	std::vector<std::shared_ptr<Entity>> Entities;
};

#endif //!LEVEL_H