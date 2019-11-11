#pragma once
#ifndef QUANTUM_APPLICATION_H
#define QUANTUM_APPLICATION_H

#include "QuantumGraphics.h"
#include "QuantumEngine.h"

class QuantumApp
{
public:
	QuantumApp() {}

	void Run()
	{
		Graphics.Initialise();
		Game.Initialise();
		Game.Start();
		MainLoop();
		Graphics.Close();
	}

private:
	QuantumGraphics Graphics;
	Quantum::QuantumEngine Game;

	void MainLoop()
	{
		while (true)
		{
			glfwPollEvents();
			Game.Run();
			Graphics.Draw();
			
			if (Graphics.WindowShouldClose())
			{
				break;
			}
		}

		
	}
};

#endif // !QUANTUM_APPLICATION_H