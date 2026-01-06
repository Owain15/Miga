
#include "pch.h"
#include"Connect4.h"
#include<iostream>	



#include "Connect4.h"

namespace Connect4
{

	Connect4::Game::Game()
	{
		Reset();
	}

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

	void Connect4::Game::UpdateCurrentPlayer()
	{
		currentPlayer = (currentPlayer == CellState::Red) ? CellState::Yellow : CellState::Red;
	}
	

}