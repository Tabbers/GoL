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
	void Swap(int*&,int*&);

public:
	int* board;
	int* board2;
private:
	int width, height;
	int index = 0;
};

