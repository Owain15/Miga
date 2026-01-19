

#include <iostream>


#include "Conterollers.h"

namespace Controllers
{
	std::string GetInput()
	{
		std::string input;
		std::cin >> std::ws >> input; // eat up any leading whitespace
		return input;
	}

	namespace HomePage
	{
		int GetInput()
		{
			std::cin >> std::ws; // eat up any leading whitespace
			
			return 0;
		}

		bool ValidateInput(const std::string& input)
		{
			if (input == "1" || input == "2" || input == "3" || input == "4")
			{
				return true;
			}
			
			return false;
		}
	}
}