
#include <iostream>

#include "ConsoleUi.h"

namespace ConsoleUi
{
	void DrawGameState()
	{
		// Clear the console
		system("cls"); // For Windows, use "clear" for Unix-based systems
		// Draw the header
		std::cout << "Mini-Game-Console-App\n\n";
		// Draw the game state here
		std::cout << "-----------------------\n";
		std::cout << "Tic-Tac-Toe Game State\n";
		std::cout << "-----------------------\n\n";
		std::cout << "  1 2 3\n";
		std::cout << "a . . .\n";
		std::cout << "b . . .\n";
		std::cout << "c . . .\n\n";
		std::cout << "-----------------------\n\n";
		std::cout << "Enter your move (e.g., a1, b2) or 'reset' to restart:\n\n";
		std::cout << "Move : ";
	}


	void ConsoleUi::DrawGameState(std::string cPlayer,std::string gridData)
	{
		// Clear the console
		system("cls"); // For Windows, use "clear" for Unix-based systems
		// Draw the header
		std::cout << "Mini-Game-Console-App-TicTacToe\n\n";
		// Draw the game state here
		std::cout << "-----------------------\n";
		std::string playerStr = "P";
		std::cout << "Current Player : " << cPlayer << "\n";
		std::cout << "-----------------------\n\n";
		std::cout << "  1 2 3\n";
		
		for (int i = 0; i < 3; i++)
		{
			char rowLabel = 'a' + i;

			std::string rowData;

			for (int j = 0; j < 3; j++)
			{
				char cellChar = gridData[i * 3 + j];
				rowData += ' ';
				rowData += cellChar;
			}
		
			std::cout << rowLabel << rowData;
			
			std::cout << "\n";
			
		}
		std::cout << "\n-----------------------\n\n";
		std::cout << "Enter your move (e.g., a1, b2) or 'reset' to restart:\n\n";
		std::cout << "Move : ";
	}

}
