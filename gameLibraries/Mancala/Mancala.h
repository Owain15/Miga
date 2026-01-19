#pragma once

#include <vector>

namespace Mancala
{

	class Game
	{

		public:
			
			Game();
			~Game();

			int GetCurrentPlayer() const;

			int GetPotCount() const;

			int GetStonesInPot(int player, int potIndex) const;

			bool ValidateInput(int input) const;

			bool MakeMove(int input);

			void RestGame();
		
		private:

			int currentPlayer;

			int potCount;
			int initialStonesPerPit = 4;

			int player1Pots[7];
			int player2Pots[7];

	};
}
