#include "Log.h"

void Log::getCurrentTime()
{
	logData << "The current date is: " << DATE << std::endl;
	logData << "The current time is: " << TIME << std::endl;
}

