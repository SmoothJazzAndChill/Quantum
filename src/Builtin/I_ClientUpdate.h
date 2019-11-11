#pragma once
#ifndef I_UPDATECLIENT_H
#define I_UPDATECLIENT_H

#include QuantumAPI
#include QuantumArchitecture

namespace Quantum
{
	class I_ClientUpdate : public Interface
	{
	public:
		virtual ~I_ClientUpdate() {};
		virtual void Update() {};
	};
}

#endif