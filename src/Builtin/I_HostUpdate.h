#pragma once
#ifndef I_HOSTUPDATE_H
#define I_HOSTUPDATE_H

#include QuantumAPI
#include QuantumArchitecture

namespace Quantum
{
	class I_HostUpdate : public Interface
	{
	public:
		void Update() {};
	};
}

#endif