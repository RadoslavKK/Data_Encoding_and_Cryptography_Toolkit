#include "printMenu.h"
#include <iostream>

void printMenu()
{
    std::cout << "\n|=========================================|\n"
              << "|                                         |\n"
              << "| menu     // Show the Menu               |\n"
              << "| encode62 // Base62 Enclode a String     |\n"
              << "| encode64 // Base64 Enclode a String     |\n"
              << "| decode64 // Base64 Decolder a String    |\n"
              << "| clear    // Clear Screen                |\n"
              << "| test     // Base64 Encoding Test        |\n"
              << "| exit     // Exit Program                |\n"
              << "|                                         |\n"
              << "|=========================================|\n\n";
}