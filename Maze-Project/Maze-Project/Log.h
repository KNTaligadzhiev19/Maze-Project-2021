#pragma once
#include <fstream>
#include <string>



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

