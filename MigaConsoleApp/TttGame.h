

#pragma once

#include <iostream>
#include <string>

namespace TttGame
{
	

	enum class CellState
	{
		Empty,
		X,
		O,
		OutOfBounds
	};

	

	enum class GameState
	{
		InProgress,
		X_Wins,
		O_Wins,
		Draw
	};
	
	class TttGame
	{
		public:
		
			TttGame();
			~TttGame();
		
			void Reset();
		
			bool MakeMove(int row, int col);
		
			GameState GetGameState();
		
			CellState GetCellState(int row, int col);

			std::string GetCurrentPlayer();

			std::string GetGridData();
	
		private:
	
			CellState grid[3][3];
	
			CellState currentPlayer;
		
			GameState gameState;

			void UpdateCurrentPlayer();
		
			void UpdateGameState();
	
	};
} 
