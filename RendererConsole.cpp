#include "RendererConsole.hpp"
#include "rlutil.h"

void RendererConsole::render(const LifeSimulator& simulation) {
	rlutil::cls();
	rlutil::hidecursor();

	//render me
	for (size_t y = 0; y < simulation.getSizeY(); y++)
	{
		for (size_t x = 0; x < simulation.getSizeX(); x++)
		{
			if (simulation.getCell(x,y) == true)
			{
				//move cursor and render char
				rlutil::locate(x, y);
				rlutil::setChar('7');
			}
			else {
				continue;
			}
		}
	}
	
	rlutil::showcursor();
}