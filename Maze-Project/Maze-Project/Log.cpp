#include "Log.h"

void Log::getCurrentTime()
{
	logData << "The current date is: " << DATE;
	logData << "The current time is: " << TIME;
}

void Log::getCurrentStatus(int status)
{
	logData.open("Logs.txt", std::ios::out | std::ios::app);

	if (logData.is_open())
	{
		getCurrentTime();

		switch (status)
		{
		case 1:
			logData<< "Print User Menu\n";
		case 2:
			logData << "Registration\n";
		case 3:
			logData<< "Logging\n";
		case 4:
			logData << "Print Player Menu\n";
		case 5:
			logData << "Playing Easy Level Maze\n";
		case 6:
			logData << "Playing Medium Level Maze\n";
		case 7:
			logData << "Playing Hard Level Maze\n";
		case 8:
			logData << "Print Rules\n";
		}
	}

	logData.close();
}

Log::Log(int status)
{
	logData.open("Logs.txt", std::ios::out | std::ios::trunc);

	if (logData.is_open())
	{
		getCurrentTime();
		logData << "Beggining\n";
	}

	logData.close();
}

Log::~Log()
{
	logData.open("Logs.txt", std::ios::out | std::ios::app);

	if (logData.is_open())
	{
		getCurrentTime();
		logData << "End";
	}

	logData.close();
}