#include <iostream>

/*
____________________________ How to Run. ____________________________

Open a Terminal

cd EncodingToolkit++
make
make run
make clean
*/

// ____________________________ Include Header Files. ____________________________

// User Input Command Corrector
#include "commandCorrector.h"

// Print the Time
#include "timePrinter.h"

// Print Menu and Help Options
#include "printOptions.h"

// Open and Read Files
#include "fileReader.h"

// Base64 and Base62 Key File's Path
#include "filePath.h"

// Remove white space from key
#include "removeSpaces.h"

// Validate the Base64 Key
#include "base64KeyValidator.h"
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

int main(int argc, char *argv[])
{
    const std::string const_ToolKitVersion = "Encoding ToolKit++ Ver. 2.0";

    // Print current time
    TimePrinter time;
    time.printTime();

    // ____________________________ Set key file paths. ____________________________
    FilePath paths;
    paths.setBase64KeyPath("/Users/radoslavkostov/Documents/Repositories/C++/EncodingToolkit++/keys/base64Key.txt");
    paths.setBase62KeyPath("/Users/radoslavkostov/Documents/Repositories/C++/EncodingToolkit++/keys/base62Key.txt");
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

    // Store if Valid (Base64/Base62) key
    bool key = false;

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
            inputText = "";

            filePath = paths.getBase64KeyPath();
            result = reader.read(filePath);
            // std::cout << "Base64 File Contents : \"" << result << "\"" << std::endl;

            result = remover.removeSpaces(result);
            // std::cout << "Base64 File Contents : \"" << result << "\"" << std::endl;

            Base64KeyValidator keyValidator64;
            key = keyValidator64.validate64(result);

            if (key)
            {
                std::cout << "\nValid Base64 Key\n";
            }
            else
            {
                std::cout << "\nNot a Valid Base64 Key\n";
            }

            std::cout << "\nEncode a String to Base64 (Simply enter your data then push the Enter/Return button) : ";

            // Capture user input
            std::getline(std::cin, inputText);

            outputText = base64Encoder(inputText, result);
            std::cout << "\n\"" << inputText << "\" to Base64 : \"" << outputText << "\"\n"
                      << std::endl;

            result = "";
            inputText = "";
            outputText = "";
            filePath = "";
            key = false;
        }
        else if (menuInput == "decode64")
        {
            inputText = "";

            filePath = paths.getBase64KeyPath();
            result = reader.read(filePath);
            // std::cout << "Base64 File Contents : \"" << result << "\"" << std::endl;

            result = remover.removeSpaces(result);
            // std::cout << "Base64 File Contents : \"" << result << "\"" << std::endl;

            Base64KeyValidator keyValidator64;
            key = keyValidator64.validate64(result);

            if (key)
            {
                std::cout << "\nValid Base64 Key\n";
            }
            else
            {
                std::cout << "\nNot a Valid Base64 Key\n";
            }

            std::cout << "\nDecode a Base64 String (Simply enter your data then push the Enter/Return button) : ";

            // Capture user input
            std::getline(std::cin, inputText);

            outputText = base64Decoder(inputText, result);
            std::cout << "\nFrom Base64 : \"" << inputText << "\" to Readable : \"" << outputText << "\"\n"
                      << std::endl;

            result = "";
            outputText = "";
            inputText = "";
            filePath = "";
            key = false;
        }
        else if (menuInput == "encode62")
        {
            inputText = "";

            filePath = paths.getBase62KeyPath();
            result = reader.read(filePath);
            // std::cout << "Base62 File Contents : \"" << result << "\"" << std::endl;

            result = remover.removeSpaces(result);
            // std::cout << "Base62 File Contents : \"" << result << "\"" << std::endl;

            Base62KeyValidator keyValidator62;
            key = keyValidator62.validate62(result);

            if (key)
            {
                std::cout << "\nValid Base62 Key\n";
            }
            else
            {
                std::cout << "\nNot a Valid Base62 Key\n";
            }

            std::cout << "\nEncode a String to Base62 (Simply enter your data then push the Enter/Return button) : ";

            // Capture user input
            std::getline(std::cin, inputText);

            outputText = base62Encoder(inputText, result);
            std::cout << "\n\"" << inputText << "\" to Base62 : \"" << outputText << "\"\n"
                      << std::endl;

            result = "";
            inputText = "";
            outputText = "";
            filePath = "";
            key = false;
        }
        else if (menuInput == "decode62")
        {
        }
        else if (menuInput == "binary")
        {
            inputText = "";
            std::cout << "\nEnter a binary string (without spaces) : ";

            // Capture user input
            std::getline(std::cin, inputText);

            inputText = remover.removeSpaces(inputText);

            if (isValidBinary(inputText))
            {
                std::cout << ("\nValid Binary\n\n");
            }
            else
            {
                std::cout << ("\nNot a Valid Binary\n\n");
            }

            binaryConvertor(inputText);

            inputText = "";
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