#include "../Header Files/Logger.h"

std::string getCurrentTime()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int hour = newtime.tm_hour;
	int minutes = newtime.tm_min;
	int seconds = newtime.tm_sec;
	int day = newtime.tm_mday;
	int month = 1 + newtime.tm_mon;
	int year = 1900 + newtime.tm_year;

	std::string time;
	time += "On " + std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year) + ", At " + std::to_string(hour) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds) + "\n";

	return time;
}

void Logger::pushCurrentTime()
{
	std::string time = getCurrentTime();

	logData << time;
}

void Logger::getCurrentStatus(int status)
{
	logData.open("Logs.txt", std::ios::out | std::ios::app);

	if (logData.is_open())
	{
		pushCurrentTime();

		switch (status)
		{
		case 1:
			logData << "Print User Menu\n";
			break;
		case 2:
			logData << "Registration\n";
			break;
		case 3:
			logData << "Logging\n";
			break;
		case 4:
			logData << "Print Player Menu\n";
			break;
		case 5:
			logData << "Playing Easy Level Maze\n";
			break;
		case 6:
			logData << "Playing Medium Level Maze\n";
			break;
		case 7:
			logData << "Playing Hard Level Maze\n";
			break;
		case 8:
			logData << "Print Rules\n";
			break;
		}
	}

	logData.close();
}

Logger::Logger()
{
	logData.open("Logs.txt", std::ios::out | std::ios::trunc);

	if (logData.is_open())
	{
		pushCurrentTime();
		logData << "Beggining\n";
	}

	logData.close();
}

Logger::~Logger()
{
	logData.open("Logs.txt", std::ios::out | std::ios::app);

	if (logData.is_open())
	{
		pushCurrentTime();
		logData << "End";
	}

	logData.close();
}