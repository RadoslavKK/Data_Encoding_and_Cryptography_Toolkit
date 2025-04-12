/*
____________________________ How to Run the Program. ____________________________

1. Open a Terminal window.

2. Navigate to the project directory:
   cd EncodingToolkit++    // Change to the project directory.

3. Build the program:
   make                    // Compile the project and generate the executable.

4. Run the program:
   make run                // Execute the program.

5. Clean the build files:
   make clean              // Remove compiled files and clean up the project.
*/

// ____________________________ Include Header Files. ____________________________

#include <iostream>

// User Input to Lower Case
#include "toLowerCase.h"

// User Input Command Corrector
#include "commandCorrector.h"

// User Command Input to ENUM
#include "commandType.h"

// Print the Time
#include "timePrinter.h"

// Print Menu and Help Options
#include "printOptions.h"

// Open and Read Files
#include "fileReader.h"

// Base64 and Base62 Key File's Path
#include "filePathManager.h"

// Remove white space from key
#include "removeSpaces.h"

// Start Base62 Encoder
#include "executeBase62Encoder.h"

// Start Base64 Encoder
#include "executeBase64Encoder.h"

// Start Base64 Decoder
#include "executeBase64Decoder.h"

// Star a Base64 Encode & Decoder Test
#include "executeBase64Test.h"

// Start Binary to Oct, Dec, Hex Convertor
#include "executeBinary.h"

// Star Hex
#include "executeHex.h"

int main(int argc, char *argv[])
{
    const std::string const_ToolKitVersion = "Encoding ToolKit++ Ver. 2.0";

    // ____________________________ Set key file paths. ____________________________
    FilePathManager::getInstance().setBase64KeyPath("/Users/radoslavkostov/Documents/Repositories/C++/EncodingToolkit++/keys/base64Key.txt");
    FilePathManager::getInstance().setBase62KeyPath("/Users/radoslavkostov/Documents/Repositories/C++/EncodingToolkit++/keys/base62Key.txt");
    // ____________________________ Set key file paths. ____________________________

    // Create obj to Print current time
    TimePrinter time;

    // Create obj to Read Files.
    FileReader reader;

    // Create obj to Remove White Space
    StringFormatter remover;

    // ____________________________ Program Print Config Options ____________________________

    bool clearScreenAtProgramStart = true;

    if (clearScreenAtProgramStart)
    {
        // ANSI escape codes for clearing screen
        std::cout << "\033[2J\033[H";
    }

    // ______________________________________________________________________________________

    bool runBase64TestAsprogramStart = true;

    if (runBase64TestAsprogramStart)
    {
        executeBase64Test();
    }

    // ______________________________________________________________________________________

    bool printTimeAtProgramStart = true;

    if (printTimeAtProgramStart)
    {
        time.printTime();
    }

    // ______________________________________________________________________________________

    bool printMenuAtProgramStart = true;

    if (printMenuAtProgramStart)
    {
        printMenu();
    }

    // ______________________________________________________________________________________

    // Store File Path for (Base64/Base62) key storage files
    std::string filePath = "";

    //________________________________________________________

    // Store Input of (Base64/Base62) Encoder and Decoder
    std::string inputText = "";

    // Store Output of (Base64/Base62) Encoder and Decoder
    std::string outputText = "";

    //________________________________________________________

    // Store Result
    std::string result = "";

    // Store User Input for Menu Options
    std::string menuInput = "";

    // Store Original User Input for Menu Options Before : White Space Remover & To Lower Case
    std::string originalUserInput = "";

    do
    {
        std::cout << ">>> ";
        menuInput = "";

        std::getline(std::cin, menuInput);

        originalUserInput = menuInput;

        // Remove white space from User Input
        menuInput = remover.removeSpaces(menuInput);

        // User Input to Lower Case
        menuInput = toLowerCase(menuInput);

        // User Input Spell Checker
        menuInput = correctCommand(menuInput);

        // Translate User Command Input to ENUM
        CommandType command = getCommandType(menuInput);

        switch (command)
        {
        case CMD_EMPTY:
            break;

        case CMD_MENU:
            printMenu();
            break;

        case CMD_HELP:
            printHelp();
            break;

        case CMD_ALL:
            printAllCommands();
            break;

        case CMD_TIME:
            time.printTime();
            break;

        case CMD_CLEAR:
            system("clear");
            break;

        case CMD_ENCODE62:
            executeBase62Encoder();
            break;

        case CMD_ENCODE64:
            executeBase64Encoder();
            break;

        case CMD_DECODE64:
            executeBase64Decoder();
            break;

        case CMD_BINARY:
            executeBinary();
            break;

        case CMD_HEX:
            executeHex();
            break;

        case CMD_TEST:
            executeBase64Test();
            break;

        case CMD_VERSION:
            // Clear the Buffer
            std::cout << "\n"
                      << const_ToolKitVersion << "\n"
                      << std::endl;
            break;

        case CMD_EXIT:
            std::cout << "Exiting...\n";
            return 0;

        default:
            // Clear the Buffer
            std::cout << "\nToolKit ++: command not found: " << originalUserInput << "\n"
                      << std::endl;
        }

    } while (menuInput != "exit");

    // Clear the Buffer
    std::cout << "Exiting..." << std::endl;

    return 0;
}