
#include "TttGame.h"

namespace TttGame
{
	
	TttGame::TttGame()
	{
		Reset();
	}

	void TttGame::Reset()
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				grid[i][j] = CellState::Empty;
			}
		}

		currentPlayer = CellState::X;
		gameState = GameState::InProgress;
	}

	bool TttGame::MakeMove(int row, int col)
	{
		if (row < 0 || row >= 3 || col < 0 || col >= 3 || grid[row][col] != CellState::Empty || gameState != GameState::InProgress)
		{
			return false;
		}

		grid[row][col] = currentPlayer;

		UpdateGameState();

		if (gameState == GameState::InProgress)
		{
			UpdateCurrentPlayer();
		}

		return true;
	}

	void TttGame::UpdateCurrentPlayer()
	{
		currentPlayer = (currentPlayer == CellState::X) ? CellState::O : CellState::X;
	}

	GameState TttGame::GetGameState()
	{
		return gameState;
	}

	void TttGame::UpdateGameState()
	{
		//check rows
			if(grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2] && grid[0][0] == CellState::X || grid[0][0] == CellState::O)
			{ gameState = (grid[0][0] == CellState::X) ? GameState::X_Wins : GameState::O_Wins; }

			if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2] && grid[1][0] == CellState::X || grid[1][0] == CellState::O)
			{ gameState = (grid[1][0] == CellState::X) ? GameState::X_Wins : GameState::O_Wins; }

			if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2] && grid[2][0] == CellState::X || grid[2][0] == CellState::O)
			{ gameState = (grid[2][0] == CellState::X) ? GameState::X_Wins : GameState::O_Wins; }


		//check columns
			if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0] && grid[0][0] == CellState::X || grid[0][0] == CellState::O)
			{ gameState = (grid[0][0] == CellState::X) ? GameState::X_Wins : GameState::O_Wins; }

			if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] && grid[0][1] == CellState::X || grid[0][1] == CellState::O)
			{ gameState = (grid[0][1] == CellState::X) ? GameState::X_Wins : GameState::O_Wins; }

			if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] && grid[0][2] == CellState::X || grid[0][2] == CellState::O)
			{ gameState = (grid[0][2] == CellState::X) ? GameState::X_Wins : GameState::O_Wins; }

		//check diagonals
			if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] == CellState::X || grid[0][0] == CellState::O)
			{ gameState = (grid[0][0] == CellState::X) ? GameState::X_Wins : GameState::O_Wins; }

			if (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2] && grid[2][0] == CellState::X || grid[2][0] == CellState::O)
			{ gameState = (grid[2][0] == CellState::X) ? GameState::X_Wins : GameState::O_Wins; }

		//check for draw
			bool isDraw = true;
			
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (grid[i][j] == CellState::Empty)
					{
						isDraw = false;
						break;
					}
				}
			}

			if (isDraw && gameState == GameState::InProgress)
			{

				gameState = GameState::Draw;
			}

	}



	CellState TttGame::GetCellState(int row, int col)
	{
		if (row < 0 || row >= 3 || col < 0 || col >= 3)
		{
			return CellState::OutOfBounds; // Or handle error as appropriate
		}
		return grid[row][col];
	}

	std::string TttGame::GetCurrentPlayer()
	{
		switch (currentPlayer)
		{
			case CellState::Empty:
				return "Empty";
			case CellState::X:
				return "X";
			case CellState::O:
				return "O";
			case CellState::OutOfBounds:
				return "OutOfBounds";
			default:
				return "Unknown";
		}
	}

	std::string TttGame::GetGridData()
	{
		std::string gridData;
		
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				switch (grid[i][j])
				{
					case CellState::Empty:
						gridData += ".";
						break;
					case CellState::X:
						gridData += "X";
						break;
					case CellState::O:
						gridData += "O";
						break;
					default:
						gridData += "?";
						break;
				}
			}
			//if (i < 2) gridData += "\n"; // Add newline except after last row
		}
		return gridData;
	}

}