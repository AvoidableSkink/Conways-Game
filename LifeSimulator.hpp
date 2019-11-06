#pragma once
#include <iostream>
#include <cstdint>

#include "Pattern.hpp"

class LifeSimulator
{

private:
	struct cell {
		bool active;
		bool alive;
	};
	std::uint8_t sizeX;
	std::uint8_t sizeY;

	std::vector<std::vector<cell>> currentState;
	std::vector<std::vector<cell>> newState;

public:
	//The constructor accepts a sizeXand sizeY indicating the size of the world.
	//You'll want to set these equal to the width/height of the console the program runs within.
	LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY);

	//insertPattern - Adds the pattern to the world, with the upper left corner beginning at startXand startY.
	void insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY);
	//update - Performs a single step update of the world, following the four rules specified in the wiki article.
	void update();

	//getSizeX and getSizeY - Return the size of the world.
	std::uint8_t getSizeX() const { return sizeX; };
	std::uint8_t getSizeY() const { return sizeY; };
	
	//getCell - Returns true if the world cell is alive, false otherwise.
	bool getCell(std::uint8_t x, std::uint8_t y) const;

};