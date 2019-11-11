#pragma once
#ifndef C_TRANSFORM_H
#define C_TRANSFORM_H

#include QuantumAPI
#include QuantumArchitecture

namespace Quantum
{
	class C_Transform : public Component
	{
		Vector3 Position;
		Quaternion Rotation;
		Vector3 Scale;
	};
}


#endif // !C_TRANSFORM_H
