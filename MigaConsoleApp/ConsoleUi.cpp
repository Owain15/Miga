
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
		std::cout << "No Game Selected\n";
		std::cout << "-----------------------\n\n";
	
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

	void DrawGameState(Connect4::GameState gs)
	{
		//// Clear the console
		//system("cls"); // For Windows, use "clear" for Unix-based systems
		//// Draw the header
		//std::cout << "Mini-Game-Console-App-Connect4\n\n";
		//// Draw the game state here
		//std::cout << "-----------------------\n";
		//std::cout << "Connect4 Game State\n";
		//std::cout << "-----------------------\n\n";
		//std::cout << "  1 2 3 4 5 6 7\n";
		//
		//for (int i = 0; i < 6; i++)
		//{
		//	char rowLabel = 'A' + i;
		//	std::string rowData;
		//	for (int j = 0; j < 7; j++)
		//	{
		//		// Placeholder for cell state representation
		//		rowData += " .";
		//	}
		//
		//	std::cout << rowLabel << rowData;
		//	
		//	std::cout << "\n";
		//	
		//}
		//std::cout << "\n-----------------------\n\n";
		//std::cout << "Enter your move (e.g.,'1' for colmn 1, '2' for column 2) or 'reset' to restart:\n\n";
		//std::cout << "Move : ";
	}

}
