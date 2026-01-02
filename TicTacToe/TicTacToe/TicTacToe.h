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
	}

	Game::~Game()
	{
	}
}



