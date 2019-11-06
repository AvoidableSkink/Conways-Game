#include "PatternBlinker.hpp"

PatternBlinker::PatternBlinker() {
  sizeX = 5;
  sizeY = 3;
  // fill up your pattern with non-active, dead cells
  for (size_t y = 0; y < sizeY; y++) {
    std::vector<cell> tmp;
    myPattern.push_back(tmp);
    for (size_t x = 0; x < sizeX; x++) {
      cell tmp;
      tmp.alive = false;
      myPattern[y].push_back(tmp);
    }
  }
  populatePattern();
}

// getters
std::uint8_t PatternBlinker::getSizeX() const { return sizeX; };
std::uint8_t PatternBlinker::getSizeY() const { return sizeY; };

// Returns true if the cell in the pattern is filled, false otherwise.
bool PatternBlinker::getCell(std::uint8_t x, std::uint8_t y) const {
  if (myPattern[y][x].alive == true) {
    return true;
  } else {
    return false;
  }
}

// fill up your pattern that looks like this
// std::vector<std::vector<cell>> myPattern;
void PatternBlinker::populatePattern() {
  // just brute force it man
  myPattern[1][1].alive = true;
  myPattern[1][2].alive = true;
  myPattern[1][3].alive = true;
}