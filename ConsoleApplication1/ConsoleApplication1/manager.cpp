#include "manager.h"
#include "board.h"
#include <fstream>
#include <streambuf>
#include <iostream>
#include <algorithm>

Manager::Manager()
{
}


Manager::~Manager()
{
}

bool Manager::ParseIn(int argc, char *argv[])
{
	bool result;
	using namespace std;
	Board board;
	for (int i = 0; i < argc; i++)
	{
		string cmd(argv[i]);
		if (cmd =="--load")
		{
			locationIn = argv[i + 1];
			cout << locationIn << "\n";
		}
		if (cmd == "--generations")
		{
			generations =atoi(argv[i + 1]);
			cout << generations << ":Generations \n";
		}
		if (cmd == "--save")
		{
			locationOut = argv[i + 1];
			cout << locationOut << "\n";
		}
		if (cmd == "--measure")
		{

		}
	}

	start_time = Time::now();
		result = board.LoadBoard(locationIn);
		if (!result) false;
	end_time = Time::now();
	fsec fs = end_time - start_time;
	cout << fs.count() << ": needed to complete File Read! \n";
	
	start_time = Time::now();
	for (int i = 0; i < generations; i++)
	{
		result = board.Calculate();
		if (!result) return false;
	}
	end_time = Time::now();
	fs = end_time - start_time;
	cout << fs.count() << ": needed to complete Generations \n";
	
	start_time = Time::now();
		result = board.SaveBoard(locationOut);
		if (!result) return false;
	end_time = Time::now();
	fs = end_time - start_time;
	cout << fs.count() << ": needed to complete File Write \n";
	return true;
}

