#pragma once
#ifndef QUANTUM_APPLICATION_H
#define QUANTUM_APPLICATION_H

#include "GraphicsEngine.h"
#include "QuantumEngine.h"

class QuantumApp
{
public:
	void Run()
	{
		Graphics.Initialise();
		MainLoop();
		Graphics.Close();
	}

private:
	GraphicsEngine Graphics;
	QuantumEngine Game;

	void MainLoop()
	{
		while (true)
		{
			glfwPollEvents();
			Graphics.Draw();
			
			if (Graphics.WindowShouldClose())
			{
				break;
			}
		}

		
	}
};

#endif // !QUANTUM_APPLICATION_H