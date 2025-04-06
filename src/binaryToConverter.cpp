#include "binaryToConverter.h"
#include "binaryValidator.h"
#include "hexValidator.h"

#include <iostream>
#include <bitset>
#include <limits>
#include <stdexcept>

void binaryConvertor(const std::string& binaryString)
{
    std::string result = binaryString;

    // Remove optional "0b" or "0B" prefix
    if (binaryString.length() >= 2 && binaryString[0] == '0' &&
        (binaryString[1] == 'b' || binaryString[1] == 'B'))
    {
        result = binaryString.substr(2);
    }

    if (isValidBinary(result))
    {
        unsigned long long convertedValue = std::bitset<64>(result).to_ullong();

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

                if (std::cin.fail())
                {
                    throw std::invalid_argument("\nInvalid input. Please enter a number.");
                }

                switch (choice)
                {
                case 1:
                    std::cout << "\nDecimal: " << convertedValue << "\n";
                    break;

                case 2:
                    std::cout << "\nHexadecimal: " << std::hex << convertedValue << std::dec << "\n";
                    break;

                case 3:
                    std::cout << "\nOctal: " << std::oct << convertedValue << std::dec << "\n";
                    break;

                case 4:
                    std::cout << std::endl;
                    return;

                default:
                    std::cout << "\nInvalid choice. Please select again.\n";
                }
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    else
    {
        std::cout << "Invalid binary input.\n" << std::endl;
    }
}