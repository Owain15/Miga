#pragma once


#include <iostream>
#include <string>
#include <vector>

namespace Connect4
{

	enum class CellState
	{
		Empty,
		Red,
		Yellow,
		OutOfBounds
	};

	enum class GameState
	{
		InProgress,
		Red_Wins,
		Yellow_Wins,
		Draw
	};

	class Game
	{
	public:

		Game();
		~Game();

		void Reset();

		

		GameState GetGameState() const;

		bool SetGameState(GameState state);

		CellState GetCellState(int row, int col) const;

		std::string GetCurrentPlayer() const;

		//std::string GetGridData();

		bool isInputValid(const std::string& input);

		bool MakeMove(int colIndex);
	
	private:

		CellState grid[6][7];

		CellState currentPlayer;

		GameState gameState;

		void UpdateCurrentPlayer();

		void UpdateGameState();

		bool CheckFor4(int row, int col);

	};
}
