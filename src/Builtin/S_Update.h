#pragma once
#ifndef S_UPDATE_H
#define S_UPDATE_H

#include QuantumAPI
#include QuantumArchitecture

namespace Quantum
{
	class S_Update : public System
	{
	public:
		InterfaceContainer<I_ClientUpdate> ClientUpdates;
		InterfaceContainer<I_HostUpdate> HostUpdates;
		InterfaceContainer<I_FixedUpdate> FixedUpdates;

		void Awake()
		{
			ConnectInterface<I_ClientUpdate>(&ClientUpdates);
			ConnectInterface<I_HostUpdate>(&HostUpdates);
			ConnectInterface<I_FixedUpdate>(&FixedUpdates);
		}

		void Run()
		{
			for (std::shared_ptr<I_ClientUpdate> c : *(ClientUpdates.Data))
			{
				c->Update();
			}

			for (std::shared_ptr<I_HostUpdate> c : *(HostUpdates.Data))
			{
				c->Update();
			}

			for (std::shared_ptr<I_FixedUpdate> f : *(FixedUpdates.Data))
			{
				f->FixedUpdate();
			}
		}
	};
}

#endif //!S_UPDATE_H