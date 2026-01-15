#pragma once


namespace Controllers
{
	std::string GetInput();

	namespace HomePage
	{
		enum class inputs
		{
			Connect4 = 1,
			TicTacToe = 2,
			Exit = 3,

			Invalivd = -1
		};

		int GetInput();

		bool ValidateInput(const std::string& input);
	}
}