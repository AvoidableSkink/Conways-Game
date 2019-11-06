#pragma once
#include "Pattern.hpp"

class PatternAcorn : public Pattern {

private:
	void populatePattern();

public:
	//constructor
	PatternAcorn();

	//Returns the horizontal width(in cells) of the pattern.
	std::uint8_t getSizeX() const { return sizeX; };

	//Returns the vertical height(in cells) of the pattern.
	std::uint8_t getSizeY() const { return sizeY; };

	//Returns true if the cell in the pattern is filled, false otherwise.
	bool getCell(std::uint8_t x, std::uint8_t y);

};