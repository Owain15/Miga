#include <iostream>

#include "ConsoleUi.h"
#include "Connect4.h"

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

	void DrawGameState(const Connect4::Game& game)
	{

		
		//// Clear the console
		system("cls"); // For Windows, use "clear" for Unix-based systems
		//// Draw the header
		std::cout << "Mini-Game-Console-App-Connect4\n\n";
		
		//// Draw the current player here
		std::cout << "-----------------------\n";
		std::cout << "Curent Player : " << game.GetCurrentPlayer() << "\n";
		std::cout << "-----------------------\n\n";
		
		////draw grid
		std::cout << "  1 2 3 4 5 6 7\n";
		
		for (int i = 0; i < 6; i++)
		{
			//char rowLabel = 'A' + i;
			std::string rowData = "|";
			for (int j = 0; j < 7; j++)
			{
			
				Connect4::CellState cellState = game.GetCellState(i, j);

				switch (cellState) 
				{
					case Connect4::CellState::Empty:
						rowData += " .";
						break;
					case Connect4::CellState::Red:
						rowData += " R";
						break;
					case Connect4::CellState::Yellow:
						rowData += " Y";
						break;
				
				}
			}
		
			std::cout << rowData << " |";
			
			std::cout << "\n";
			
		}
		
		std::cout << "  - - - - - - -\n";

		std::cout << "\n-----------------------\n\n";

	}

	void DrawConnect4MovePrompt(const Connect4::GameState& gameState)
	{
		std::string prompt = "";

		switch (gameState)
		{
			case Connect4::GameState::InProgress:
			{
				prompt = "Enter your move (e.g.,'1' for colmn 1, '2' for column 2)\n";
				break;
			}
			case Connect4::GameState::Red_Wins:
			{
				prompt = "Red Player Wins!\n";
				break;
			}
			case Connect4::GameState::Yellow_Wins:
			{
				prompt = "Yellow Player Wins!\n";
				break;
			}
			case Connect4::GameState::Draw:	
			{
				prompt = "It's a Draw!\n";
				break;
			}
					

		default:
			break;
		}

		std::cout << prompt << "'reset' to restart\n'exit' to end game:\n\nMove : ";
		
	}

}
