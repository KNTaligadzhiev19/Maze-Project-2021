#include "Log.h"

void Log::getCurrentTime()
{
	logData << "The current date is: " << DATE << std::endl;
	logData << "The current time is: " << TIME << std::endl;
}

std::string Log::getCurrentStatus(int status)
{
	switch (status)
	{
	case 1:
		return "Program Beggining\n";
	case 2:
		return "Print User Menu\n";
	case 3:
		return "Registration\n";
	case 4:
		return "Logging\n";
	case 5:
		return "Print Player Menu\n";
	case 6:
		return "Playing Easy Level Maze\n";
	case 7:
		return "Playing Medium Level Maze\n";
	case 8:
		return "Playing Hard Level Maze\n";
	case 9:
		return "Print Rules\n";
	}
}

Log::Log(int status)
{
	std::string statusMessage;

	statusMessage = getCurrentStatus(status);

	logData.open("Logs.txt", std::ios::out | std::ios::trunc);

	if (logData.is_open())
	{
		getCurrentTime();
		logData << statusMessage;
	}

	logData.close();
}