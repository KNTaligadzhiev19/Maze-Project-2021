#pragma once
#include <fstream>
#include <string>

#define DATE system("date/t")
#define TIME system("time/t")

class Log
{
private:
	std::ofstream logData;

public:
	void getCurrentTime();

	std::string getCurrentStatus(int status);

	Log();

	~Log();
};

