#include "checkOS.h"

std::string checkOS()
{
    std::string osName = "";

#if defined(_WIN32) || defined(_WIN64)
    osName = "Windows";
#elif defined(__linux__)
    osName = "Linux";
#elif defined(__APPLE__) || defined(__MACH__)
    osName = "macOS";
#elif defined(__unix__)
    osName = "UNIX";
#else
    osName = "Unknown Operating System";
#endif

    return osName;
}