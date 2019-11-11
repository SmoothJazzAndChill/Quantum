#include "../QuantumEngine.h"

namespace Quantum
{
	QuantumEngine::QuantumEngine()
	{
		Levels = std::shared_ptr<Quantum::LinkedList<std::shared_ptr<Quantum::Level>>>(new Quantum::LinkedList<std::shared_ptr<Quantum::Level>>());
		Systems = std::shared_ptr<std::vector<std::shared_ptr<System>>>(new std::vector<std::shared_ptr<System>>());
	}

	void QuantumEngine::Initialise()
	{
		UpdateSystem = std::shared_ptr<S_Update>(new S_Update());
		Systems->push_back(std::static_pointer_cast<S_Update>(UpdateSystem));
		Systems->push_back(std::shared_ptr<System>(new S_Renderer()));

		for (std::shared_ptr<System> System : *Systems)
		{
			System->AllSystems = Systems;
			System->CurrentLevel = CurrentLevel;
			System->Awake();
		}
	}

	void QuantumEngine::Start()
	{
		for (std::shared_ptr<System> System : *Systems)
		{
			System->Start();
		}
	}

	void QuantumEngine::Run()
	{
		UpdateSystem->Run();
	}
}