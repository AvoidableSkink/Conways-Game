#include "LifeSimulator.hpp"


//The constructor accepts a sizeXand sizeY indicating the size of the world.
//You'll want to set these equal to the width/height of the console the program runs within.
//TODO: if you are getting weird results maybe need to swap x and y we have y as the vector of vectors
LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY) {
	sizeX = sizeX;
	sizeY = sizeY;
	//fill up your world with dead cells
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t j = 0; j < sizeX; j++)
		{
			cell tmp;
			tmp.alive = false;
			myPattern[i].push_back(tmp);
		}
	}
}

//insertPattern - Adds the pattern to the world, with the upper left corner beginning at startXand startY.
void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY) {

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