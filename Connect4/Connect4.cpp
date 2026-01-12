#include "pch.h"
#include "Connect4.h"

Connect4::Game::Game()
{
	Reset();
}

Connect4::Game::~Game() = default;

void Connect4::Game::Reset()
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

Connect4::GameState Connect4::Game::GetGameState()
{
	return gameState;
}

void Connect4::Game::UpdateCurrentPlayer()
{
	currentPlayer = (currentPlayer == CellState::Red) ? CellState::Yellow : CellState::Red;
}

void Connect4::Game::UpdateGameState()
{
	// Placeholder -- implement game-over detection here
}

// Provide the C-exported function definition added to the header to force an exported symbol
extern "C" Connect4_API void Connect4_EnsureExport()
{
	// No-op
}

// Ensure the symbol is exported even if unreferenced
#pragma comment(linker, "/export:Connect4_EnsureExport")