#include <iostream>

#include "timePrinter.h"

// For Time
#include <ctime>

void TimePrinter::printTime()
{
    // Get the current time as a time_t object
    std::time_t now = std::time(0); // same as time(NULL)

    // Convert to local time structure
    std::tm *localTime = std::localtime(&now);

    // Print the time in YYYY-MM-DD HH:MM:SS format
    std::cout << "Current time: "
              << (1900 + localTime->tm_year) << "-"
              << (1 + localTime->tm_mon) << "-"
              << localTime->tm_mday << " "
              << localTime->tm_hour << ":"
              << localTime->tm_min << ":"
              << localTime->tm_sec << std::endl;
};