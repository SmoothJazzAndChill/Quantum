#pragma once
#ifndef QUANTUM_ENGINE_H
#define QUANTUM_ENGINE_H

#include QuantumAPI
#include QuantumArchitecture

namespace Quantum
{
	class QuantumEngine
	{
	public:
		QuantumEngine();

		std::string AssetDirectory = "src/Assets";

		AssetLoader Loader;

		std::shared_ptr<Level> CurrentLevel;
		std::shared_ptr<LinkedList<std::shared_ptr<Level>>> Levels;

		std::shared_ptr<std::vector<std::shared_ptr<System>>> Systems;

		std::shared_ptr<S_Update> UpdateSystem;
		
		void Initialise();
		void Start();
		void Run();
	};
}


#endif //!QUANTUM_ENGINE_H
