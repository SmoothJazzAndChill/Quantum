#pragma once
#ifndef C_CAMERA_H
#define C_CAMERA_H

#include QuantumAPI
#include QuantumArchitecture

namespace Quantum
{
	class C_Camera : public Component
	{
	public:
		bool Current;
		float FOV;
	};
}

#endif //!C_CAMERA_H