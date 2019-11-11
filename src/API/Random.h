#pragma once
#ifndef RANDOM_H
#define RANDOM_H

#include "Vector.h"
#include "Colour.h"

namespace Quantum
{
	namespace Random
	{
		//Returns a random value between two set values
		template<typename T>
		T Range(T min, T max);

		//Returns a random point on a unit circle
		Vector2 PointOnUnitCircle();
		//Returns a random point on a unit sphere
		Vector3 PointOnUnitSphere();

		//Returns a random colour
		Colour RandomColour();
	}
};

#endif //!RANDOM_H