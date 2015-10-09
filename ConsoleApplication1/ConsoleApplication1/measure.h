#pragma once
#include <vector>
#include <chrono>
#include <fstream>
#include <string>

class Measure
{
public:
	Measure();
	~Measure();
	void startMeasure();
	void stopMeasure();
	void saveMeasures(std::string);
public:
	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::milliseconds ms;
	typedef std::chrono::duration<float> fsec;

	std::chrono::high_resolution_clock::time_point start_time;
	std::chrono::high_resolution_clock::time_point end_time;
private:
	std::vector<float> times;
};

