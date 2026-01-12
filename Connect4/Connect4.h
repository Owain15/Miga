#pragma once

#ifdef Connect4_EXPORTS
#define Connect4_API __declspec(dllexport)
#else
// Do not force __declspec(dllimport) for consumers — allow header-only/linkable usage
#define Connect4_API
#endif

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

	class Connect4_API Game
	{
	public:

		Game();
		~Game();

		void Reset();

		//bool MakeMove(int row, int col);

		GameState GetGameState();

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

#ifdef __cplusplus
extern "C" {
#endif

// Export a simple C symbol to ensure the DLL produces an import library
Connect4_API void Connect4_EnsureExport();

#ifdef __cplusplus
}
#endif


