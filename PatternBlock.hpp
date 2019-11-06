#pragma once

#include "Pattern.hpp"

class PatternBlock : public Pattern {

private:
	void populatePattern();

public:
	//constructor
	PatternBlock();

	//Returns the horizontal width(in cells) of the pattern.
	std::uint8_t getSizeX() const;

	//Returns the vertical height(in cells) of the pattern.
	std::uint8_t getSizeY() const;

	//Returns true if the cell in the pattern is filled, false otherwise.
	bool getCell(std::uint8_t x, std::uint8_t y) const;

};