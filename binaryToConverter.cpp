#include <iostream>
#include <string>
#include "removeSpaces.h"
#include "isValidBinary.h"

void binaryToConverter()
{
    std::string input;

    std::cout << "\nEnter a binary string (without spaces): ";
    std::getline(std::cin, input);

    input = removeSpaces(input);

    if (isValidBinary(input))
    {
        unsigned long long decimalValue = std::bitset<64>(input).to_ullong();

        std::cout << "\nChoose conversion option:\n";
        std::cout << "1. Decimal\n";
        std::cout << "2. Hexadecimal\n";
        std::cout << "3. Octal\n";
        std::cout << "4. Exit\n";

        int choice = 0;

        while (true)
        {
            try
            {
                std::cout << "\nEnter your choice: ";
                std::cin >> choice;

                // Check if input failed (non-integer input)
                if (std::cin.fail())
                {
                    throw std::invalid_argument("\nInvalid input. Please enter a number.");
                }

                switch (choice)
                {
                case 1:
                    std::cout << "\nDecimal: " << decimalValue << "\n";
                    break;
                case 2:
                    std::cout << "\nHexadecimal: " << std::hex << decimalValue << "\n";
                    break;
                case 3:
                    std::cout << "\nOctal: " << std::oct << decimalValue << "\n";
                    break;
                case 4:
                    std::cout << std::endl;
                    return;
                default:
                    std::cout << "\nInvalid choice. Please select again.\n";
                }
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
                std::cin.clear();                                                   // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
        }
    }
    else
    {
        std::cout << "Invalid binary input.\n" << std::endl;
        return;
    }
}