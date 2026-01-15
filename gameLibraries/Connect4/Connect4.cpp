
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

	GameState Game::GetGameState() const
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
		int empytyCells = 0;

		for (int row = 0; row < 6; row++)
			for (int col = 0; col < 7; col++)
			{
				if (grid[row][col] == CellState::Empty)
				{
					empytyCells++;
					continue;
				}

				bool gameEndFound = CheckFor4(row, col);

				if (gameEndFound)
				{
					gameState = (grid[row][col] == CellState::Red) ? GameState::Red_Wins : GameState::Yellow_Wins;
					return;
				}
			}

		if (empytyCells < 1)
		{
			gameState = GameState::Draw;
		}
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

	bool Game::CheckFor4(int row, int col)
	{
		Connect4::CellState target = grid[row][col];
		int inARow = 0;


		//check horizontal

		for (int i = col - 4; i < col + 4; i++)
		{
			//check bounds
			if (i < 0 || i + 3 >= 7 && row < 0 || row >= 6)
			{
				continue;
			}

			if (grid[row][i] == target)
			{
				inARow++;
			}
			else
			{
				inARow = 0;
			}

			if (inARow >= 4)
			{
				return true;
			}
		}
		
		//check vertical
		inARow = 0;

		for (int i = row - 4; i < row + 4; i++)
		{
			//check bounds
			if (col < 0 || col >= 7 && i < 0 || i + 3 >= 6)
			{
				continue;
			}

			if (grid[i][col] == target)
			{
				inARow++;
			}
			else
			{
				inARow = 0;
			}

			if (inARow >= 4)
			{
				return true;
			}
		}

		//check diagonal /
		inARow = 0;

		for (int i = -4; i < 4; i++)
		{
			int checkRow = row + i;
			int checkCol = col - i;

			//check bounds
			if (checkCol < 0 || checkCol >= 7 && checkRow < 0 || checkRow >= 6)
			{
				continue;
			}

			if (grid[checkRow][checkCol] == target)
			{
				inARow++;
			}
			else
			{
				inARow = 0;
			}

			if (inARow >= 4)
			{
				return true;
			}
		}

		//check diagonal \

		inARow = 0;

		for (int i = -4; i < 4; i++)
		{
			int checkRow = row + i;
			int checkCol = col + i;

			//check bounds
			if (checkCol < 0 || checkCol >= 7 && checkRow < 0 || checkRow >= 6)
			{
				continue;
			}

			if (grid[checkRow][checkCol] == target)
			{
				inARow++;
			}
			else
			{
				inARow = 0;
			}

			if (inARow >= 4)
			{
				return true;
			}
				
		}

		// no connect 4 found
		return false;
	}

	
}