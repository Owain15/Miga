#pragma once

#include "TttGame.h"
#include "Connect4.h"

namespace ConsoleUi
{

	void DrawGameState();

	void DrawGameState(std::string cPlayer, std::string gridData);

	void DrawGameState(const Connect4::Game& game);

	void DrawConnect4MovePrompt();
}
