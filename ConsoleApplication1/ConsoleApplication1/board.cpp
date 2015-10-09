#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "board.h"
#include "cell.h"


Board::Board()
{
}


Board::~Board()
{
}

bool Board::LoadBoard(std::string load)
{
	using namespace std;
	ifstream file(load);
	string str;
	int i = 0;
	char trash;

	file >> width >> trash >> height;
	cout << width << "\n" << height << "\n";
	board  = new Cell[width*height];
	getline(file, str);
	// read character for character
	while (getline(file, str))
	{
		for (char& c : str) 
		{
			board[i].alive = c == 'x';
			i++;
		}
	}
	file.close();
	return true;
}

bool Board::Calculate()
{
	Cell* board2 = new Cell[width*height];
	int lcnt;
	int diffXR = 0;
	int diffYD = 0;
	int diffXL = 0;
	int diffYU = 0;
	using namespace std;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			lcnt = 0;
			diffXR = 0;
			diffXL = 0;
			diffYU = 0;
			diffYD = 0;

			// Spezialfälle für 
			if (y == 0)			diffYU = height;
			if (y == height-1)	diffYD = -height;
			if (x == 0)			diffXL = width;
			if (x == width-1)		diffXR = -width;


			/*UL*/lcnt += board[x - 1 + diffXL + width*(y - 1 + diffYU)].alive;
			/*U*/ lcnt += board[x +			  width*(y - 1 + diffYU)].alive;
			/*UR*/lcnt += board[x + 1 + diffXR + width*(y - 1 + diffYU)].alive;

			/*L*/lcnt += board[x - 1 + diffXL + width*y].alive;
			/*R*/lcnt += board[x + 1 + diffXR + width*y].alive;

			/*DL*/lcnt += board[x - 1 + diffXL + width*(y + 1 + diffYD)].alive;
			/*D*/ lcnt += board[x +			  width*(y + 1 + diffYD)].alive;
			/*DR*/lcnt += board[x + 1 + diffXR + width*(y + 1 + diffYD)].alive;

			if(board[x+(width*y)].alive)
			{
				if (lcnt <2 || lcnt > 3)   board2[x + (width*y)].alive = 0;
				if (lcnt ==2 || lcnt == 3) board2[x + (width*y)].alive = 1;
			}
			else
			{
				if (lcnt == 3) board2[x + (width*y)].alive = 1;
			}
		}
	}
	Swap(board, board2);
	delete[] board2;
	return true;
}

bool Board::SaveBoard(std::string load)
{
	using namespace std;
	ofstream file(load);
	file << width << ',' << height;
	for (int y = 0; y < height; y++)
	{
		file.put('\n');
		for (int x = 0; x < width; x++)
		{
			if(board[x + width*y].alive) file.put('x');
			else  file.put('.');
		}
	}
	file.close();
	return true;
}

void Board::Swap(Cell *&r, Cell *&s)
{
	Cell* temp = r;
	r = s;
	s = temp;
	return;
}
