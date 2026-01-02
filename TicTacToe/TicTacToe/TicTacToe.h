#pragma once

namespace TicTacToe
{

	enum class CellState
	{
		Empty,
		X,
		O
	};
	
	class Game
	{
		public:
		Game();
		~Game();

		

		int PlayerIndex;
		CellState Grid[3][3];


	private:

	};

	Game::Game()
	{
		PlayerIndex = 0;
		
		//Grid = InitalizeGrid();
	/*	for (int row = 0; row < 3; ++row)
		{
			for (int col = 0; col < 3; ++col)
			{
				Grid[row][col] = CellState::Empty;
			}
		}*/
	}

	Game::~Game()
	{
	}


	void InitalizeNewGrid();
	/*CellState[][] InitalizeNewGrid();
	{
		CellState Grid[3][3];

		for (int row = 0; row < 3; ++row)
		{
			for (int col = 0; col < 3; ++col)
			{
				Grid[row][col] = CellState::Empty;
			}
		}

		return Grid;
	}*/
}



