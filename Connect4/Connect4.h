#pragma once



#ifdef Connect4_EXPORTS
#define Connect4_API __declspec(dllexport)
#else
#define Connect4_API __declspec(dllimport)
#endif



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

		//bool MakeMove(int row, int col);

		//GameState GetGameState();

		//CellState GetCellState(int row, int col);

		//std::string GetCurrentPlayer();

		//std::string GetGridData();

	private:

		CellState grid[6][7];

		CellState currentPlayer;

		GameState gameState;

		void UpdateCurrentPlayer();

		void UpdateGameState();

	};
}


