// Conways Game.cpp : Defines the entry point for the application.
//
#include <Windows.h>

#include "LifeSimulator.hpp"
#include "RendererConsole.hpp"
#include "PatternAcorn.hpp"

int main()
{
	//get the size of the console
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	std::uint8_t columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	//create a life simulator
	LifeSimulator myWorld(columns, rows);
	PatternAcorn acorn;
	myWorld.insertPattern(acorn, 0, 0);

	//render the simulator
	RendererConsole console;
	console.render(myWorld);

	return 0;
}
