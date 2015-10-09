#pragma once
class Cell;
#include <string>
#include <vector>

class Board
{
public:
	Board();
	~Board();
	
	bool LoadBoard(std::string);
	bool Calculate();
	bool SaveBoard(std::string);
private:
	void Swap(Cell*&,Cell*&);

public:
	Cell* board;
private:
	int width, height;
	int index = 0;
};

