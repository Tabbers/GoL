#include "measure.h"
#include <iostream>


Measure::Measure()
{
}


Measure::~Measure()
{
}

void Measure::startMeasure()
{
	start_time = Time::now();
}

void Measure::stopMeasure()
{
	end_time = Time::now();
	fsec fs = end_time - start_time;
	times.push_back(fs.count());
	std::cout << fs.count() << " :needed! \n";
}

void Measure::saveMeasures(std::string Filename)
{
	using namespace std;
	ofstream file;
	for (int i = 0; i < times.size(); i++)
	{
		file.put(times[i]);
		file.put('\n');
	}
}
