#pragma once

#include "TttGame.h"
#include "Connect4.h"
#include "Mancala.h"

#include "ConsoleUi.h"


namespace RunProgram
{
	enum class ProgramChoice
	{
		Connect4,
		TicTacToe,
		Mancala
	};

	void ChooseProgram(ProgramChoice choice);

	bool Connect4();

	bool TicTacToe();

	bool Mancala();

}
