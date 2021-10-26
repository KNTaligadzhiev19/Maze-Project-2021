#pragma once
#include <fstream>
#include <string>

class Logger
{
private:
	std::ofstream logData;

public:

	void pushCurrentTime();

	void getCurrentStatus(int status);

	Logger();

	~Logger();
};

