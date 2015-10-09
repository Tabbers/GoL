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
	board  = new int[width*height];
	board2 = new int[width*height];
	getline(file, str);
	// read character for character
	while (getline(file, str))
	{
		for (char& c : str) 
		{
			board[i] = c == 'x';
			i++;
		}
	}
	file.close();
	return true;
}

bool Board::Calculate()
{
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
			if (x == width-1)	diffXR = -width;


			/*UL*/lcnt += board[x - 1 + diffXL + width*(y - 1 + diffYU)];
			/*U*/ lcnt += board[x +			     width*(y - 1 + diffYU)];
			/*UR*/lcnt += board[x + 1 + diffXR + width*(y - 1 + diffYU)];

			/*L*/ lcnt += board[x - 1 + diffXL + width*y];
			/*R*/ lcnt += board[x + 1 + diffXR + width*y];

			/*DL*/lcnt += board[x - 1 + diffXL + width*(y + 1 + diffYD)];
			/*D*/ lcnt += board[x +			     width*(y + 1 + diffYD)];
			/*DR*/lcnt += board[x + 1 + diffXR + width*(y + 1 + diffYD)];

			if(board[x+(width*y)])
			{
				if (lcnt <2  || lcnt > 3)   board2[x + (width*y)] = 0;
				if (lcnt ==2 || lcnt == 3) board2[x + (width*y)] = 1;
			}
			else
			{
				if (lcnt == 3) board2[x + (width*y)] = 1;
			}
		}
	}
	Swap(board, board2);
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
			if(board[x + width*y]) file.put('x');
			else  file.put('.');
		}
	}
	file.close();
	return true;
}

void Board::Swap(int *&r, int *&s)
{
	int* temp = r;
	r = s;
	s = temp;

	memcpy(s,r,sizeof(int)*width*height);
	return;
}
