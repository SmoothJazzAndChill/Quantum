#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include "QuantumArchitecture.h"

class System : public Object
{
	virtual void Awake() = 0;
	virtual void Start() = 0;

	void ConnectInterface(Interface I)
	{

	}
};

#endif //!SYSTEM_H