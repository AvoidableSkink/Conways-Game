#include "PatternGosperGliderGun.hpp"

PatternGosperGliderGun::PatternGosperGliderGun() {
	sizeX = 38;
	sizeY = 11;
	//fill up your pattern with non-active, dead cells
	for (size_t y = 0; y < sizeY; y++)
	{
		std::vector<cell> tmp;
		myPattern.push_back(tmp);
		for (size_t x = 0; x < sizeX; x++)
		{
			cell tmp;
			tmp.alive = false;
			myPattern[y].push_back(tmp);
		}
	}
	populatePattern();
}

//getters
std::uint8_t PatternGosperGliderGun::getSizeX() const { return sizeX; };
std::uint8_t PatternGosperGliderGun::getSizeY() const { return sizeY; };

//Returns true if the cell in the pattern is filled, false otherwise.
bool PatternGosperGliderGun::getCell(std::uint8_t x, std::uint8_t y) const {
	if (myPattern[y][x].alive == true) {
		return true;
	}
	else {
		return false;
	}
}

//fill up your pattern that looks like this
//std::vector<std::vector<cell>> myPattern;
void PatternGosperGliderGun::populatePattern() {
	//just brute force it man
	myPattern[5][1].alive = true;
	myPattern[5][2].alive = true;
	myPattern[6][1].alive = true;
	myPattern[6][2].alive = true;

	myPattern[5][11].alive = true;
	myPattern[6][11].alive = true;
	myPattern[7][11].alive = true;

	myPattern[4][12].alive = true;
	myPattern[8][12].alive = true;


	myPattern[3][13].alive = true;
	myPattern[3][14].alive = true;
	myPattern[9][13].alive = true;
	myPattern[9][14].alive = true;
	myPattern[6][15].alive = true;

	myPattern[4][16].alive = true;
	myPattern[8][16].alive = true;
	myPattern[5][17].alive = true;
	myPattern[6][17].alive = true;
	myPattern[7][17].alive = true;
	myPattern[6][18].alive = true;

	myPattern[3][21].alive = true;
	myPattern[4][21].alive = true;
	myPattern[5][21].alive = true;
	myPattern[3][22].alive = true;
	myPattern[4][22].alive = true;
	myPattern[5][22].alive = true;

	myPattern[2][23].alive = true;
	myPattern[6][23].alive = true;
	myPattern[1][25].alive = true;
	myPattern[2][25].alive = true;
	myPattern[6][25].alive = true;
	myPattern[7][25].alive = true;

	myPattern[3][35].alive = true;
	myPattern[3][36].alive = true;
	myPattern[4][35].alive = true;
	myPattern[4][36].alive = true;
}