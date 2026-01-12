
#include <iostream>
#include <string>
#include <thread>

#include "RunProgram.h"

void RunProgram::Connect4()
{
	Connect4::Game* c4 = new Connect4::Game();

	/*while (c4->GetGameState() == Connect4::GameState::InProgress)
	{
		ConsoleUi::DrawGameState(c4->GetGameState());

		std::string input;
		std::cin >> input;

	}*/
	
	std::cout << "Connect4 game is not yet implemented.\n";
}

void RunProgram::TicTacToe()
{
	int messageDelay = 1; // seconds

	//std::cout << "Mini-Game-Console-App\n";


	TttGame::TttGame* game = new TttGame::TttGame();

	while (game->GetGameState() == TttGame::GameState::InProgress)
	{
		ConsoleUi::DrawGameState(game->GetCurrentPlayer(), game->GetGridData());

		std::string input;
		std::cin >> input;

		/*	if(input == "exit")
			{

			}*/

		if (input == "reset")
		{
			game->Reset();
			continue;
		}

		if (input.length() != 2)
		{
			std::cout << "Invalid input.\n Please enter a row and column (e.g., a1 for row a, column 1)\n or 'reset' to restart.\nor 'exit' to end game.\n";
			std::this_thread::sleep_for(std::chrono::seconds(messageDelay));
			continue;
		}

		if (input[0] < 'a' || input[0] > 'c' && input[1] < '1' || input[1] > '3')
		{
			std::cout << "Invalid input.\n Please enter a row and column (e.g., a1 for row a, column 1)\n or 'reset' to restart.\nor 'exit' to end game.\n";
			std::this_thread::sleep_for(std::chrono::seconds(messageDelay));
			continue;
		}

		switch (input[0])
		{
		case 'a':
			input[0] = '0';
			break;
		case 'b':
			input[0] = '1';
			break;
		case 'c':
			input[0] = '2';
			break;

		default:
			input[0] = '0';
			break;
		}
		char c1 = input[0];
		char c2 = input[1];

		int x = atoi(&c1);
		int y = atoi(&c2) - 1;

		//int x = atoi(&input[0]);
		//int y = atoi(&input[1])-1;

		if (game->GetCellState(x, y) != TttGame::CellState::Empty)
		{
			std::cout << "Invalid move. Try again.\n";
			std::this_thread::sleep_for(std::chrono::seconds(messageDelay));
			continue;
		}

		bool mc = game->MakeMove(x, y);

		if (!mc)
		{
			std::cout << "Move faild. Try again.\n";
			std::this_thread::sleep_for(std::chrono::seconds(messageDelay));
			continue;
		}

	}

}