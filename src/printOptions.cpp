#include "printOptions.h"
#include <iostream>

void printMenu()
{
    std::cout << "\n|================================ Main Menu ================================|\n"
              << "|                                                                           |\n"
              << "| menu       -> Show the Menu                                               |\n"
              << "| help       -> Show this detailed help guide with explanations.            |\n"
              << "| encode62   -> Base62 Encode a String                                      |\n"
              << "| encode64   -> Base64 Encode a String                                      |\n"
              << "| decode64   -> Base64 Decode a String                                      |\n"
              << "| binary     -> Convert Binary to DEC, HEX, or OCT                          |\n"
              << "| clear      -> Clear the terminal screen                                   |\n"
              << "| test       -> Run Base64 encoding test                                    |\n"
              << "| version    -> Show Encoding Toolkit++ version number                      |\n"
              << "| exit       -> Exit the program                                            |\n"
              << "|                                                                           |\n"
              << "|===========================================================================|\n\n";
}

void printHelp()
{
    std::cout << "\n|=========================== Help & Usage Guide ============================|\n"
              << "|                                                                           |\n"
              << "| menu       -> Display the main menu with all primary commands.            |\n"
              << "| help       -> Show this detailed help guide with explanations.            |\n"
              << "|                                                                           |\n"
              << "| encode62   -> Encode a plain text string using Base62 encoding.           |\n"
              << "|              Example: 'hello' => 'T8dgcjRGuYUueWht'                       |\n"
              << "|                                                                           |\n"
              << "| encode64   -> Encode a plain text string using Base64 encoding.           |\n"
              << "|              Example: 'hello' => 'aGVsbG8='                               |\n"
              << "|                                                                           |\n"
              << "| decode64   -> Decode a Base64-encoded string back to its original form.   |\n"
              << "|              Example: 'aGVsbG8=' => 'hello'                               |\n"
              << "|                                                                           |\n"
              << "| binary     -> Convert binary numbers to decimal, hexadecimal, or octal.   |\n"
              << "|              Example: '0b1010' => DEC: 10, HEX: A, OCT: 12                |\n"
              << "|                                                                           |\n"
             // << "| isbinary   -> Check whether a string is a valid binary sequence.          |\n" Add soon.
             // << "|              Accepts '0b' or 'ob' prefixes (e.g., 0b1101).                |\n"
             // << "|                                                                           |\n"
              << "| clear      -> Clears the screen. Also accepts: 'cls', 'clean', etc.       |\n"
              << "| test       -> Run a Base64 encode/decode test to validate functionality.  |\n"
              << "| version    -> Print the version number of Encoding Toolkit++.             |\n"
              << "| exit       -> Exit the program safely.                                    |\n"
              << "|                                                                           |\n"
              << "| Notes:                                                                    |\n"
              << "| - Commands are case-insensitive and support common misspellings.          |\n"
              << "| - Use 'all' to view every recognized command and alias.                   |\n"
              << "|                                                                           |\n"
              << "|===========================================================================|\n\n";
}


void printAllCommands()
{
    std::cout << "\n|======================== All Recognized Commands ==========================|\n"
              << "|                                                                           |\n"
              << "| menu, meun, mneu, mnue       -> Show the main menu                        |\n"
              << "| help, hepl, hlep, hell       -> Show help and usage                       |\n"
              << "| encode62                     -> Encode a string to Base62                 |\n"
              << "| encode64                     -> Encode a string to Base64                 |\n"
              << "| decode64                     -> Decode a Base64 string                    |\n"
              << "| binary                       -> Convert binary to dec/hex/oct             |\n"
            //  << "| isbinary                     -> Check if a string is binary               |\n" Add soon.
              << "| clear, cls, clx, clean       -> Clear the screen                          |\n"
              << "| test                         -> Run base64 encoding test                  |\n"
              << "| version, verion, versoin     -> Show version number                       |\n"
              << "| exit, exiit, exti            -> Exit the program                          |\n"
              << "|                                                                           |\n"
              << "|===========================================================================|\n\n";
}
