#include "PatternAcorn.hpp"

PatternAcorn::PatternAcorn() {
	sizeX = 9;
	sizeY = 5;
	//fill up your pattern with non-active, dead cells
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

//Returns true if the cell in the pattern is filled, false otherwise.
bool PatternAcorn::getCell(std::uint8_t x, std::uint8_t y) {
	if (myPattern[y][x].alive == true) {
		return true;
	}
	else {
		return false;
	}
}

//fill up your pattern that looks like this
//std::vector<std::vector<cell>> myPattern;
void PatternAcorn::populatePattern() {
	//just brute force it man
	myPattern[1][2].alive = true;
	myPattern[2][4].alive = true;
	myPattern[3][1].alive = true;
	myPattern[3][2].alive = true;
	myPattern[3][5].alive = true;
	myPattern[3][6].alive = true;
	myPattern[3][7].alive = true;
}