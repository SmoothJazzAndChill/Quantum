#pragma once
#ifndef I_FIXEDUPDATE_H
#define I_FIXEDUPDATE_H

#include QuantumAPI
#include QuantumArchitecture

namespace Quantum
{
	class I_FixedUpdate : public Interface
	{
	public:
		virtual ~I_FixedUpdate() {};
		virtual void FixedUpdate() {};
	};
}

#endif //!I_FIXEDUPDATE_H