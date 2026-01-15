#pragma once

#include "TttGame.h"
#include "Connect4.h"

namespace ConsoleUi
{
	namespace HomePage
	{
		enum class MenuOption
		{
			Connect4,
			TicTacToe,
			Exit,
			Invalid
		};
		
		void DrawHomePage();
		
		void DrawMenu();

		void DrawInputErrorPrompt();
		
	}

	void Clear();

	void Sleep();

	void Sleep(int seconds);

	void PressEnterToContinue();

	void ApplicationNotFound();

	void DrawGameState();

	void DrawGameState(std::string cPlayer, std::string gridData);

	void DrawGameState(const Connect4::Game& game);

	void DrawConnect4MovePrompt(const Connect4::GameState& gameState);
}
