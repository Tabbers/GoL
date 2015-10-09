#pragma once
#include <chrono>
#include <string>

class Manager
{
public:
	Manager();
	~Manager();
public:
	bool ParseIn(int, char*[]);
public:
	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::milliseconds ms;
	typedef std::chrono::duration<float> fsec;

	std::chrono::high_resolution_clock::time_point start_time;
	std::chrono::high_resolution_clock::time_point end_time;
private:

	bool measure = false;
	std::string locationIn, locationOut;
	int generations;

};

