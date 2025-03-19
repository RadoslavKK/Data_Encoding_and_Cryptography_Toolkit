
/*
_________________________________________________________________________________________________


This toolkit is currently in the development phase, with support for:

- Dynamic memory allocation
- SHA-256
- Base62 Encoder
- Base62 Decoder
- URL shortener
- MAKE
- Binary, Hex, Decimal - Converters

Updates are planned for release soon.

_________________________________________________________________________________________________

How to Run:
In the Terminal copy/paste:

clang++ main.cpp base64Encoding.cpp printMenu.cpp base64EncodingTest.cpp getRandomNumberInMinMaxScope.cpp checkOS.cpp base64Decoding.cpp readBase64CharacterSet.cpp base62Encoding.cpp readBase62CharacterSet.cpp -o myProgram

./myProgram

_________________________________________________________________________________________________

How do use:
int menu/terminal:

type "encode"
    - enter data in the form of a String // encode in Base64

type "decode"
    - enter data in the form of a String // decode Base64

_________________________________________________________________________________________________
*/

#include <iostream>
// #include <bitset> // For Converthing Char to Binary // -- Del
// #include <random> // For Random Number Generator
#include <cstdlib> // For Screen Clear // -- Del

// Include Header Files
#include "base64Encoding.h"
#include "printMenu.h"
#include "base64EncodingTest.h"
#include "getRandomNumberInMinMaxScope.h"
#include "checkOS.h"
#include "base64Decoding.h"
#include "base62Encoding.h"

int main(void)
{

    // Program Start Options Switch
    bool checkOSAbiluty = true;
    bool checkOSOnProgramStart = false;

    if (checkOSAbiluty == false)
    {
        checkOSOnProgramStart = false;
    }

    std::string osName = ""; // Fix dont nedd to be here

    bool runBase64EncodingTestOnProgramStart = false;
    bool printMenuOnProgramStart = false;

    // Options Switch Log
    if (checkOSOnProgramStart == true)
    {
        osName = checkOS();
    }

    // Base64 Encode and Decode Test at Start of Program
    // Step 1 : Generate Random String print it on the Screen
    // Step 2 : Encode in Base64 and  Prnt on Screen
    // Step 3 : Decode in Base64 and Print
    std::cout << "\n";
    std::string testDataOutputInProgramStart = base64EncodingTest();

    std::cout << "Random Base64 Encode Output : \"" << testDataOutputInProgramStart << "\"\n";
    std::cout << "\nBase64 Decode : " << testDataOutputInProgramStart << " : \"" << base64Decoding(testDataOutputInProgramStart) << "\"\n" << std::endl;

    // Options Switch Log
    if (printMenuOnProgramStart == true)
    {
        printMenu();
    }

    std::string menuInput = "";
    std::string inputText = "";
    std::string outputText = "";

    // Add Try Catch every where and Add Error Codes

    do
    {
        std::cout << ">>> ";
        std::getline(std::cin, menuInput);

        if (menuInput == "clear")
        {
            if (checkOSAbiluty == true) // Bug Meybe remove
            {
                if (osName == "macOS")
                {
                    system("clear");
                }
            }

            // ANSI escape codes for clearing screen
            std::cout << "\033[2J\033[H";
        }

        if (menuInput == "menu")
        {
            printMenu();
        }

        // Rewrite
        // Make the test a sepret ethod and call it in the beggining of the program.

        //_________________________________________

        /*
        if (menuInput == "test")
        {
            testDataOutputInProgramStart = base64EncodingTest();

            std::cout << "Base64 Encoded Test Output : \"" << testDataOutputInProgramStart << "\"\n";

            // testDataOutputInProgramStart = base64Decoding(testDataOutputInProgramStart);
            // std::cout << "Base64 Decode Test Output : \"" <<  << "\"\n";
        }
        */
        //_________________________________________

        if (menuInput == "encode64")
        {
            std::cout << "\nEncode to Base64 format (Simply enter your data then push the Enter/Return button) : ";

            // Capture user input
            std::getline(std::cin, inputText);

            // Base64 Encoding
            outputText = base64Encoding(inputText);
            std::cout << "Base64 Encoded Output : \"" << outputText << "\"\n"
                      << std::endl;
        }

        if (menuInput == "encode62")
        {
            std::cout << "\nEncode to Base62 format (Simply enter your data then push the Enter/Return button) : ";

            // Capture user input
            std::getline(std::cin, inputText);

            // Base64 Encoding
            outputText = base62Encoding(inputText);
            std::cout << "Base62 Encoded Output : \"" << outputText << "\"\n"
                      << std::endl;
        }

        if (menuInput == "decode64")
        {
            std::cout << "\nDecode Base64 format (Simply enter your data then push the Enter/Return button) : ";

            // Capture user input
            std::getline(std::cin, inputText);

            // Base64 Encoding
            outputText = base64Decoding(inputText);
            std::cout << "Base64 Encoded Output : \"" << outputText << "\"\n"
                      << std::endl;
        }

        if (menuInput == "exit")
        {
            // Exit loop
            break;
        }

        // Add command not found

        inputText = "";
        outputText = "";
        menuInput = "";

    } while (menuInput != "exit");

    // Clear the Buffer
    std::cout << "Exiting..." << std::endl;

    return 0;
}