﻿// Conways Game.cpp : Defines the entry point for the application.
//
#include <Windows.h>
#include <thread>

#include "LifeSimulator.hpp"
#include "RendererConsole.hpp"
#include "PatternAcorn.hpp"
#include "PatternGosperGliderGun.hpp"
#include "PatternBlinker.hpp"
#include "PatternBlock.hpp"
#include "PatternGlider.hpp"

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
	PatternGosperGliderGun gun;
	myWorld.insertPattern(gun, 1, 1);
	PatternBlinker blinker;
	myWorld.insertPattern(blinker, 40, 5);
	myWorld.insertPattern(blinker, 48, 3);
	myWorld.insertPattern(blinker, 48, 10);
	myWorld.insertPattern(blinker, 55, 5);
	myWorld.insertPattern(blinker, 57, 15);
	myWorld.insertPattern(blinker, 50, 9);
	PatternBlock block;
	myWorld.insertPattern(block, 46, 3);

	bool keepGoing = true;
	while (keepGoing) {
		//render the simulator
		RendererConsole console;
		console.render(myWorld);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		myWorld.update();
	}

	return 0;
}
