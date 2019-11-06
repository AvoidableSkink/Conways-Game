#include "LifeSimulator.hpp"


//The constructor accepts a sizeXand sizeY indicating the size of the world.
//You'll want to set these equal to the width/height of the console the program runs within.
LifeSimulator::LifeSimulator(std::uint8_t sX, std::uint8_t sY) {
	sizeX = sX;
	sizeY = sY;
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
	newState = currentState;
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
	//for each cell check the neighbors for these
	//Any live cell with fewer than two live neighbours dies, as if by underpopulation.
	//Any live cell with two or three live neighbours lives on to the next generation.
	//Any live cell with more than three live neighbours dies, as if by overpopulation.
	//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
	for (size_t y = 0; y < sizeY; y++)
	{
		for (size_t x = 0; x < sizeX; x++)
		{
			std::uint8_t livingCount = liveNeighborCount(x, y);
			if (currentState[y][x].alive == true) {
				//check the true stuff
				switch (livingCount)
				{
				case 2: 
					newState[y][x].alive = true;
					break;
				case 3:
					newState[y][x].alive = true;
					break;
				default:
					newState[y][x].alive = false;
					break;
				}
			}
			else {
				switch (livingCount)
				{
				case 3:
					newState[y][x].alive = true;
					break;
				default:
					newState[y][x].alive = false;
					break;
				}
			}
		}
	}
	currentState = newState;
}

//takes in the x,y of a cell, counts up how many live neighbors it has
//if a cell doesnt have all 8 neighbors the missing ones are just counted as dead
std::uint8_t LifeSimulator::liveNeighborCount(std::uint8_t x, std::uint8_t y) {
	std::uint8_t count = 0;
	//lets just brute force this?
	//TODO: check that none of these are out of bounds ... also too big 
	if (((y - 1) >= 0 && (x - 1) >= 0) && currentState[y - 1][x - 1].alive)
		count++;
	if ((y - 1) >= 0 && currentState[y - 1][x].alive)
		count++;
	if (((y - 1) >= 0 && (x + 1) < sizeX) && currentState[y - 1][x + 1].alive)
		count++;
	if (((x - 1) >= 0) && currentState[y][x - 1].alive)
		count++;
	if (((x + 1) < sizeX) && currentState[y][x + 1].alive)
		count++;
	if (((y + 1) < sizeY && (x - 1) >= 0) && currentState[y + 1][x - 1].alive)
		count++;
	if ((y + 1) < sizeY && currentState[y + 1][x].alive)
		count++;
	if (((y + 1) < sizeY && (x + 1) < sizeX) && currentState[y + 1][x + 1].alive)
		count++;

	return count;
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