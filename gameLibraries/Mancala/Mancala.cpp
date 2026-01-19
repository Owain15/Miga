
#include "Mancala.h"

namespace Mancala
{
	Game::Game()
	{
		RestGame();
	}


	void Game::RestGame()
	{
	
		currentPlayer = 1;
		potCount = 7;
		
		for (int i = 0; i < potCount - 1; i++)
		{
			player1Pots[i] = initialStonesPerPit;
			player2Pots[i] = initialStonesPerPit;
		}
		
		player1Pots[potCount - 1] = 0; // Player 1's Mancala
		player2Pots[potCount - 1] = 0; // Player 2's Mancala
	
	}		


	int Game::GetCurrentPlayer() const 
	{
		return currentPlayer;
	}

	int Game::GetPotCount() const 
	{ return potCount; }

	int Game::GetStonesInPot(int player, int potIndex) const
	{
		if (player == 1)
		{
			return player1Pots[potIndex];
		}
		else
		{
			return player2Pots[potIndex];
		}
	}

	bool Game::ValidateInput(int input) const
	{
		if (input < 1 || input > potCount - 1)
		{
			return false;
		}
		
		if (currentPlayer == 1)
		{
			if (player1Pots[input -1] == 0)
			{
				return false;
			}
		}
		else
		{
			if (player2Pots[input -1] == 0)
			{
				return false;
			}
		}
	
		return true;
	}

	bool Game::MakeMove(int input)
	{
		bool moveMade = false;
		bool getsAnotherTurn = false;

		int stonesToDistribute = GetStonesInPot(currentPlayer,input -1);
	
		//clear chosed pot
		if(currentPlayer == 1)
		{
			player1Pots[input -1] = 0;
		}
		else
		{
			player2Pots[input -1] = 0;
		}

		int index = input -1;

		int player = currentPlayer;

		while (stonesToDistribute > 0)
		{
			index++;

			if (index == potCount)
			{
				if (player == currentPlayer)
				{
					if (currentPlayer == 1)
					{
						player1Pots[potCount - 1]++;
					}
					else
					{
						player2Pots[potCount - 1]++;
					}
				
					stonesToDistribute--;
					
					if (stonesToDistribute == 0)
					{
						getsAnotherTurn = true; 
					}
				}
			
				index = -1;
				
				player = (player == 1) ? 2 : 1;
			
			}
			else
			{
				if (player == 1)
				{
					player1Pots[index]++;
				}
				else
				{
					player2Pots[index]++;
				}
				
				stonesToDistribute--;
			}
		}
		
		if (!getsAnotherTurn)
		{
			currentPlayer = (currentPlayer == 1) ? 2 : 1;
		}
		
		//EvaluateGameState();

		return true;
	}

}