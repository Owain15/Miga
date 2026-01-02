
#include "TicTacToe.h"

//TicTacToe

TicTacToe::Game::Game()
{

}

TicTacToe::InitalizeNewGrid()
{
	CellState Grid[3][3] ;
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			Grid[row][col] = CellState::Empty;
		}
	}
}