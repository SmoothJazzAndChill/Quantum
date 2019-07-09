#include "QuantumApplication.h"

int main() 
{
	QuantumApp App;
	
	try 
	{
		App.Run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		system("PAUSE");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}