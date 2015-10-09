#include "manager.h"
#include "board.h"
#include "measure.h"
#include <fstream>
#include <streambuf>
#include <algorithm>
#include <iostream>

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
	Measure mestime;
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
			measure = 1;
		}
	}

		if (measure) mestime.startMeasure();
		result = board.LoadBoard(locationIn);
		if (!result) false;
	if (measure) mestime.stopMeasure();
	
	if (measure) mestime.startMeasure();
		for (int i = 0; i < generations; i++)
		{
			result = board.Calculate();
			if (!result) return false;
		}
	if (measure) mestime.stopMeasure();
	
	if (measure) mestime.startMeasure();
		result = board.SaveBoard(locationOut);
		if (!result) return false;
	if (measure)
	{
		mestime.stopMeasure();
		mestime.saveMeasures("times.gol");
	}
	return true;
}

