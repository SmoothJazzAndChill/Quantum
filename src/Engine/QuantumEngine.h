#pragma once
#ifndef QUANTUM_ENGINE_H
#define QUANTUM_ENGINE_H

#include "../API/QuantumAPI.h"

class QuantumEngine
{
	AssetLoader Loader;

	std::shared_ptr<Level> CurrentLevel;
	std::vector<std::shared_ptr<Level>> Levels;

	// Initialise
	void Initialise() {}

	// Load Required Assets
	void Load() {}
};


#endif //!QUANTUM_ENGINE_H
