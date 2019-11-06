#pragma once

#include <iostream>
#include <cstdint>
#include <vector>

class Pattern
{
protected:
	struct cell {
		bool active; // maybe ?
		bool alive;
	}; 
	std::uint8_t sizeX;
	std::uint8_t sizeY;
	std::vector<std::vector<cell>> myPattern;
	

public:
	//Returns the horizontal width(in cells) of the pattern.
	virtual std::uint8_t getSizeX() const = 0;
	
	//Returns the vertical height(in cells) of the pattern.
	virtual std::uint8_t getSizeY() const = 0;
	
	//Returns true if the cell in the pattern is filled, false otherwise.
	virtual bool getCell(std::uint8_t x, std::uint8_t y) const = 0;

};