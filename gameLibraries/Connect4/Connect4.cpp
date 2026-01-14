
#include "Connect4.h"

namespace Connect4
{
	Game::Game()
	{
		Reset();
	}

	//Game::~Game() = default;

	void Game::Reset()
	{
		gameState = GameState::InProgress;
		currentPlayer = CellState::Red;
		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 7; ++j)
			{
				grid[i][j] = CellState::Empty;
			}
		}
	}

	GameState Game::GetGameState()
	{
		return gameState;
	}

	bool Game::SetGameState(GameState state)
	{
		gameState = state;
		return true;
	}

	CellState Game::GetCellState(int row, int col) const
	{
		return grid[row][col];
	}

	std::string Game::GetCurrentPlayer() const
	{
		return (currentPlayer == CellState::Red) ? "Red" : "Yellow";
	}

	void Game::UpdateCurrentPlayer()
	{
		currentPlayer = (currentPlayer == CellState::Red) ? CellState::Yellow : CellState::Red;
	}

	void Game::UpdateGameState()
	{
		// Placeholder -- implement game-over detection here
	}

	bool Game::isInputValid(const std::string& input)
	{
		if (input.length() != 1)
		{
			return false;
		}
		
		char colChar = input[0];
		if (colChar < '1' || colChar > '7')
		{
			return false;
		}
		
		int col = colChar - '1';
		

		return grid[0][col] == CellState::Empty;
	}

	bool Game::MakeMove(int col)
	{
		if (col < 0 || col >= 7)
		{
			return false;
		}
		
		for (int row = 5; row >= 0; --row)
		{
			if (grid[row][col] == CellState::Empty)
			{
				grid[row][col] = currentPlayer;

				UpdateCurrentPlayer();
				UpdateGameState();

				return true;
			}
		}
		return false; // Column is full
	}

} 