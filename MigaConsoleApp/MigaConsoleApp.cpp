// MigaConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include <string>
#include <thread>

#include "Conterollers.h"
#include "ConsoleUi.h"
#include "RunProgram.h"


//#import TicTacToe.dll
//#include "TicTacToe/TicTacToe.h"
//#include "TttGame.h"
//#include "Connect4.h"
//#include "ConsoleUi.h"

int main()
{

	bool appRunning = true;
	
	while (appRunning)
	{
		
		bool inputValid = false;
		std::string input = "";

		while (!inputValid)
		{
			ConsoleUi::HomePage::DrawHomePage();
			
			input = Controllers::GetInput();

			inputValid = Controllers::HomePage::ValidateInput(input);

			if (!inputValid)
			{
				ConsoleUi::HomePage::DrawInputErrorPrompt();

				ConsoleUi::Sleep();
			}

		}

		int inputIndex = std::stoi(input);

		switch (inputIndex)
		{
			case 1:
			{
				RunProgram::ChooseProgram(RunProgram::ProgramChoice::Connect4);
				break;
			}
			case 2:
			{
				RunProgram::ChooseProgram(RunProgram::ProgramChoice::TicTacToe);
				break;
			}
			case 3:
			{
				appRunning = false;
				break;
			}
			default:
			{
				ConsoleUi::ApplicationNotFound();
				break;
			}
		}


	}

	ConsoleUi::Clear();

	ConsoleUi::Sleep();

	return 0;

}
