#include "printOptions.h"
#include <iostream>

void printMenu()
{
    std::cout << "\n|=======================================================|\n"
              << "|                                                       |\n"
              << "| menu     // Show the Menu                             |\n"
              << "| help     // Show how to use the Program               |\n"
              << "| encode62 // Base62 Encode a String                    |\n"
              << "| encode64 // Base64 Encode a String                    |\n"
              << "| decode64 // Base64 Decode a String                    |\n"
              << "| binary   // Convert Binary to : DEC, HEX, OCT         |\n"
              << "| isbinary // Check if Valid Binary Stream              |\n"
              << "| clear    // Clear Screen                              |\n"
              << "| test     // Base64 Encoding Test                      |\n"
              << "| vesrion  // Print Encoding ToolKit++ Ver. Number      |\n"
              << "| exit     // Exit Program                              |\n"
              << "|                                                       |\n"
              << "|=======================================================|\n\n";
}

void printHelp()
{
    std::cout << "\n|=================================================================================================|\n"
              << "|                                                                                                 |\n"
              << "| menu     // Show all of the Prgoram Options                                                     |\n"
              << "| help     // Show more info on how to use the Program                                            |\n"
              << "| encode62 // Encode a String to Base62 (Just enter a text String) and recive the Encoded Data    |\n"
              << "| encode64 // Encode a String to Base64 (Just enter a text String) and recive the Encoded Data    |\n"
              << "| decode64 // Decode a Base64 String (Just enter a text String) and recive the Decoded Data       |\n"
              << "| binary   // Convert Binary to : DEC, HEX, OCT                                                   |\n"
              << "| isbinary // Check if Valid Binary Stream                                                        |\n"
              << "| clear    // Clear Screen                                                                        |\n"
              << "| test     // Base64 Encoding Test                                                                |\n"
              << "| exit     // Exit Program                                                                        |\n"
              << "|                                                                                                 |\n"
              << "|=================================================================================================|\n\n";
}