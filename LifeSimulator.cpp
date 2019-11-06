#include "LifeSimulator.hpp"


//The constructor accepts a sizeXand sizeY indicating the size of the world.
//You'll want to set these equal to the width/height of the console the program runs within.
LifeSimulator::LifeSimulator(std::uint8_t sX, std::uint8_t sY) {
	sizeX = sX+3;
	sizeY = sY+3;
	//fill up your world with dead cells
	for (size_t i = 0; i < sizeY; i++)
	{
		std::vector<cell> tmp;
		currentState.push_back(tmp);
		for (size_t j = 0; j < sizeX; j++)
		{
			cell tmp;
			tmp.alive = false;
			currentState[i].push_back(tmp);
		}
	}
}

//insertPattern - Adds the pattern to the world, with the upper left corner beginning at startXand startY.
void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY) {
	for (size_t y = 0; y < pattern.getSizeY(); y++)
	{
		for (size_t x = 0; x < pattern.getSizeX(); x++)
		{
			//check that the cell is in range of the world
			if (y + startY >= sizeY || x + startX >= sizeX) {
				continue;
			}
			//if in bounds update state of cell to be same as corresponding pattern cell
			currentState[y + startY][x + startX].alive = pattern.getCell(x, y);
		}
	}
}

//update - Performs a single step update of the world, following the four rules specified in the wiki article.
//for each cell, check its neighbors states and see if you live or die
void LifeSimulator::update() {

}


//getCell - Returns true if the currentWorld cell is alive, false otherwise.
//this data used to update newState
bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const {
	if (currentState[y][x].alive == true) {
		return true;
	}
	else {
		return false;
	}
}