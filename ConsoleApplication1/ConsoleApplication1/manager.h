#pragma once
#include <string>

class Manager
{
public:
	Manager();
	~Manager();
public:
	bool ParseIn(int, char*[]);
private:
	int measure = 0;
	std::string locationIn, locationOut;
	int generations;

};

