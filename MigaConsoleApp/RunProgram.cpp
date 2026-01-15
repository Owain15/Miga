
#include <iostream>
#include <string>
#include <thread>

#include "RunProgram.h"
#include "Connect4.h"


void RunProgram::Connect4()
{
	bool gameRunning = true;

	while (gameRunning)
	{
		gameRunning = Connect4RunGame();

	}	
}

bool RunProgram::Connect4RunGame()
{
	bool gameRunning = true;
	int messageDelay = 1; // seconds
	
	Connect4::Game* c4 = new Connect4::Game();
	
	while (c4->GetGameState() == Connect4::GameState::InProgress)
	{
		//draw game state
		ConsoleUi::DrawGameState(*c4);

		ConsoleUi::DrawConnect4MovePrompt(c4->GetGameState());

		//get input
		std::string input;
		std::cin >> input;

		//handle input
		if (input == "exit")
		{
			gameRunning = false;
			c4->SetGameState(Connect4::GameState::Draw); // to exit the game loop
			break;
		}

		if (input == "reset")
		{
			c4->Reset();
			continue;
		}

		if (!c4->isInputValid(input))
		{
			std::cout << "\n\nInvalid input.\n Please enter a valid column number (1-7)\n or 'reset' to restart.\nor 'exit' to end game.\n";
			std::this_thread::sleep_for(std::chrono::seconds(messageDelay));
			continue;
		}

		bool moveSucsesfull = c4->MakeMove(std::stoi(input) - 1);

		if (!moveSucsesfull)
		{
			std::cout << "\n\nMove failed. Try again.\n";
			std::this_thread::sleep_for(std::chrono::seconds(messageDelay));
			continue;
		}

	}

	//end game

	while (true)
	{
		ConsoleUi::DrawGameState(*c4);

		std::cout << "Game Over!\n\n";

		ConsoleUi::DrawConnect4MovePrompt(c4->GetGameState());

		//get input
		std::string input;
		std::cin >> input;

		//handle input

		if (input == "exit")
		{
			gameRunning = false;
			break;
		}
		if (input == "reset")
		{
			break;
		}

		std::cout << "\n\nInvalid input.\n Please enter 'reset' to restart.\nor 'exit' to end game.\n";
		std::this_thread::sleep_for(std::chrono::seconds(messageDelay));

	}

	return gameRunning;
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