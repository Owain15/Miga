
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

		int playerPotsAffected = currentPlayer;

		while (stonesToDistribute > 0)
		{
			//update index
			index++;
			if (index > potCount - 2 && playerPotsAffected != currentPlayer || index > potCount - 1 && playerPotsAffected == currentPlayer)
			{
				index = 0;
				playerPotsAffected = (playerPotsAffected == 1) ? 2 : 1;
			}

			//valid index check
			if(index < 0 || index >= potCount)
			{
				return false;
			}

			//check next pot
			if (index < potCount - 1)
			{
				//normal pot
				if (playerPotsAffected == 1)
				{
					player1Pots[index]++;
					stonesToDistribute--;
				}
				else
				{
					player2Pots[index]++;
					stonesToDistribute--;
				}
			}

			if(index == potCount-1)
			{
				//home pot
				if (playerPotsAffected == currentPlayer)
				{
					if (currentPlayer == 1)
					{
						player1Pots[potCount -1]++;
						stonesToDistribute--;
					}
					else
					{
						player2Pots[potCount -1]++;
						stonesToDistribute--;
					}
	
				}
			}
	
		}

		//// check last stone for anuther turn or pot steal
		//if(index == potCount -1)
		//{
		//	getsAnotherTurn == true;
		//}

	/*	if (playerPotsAffected == currentPlayer || GetStonesInPot(playerPotsAffected, index) == 1)
		{
			if (currentPlayer == 1)
			{
				player1Pots[potCount - 1]++;
				player1Pots[index] = 0;

				player1Pots[potCount - 1] += player2Pots[potCount - index];
				player2Pots[potCount - index] = 0;

			}
			else
			{ 
				player2Pots[potCount - 1]++;
				player2Pots[index] = 0;
			
				player2Pots[potCount - 1] += player1Pots[potCount - index];
				player1Pots[potCount - index] = 0;
			}


		}*/


		//handel setting next player
		if (!getsAnotherTurn)
		{
			currentPlayer = (currentPlayer == 1) ? 2 : 1;
		}
		
		//EvaluateGameState();

		return true;
	}

}