#include <iostream>
#include <thread>
#include <limits>

#include "ConsoleUi.h"
#include "Connect4.h"

namespace ConsoleUi
{



	void Clear()
	{
		// Clear the console
		system("cls"); // For Windows, use "clear" for Unix-based systems
	}

	void Sleep()
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}

	void Sleep(int seconds)
	{
		std::this_thread::sleep_for(std::chrono::seconds(seconds));
	}

	void PressEnterToContinue()
	{
		std::cout << "Press Enter to Continue";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	void ApplicationNotFound()
	{
		// Clear the console
		system("cls"); // For Windows, use "clear" for Unix-based systems
		// Draw the header
		std::cout << "Mini-Game-Console-App\n\n";
		// Draw the application not found message
		std::cout << "-----------------------\n";
		std::cout << "Application Not Found!\n";
		std::cout << "-----------------------\n\n";
		std::cout << "Press Enter to Continue";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

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


	void ConsoleUi::DrawGameState(std::string cPlayer, std::string gridData)
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



	namespace HomePage
	{
		void DrawHomePage()
		{
			// Clear the console
			system("cls"); // For Windows, use "clear" for Unix-based systems
			// Draw the header
			std::cout << "Mini-Game-Console-App\n\n";
			// Draw the menu options
			std::cout << "-----------------------\n\n";
			std::cout << "1. Connect4\n";
			std::cout << "2. TicTacToe\n";
			std::cout << "3. Mancala\n\n";
			std::cout << "4. Exit\n\n";
			std::cout << "-----------------------\n\n";
			std::cout << "Select an option (1-4):\n\n";
			std::cout << "Choice : ";
		}

		void DrawInputErrorPrompt()
		{

			// Draw the input error message
			std::cout << "\n-----------------------\n";
			std::cout << "Invalid Input! Please try again.\n";
			std::cout << "-----------------------\n\n";

			//PressEnterToContinue();
		}
	}



	namespace MancalaUi
	{

		void DrawGameState(const Mancala::Game& game)
		{
			// Clear the console
			system("cls"); // For Windows, use "clear" for Unix-based systems

			// Draw the header
			std::cout << "Mini-Game-Console-App-Mancala\n\n";

			// Draw current player
			std::cout << "-----------------------\n";
			std::cout << "Current player : " << game.GetCurrentPlayer() << "\n";
			std::cout << "-----------------------\n\n";

			// Draw the Mancala board here
			//p1 pots
			std::cout << "p1 pots\n\n";
			for (int i = game.GetPotCount(); i >= 1; i--)
			{
				char p = (i == game.GetPotCount()) ? 'H' : char(i + 48);
				std::cout << " " << p << "  ";
			}

			std::cout << "\n    ";
			for (int i = game.GetPotCount() - 2; i >= 0; i--)
			{
				std::cout << "[" << game.GetStonesInPot(1, i) << "] ";
			}
			//home pots
			for (int i = 0; i < game.GetPotCount(); i++)
			{
				if (i == 0)
				{
					std::cout << "\n[" << game.GetStonesInPot(1, game.GetPotCount() - 1) << "]"; // player 2 home pot
				}
				else if (i == game.GetPotCount() - 1)
				{
					std::cout << "[" << game.GetStonesInPot(2, game.GetPotCount() - 1) << "]"; // player 1 home pot
				}
				else
				{
					std::cout << "     ";
				}

			}
			//p2 pots

			std::cout << "\n    ";

			for (int i = 0; i < game.GetPotCount() - 1; i++)
			{
				std::cout << "[" << game.GetStonesInPot(2, i) << "] ";
			}

			std::cout << "\n";

			for (int i = 0; i <= game.GetPotCount(); i++)
			{
				char p = (i == game.GetPotCount()) ? 'H' : char(i + 48);
				if (i == 0)
				{
					p = ' ';
				}
				std::cout << " " << p << "  ";
			}

			std::cout << "\n\np2 pots\n\n";

			std::cout << "-----------------------\n";

		}





		void DrawInputPrompt()
		{
			std::cout << "Enter the pot number (1-6) to make a move\n'reset' to restart or\n'exit' to end game:\n\n";
			std::cout << "Move : ";
		}

	}
}


