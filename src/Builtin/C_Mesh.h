#pragma once
#ifndef C_MESH_H
#define C_MESH_H

#include QuantumAPI
#include QuantumArchitecture

namespace Quantum
{
	class C_Mesh : public Component
	{
	public:
		std::vector<Vector3> Vertices;
		std::vector<int> Triangles;
		std::vector<Vector2> TextureCoordinates;
		std::vector<Vector3> Normals;
		std::vector<Vector3> Tangents;
	};
}

#endif //!C_MESH_H