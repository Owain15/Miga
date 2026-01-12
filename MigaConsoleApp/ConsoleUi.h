#pragma once

#include "TttGame.h"
#include "../Connect4/Connect4.h"

namespace ConsoleUi
{
	void DrawGameState();

	void DrawGameState(std::string cPlayer, std::string gridData);

	void DrawGameState(Connect4::GameState gs);
}
