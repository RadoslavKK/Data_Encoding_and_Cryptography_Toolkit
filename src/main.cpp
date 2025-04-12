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
#include "FilePathManager.h"

// Remove white space from key
#include "removeSpaces.h"

// Validate the Base64 Key
#include "base64KeyValidator.h"

// Validate the Base62 Key
#include "base62KeyValidator.h"

// Base62 Encoder
#include "base62Encoder.h"

// Base64 Encoder
#include "base64Encoder.h"

// Base64 Decoder
#include "base64Decoder.h"

// ____________ bin, oct, dec, hex Valitation. ____________

// Binary Code Validation
#include "binaryValidator.h"

// Hex Code Valitation
#include "hexValidator.h"

// ____________ /bin, oct, dec, hex Valitation. ____________

// Convert Binary to Oct, Dec, Hex
#include "binaryToConverter.h"

// ____________________________ /Include Header Files. ____________________________

// Start Base62 Encoder
#include "executeBase62Encoder.h"

// Start Base64 Encoder
#include "executeBase64Encoder.h"

// Start Base64 Decoder
#include "executeBase64Decoder.h"

// Start Binary to Oct, Dec, Hex Convertor
#include "executeBinary.h"

int main(int argc, char *argv[])
{
    const std::string const_ToolKitVersion = "Encoding ToolKit++ Ver. 2.0";

    // Print current time
    TimePrinter time;
    time.printTime();

    // ____________________________ Set key file paths. ____________________________
    FilePathManager::getInstance().setBase64KeyPath("/Users/radoslavkostov/Documents/Repositories/C++/EncodingToolkit++/keys/base64Key.txt");
    FilePathManager::getInstance().setBase62KeyPath("/Users/radoslavkostov/Documents/Repositories/C++/EncodingToolkit++/keys/base62Key.txt");
    // ____________________________ Set key file paths. ____________________________

    // Store File Path for (Base64/Base62) key storage fikes
    std::string filePath = "";

    // Create obj to Read Files.
    FileReader reader;

    // Create obj to Remove White Space
    StringFormatter remover;

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

    // ANSI escape codes for clearing screen
    std::cout << "\033[2J\033[H";
    printMenu();

    do
    {
        std::cout << ">>> ";
        menuInput = "";

        std::getline(std::cin, menuInput);

        // Remove white space from User Input
        menuInput = remover.removeSpaces(menuInput);

        menuInput = correctCommand(menuInput);

        /*

        // Translate User Command Input to ENUM
        CommandType command = getCommandType(menuInput);

        switch (command)
        {
        case CMD_MENU:
            printMenu();
            break;
        case CMD_HELP:
            printHelp();
            break;
        case CMD_ALL:
            printAllCommands();
            break;
        case CMD_CLEAR:
            system("clear");
            break;
        case CMD_EXIT:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Unknown command. Type 'menu' or 'help'.\n";
        }

        */

        if (menuInput == "menu")
        {
            printMenu();
        }
        else if (menuInput == "help")
        {
            printHelp();
        }
        else if (menuInput == "all")
        {
            printAllCommands();
        }
        else if (menuInput == "clear")
        {
            // ANSI escape codes for clearing screen
            std::cout << "\033[2J\033[H";
        }
        else if (menuInput == "time")
        {
            time.printTime();
        }
        else if (menuInput == "encode64")
        {
            executeBase64Encoder();
        }
        else if (menuInput == "decode64")
        {
            executeBase64Decoder();
        }
        else if (menuInput == "encode62")
        {
            executeBase62Encoder();
        }
        else if (menuInput == "decode62")
        {
            // Add soon.
        }
        else if (menuInput == "binary")
        {
            executeBinary();
        }
        else if (menuInput == "hex")
        {
            inputText = "";
            std::cout << "\nEnter a hex string (without spaces) : ";

            // Capture user input
            std::getline(std::cin, inputText);

            inputText = remover.removeSpaces(inputText);

            if (isValidHex(inputText))
            {
                std::cout << ("\nValid Hex\n\n");
            }
            else
            {
                std::cout << ("\nNot a Valid Hex\n\n");
            }

            inputText = "";
        }
        else if (menuInput == "exit")
        {
        }
        else if (menuInput == "version")
        {
            // Clear the Buffer
            std::cout << "\n"
                      << const_ToolKitVersion << "\n"
                      << std::endl;
        }

        // If Not a Valid Command
        else if (menuInput != "")
        {
            // Clear the Buffer
            std::cout << "\nToolKit ++: command not found: " << menuInput << "\n"
                      << std::endl;
        }

    } while (menuInput != "exit");

    // Clear the Buffer
    std::cout << "Exiting..." << std::endl;

    return 0;
}