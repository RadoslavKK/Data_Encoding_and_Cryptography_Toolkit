/*
____________________________ How to Run the Program. ____________________________

1. Set Base62 & Base64 Key Path in "main.cpp" on Lines 92 & 93

   File Names "base62Key.txt" & "base64Key.txt" located in "keys" Folder

   FilePathManager::getInstance().setBase64KeyPath(" < base64Key.txt File Path > ");
   FilePathManager::getInstance().setBase62KeyPath(" < base62Key.txt File Path > ");

2. Open a Terminal window.

3. Navigate to the project directory:
   cd EncodingToolkit++    // Change to the project directory.

4. Build the program:
   make                    // Compile the project and generate the executable.

5. Run the program:
   make run                // Execute the program.

6. Clean the build files:
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
#include "base62/executeBase62Encoder.h"

// Start Base62 Decoder
#include "base62/executeBase62Decoder.h"

// Start a Base62 Encode & Decoder Test
#include "base62/executeBase62Test.h"

// Start Base64 Encoder
#include "base64/executeBase64Encoder.h"

// Start Base64 Decoder
#include "base64/executeBase64Decoder.h"

// Start a Base64 Encode & Decoder Test
#include "base64/executeBase64Test.h"

// Start SHA256 Hash
#include "sha-256/executeSha256.h"

// Start Binary to Oct, Dec, Hex Convertor
#include "executeBinary.h"

// Start Hex
#include "executeHex.h"

// Comapre Two Keys
#include "keyOptions.h"

// Change Menu Cursor ">>> "
#include "cursorOptions.h"

int main(int argc, char *argv[])
{
    const std::string const_ToolKitVersion = "Encoding ToolKit++ Ver. 2.4.0 -beta.1";

    // ____________________________ Set key file paths. ____________________________
    FilePathManager::getInstance().setBase62KeyPath("/Users/radoslavkostov/Desktop/tool/Data_Encoding_and_Cryptography_Toolkit/keys-encoding-alphabet/base62Key.txt");
    FilePathManager::getInstance().setBase64KeyPath("/Users/radoslavkostov/Desktop/tool/Data_Encoding_and_Cryptography_Toolkit/keys-encoding-alphabet/base64Key.txt");

    // Future Updare fot Base32 and Base58 Encoder and Decoder's
    // FilePathManager::getInstance().setBase32KeyPath("/Users/radoslavkostov/Documents/Repositories/C++/EncodingToolkit++/keys-encoding-alphabet/base32Key.txt");
    // FilePathManager::getInstance().setBase58KeyPath("/Users/radoslavkostov/Documents/Repositories/C++/EncodingToolkit++/keys-encoding-alphabet/base58Key.txt");
    // ____________________________ Set key file paths. ____________________________

    // Create obj to Print current time
    TimePrinter time;

    // Create obj to Read Files.
    FileReader reader;

    // Create obj to Remove White Space
    StringFormatter remover;

    // Create obj for KeyOptions
    KeyOptions keyOption;

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

    std::string menuCourser = ">>> ";

    do
    {
        std::cout << menuCourser;
        menuInput.clear();

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

        // Constands for randomBase32, randomBase58, randomBase62 and randomBase64 key Generator
       
        // Future Updare fot Base32 and Base58 Encoder and Decoder's
        //const unsigned short baseCode32 = 32;
        //const unsigned short baseCode58 = 58;
       
        const unsigned short baseCode62 = 62;
        const unsigned short baseCode64 = 64;

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

        case CMD_DECODE62:
            executeBase62Decoder();
            break;

        case CMD_ENCODE64:
            executeBase64Encoder();
            break;

        case CMD_DECODE64:
            executeBase64Decoder();
            break;

        case CMD_SHA256:
            executeSha256();
            break;

        case CMD_BINARY:
            executeBinary();
            break;

        case CMD_HEX:
            executeHex();
            break;

        case CMD_TEST62:
            executeBase62Test();
            break;

        case CMD_TEST64:
            executeBase64Test();
            break;

        case CMD_KEYCOMPARE:
            keyOption.keyComapare();
            break;

        case CMD_GENERATE_RANDOM_KEY:
            keyOption.generateRandomKey();
            break;

        case CMD_GENERATE_BASE62_KEY:
            keyOption.generateBaseCodeKey(baseCode62);
            break;

        case CMD_GENERATE_BASE64_KEY:
            keyOption.generateBaseCodeKey(baseCode64);
            break;

        case CMD_VERSION:
            // Clear the Buffer
            std::cout << "\n"
                      << const_ToolKitVersion << "\n"
                      << std::endl;
            break;

        case CMD_MENU_CURSOR:
            menuCourser = changeCursor(menuCourser);
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