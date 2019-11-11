#pragma once
#ifndef S_RENDERER_H
#define S_RENDERER_H

#include QuantumAPI
#include QuantumArchitecture

namespace Quantum
{
	class S_Renderer : public System, public I_ClientUpdate
	{
		LinkedList<std::shared_ptr<C_Mesh>> MeshComponents;
		LinkedList<std::shared_ptr<C_Renderer>> RendererComponents;

		void Awake()
		{
			FetchComponents<C_Mesh>(&MeshComponents);
			FetchComponents<C_Renderer>(&RendererComponents);
		}

		void Start()
		{

		}
	};
}

#endif //!S_RENDERER_H