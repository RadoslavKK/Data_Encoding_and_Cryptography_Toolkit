#include "hexValidator.h"
#include "hexToConverter.h"
#include "toLowerCase.h"

#include <iostream>
#include <bitset>
#include <limits>
#include <stdexcept>
#include <sstream>

void hexConverter(const std::string &hexString)
{
    std::string result = hexString;

    result = toLowerCase(result);

    // Remove optional "0x" or "0X" prefix
    if (hexString.length() >= 2 && hexString[0] == '0' &&
        (hexString[1] == 'x' || hexString[1] == 'X'))
    {
        result = hexString.substr(2);
    }

    if (isValidHex(result))
    {
        unsigned long long convertedValue = 0;

        try
        {
            convertedValue = std::stoull(result, nullptr, 16);
        }
        catch (const std::exception &e)
        {
            std::cout << "Conversion error: " << e.what() << "\n";
            return;
        }

        std::cout << "\nChoose conversion option:\n";
        std::cout << "1. Binary\n";
        std::cout << "2. Octal\n";
        std::cout << "3. Decimal\n";
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
                    throw std::invalid_argument("Invalid input. Please enter a number.");
                }

                switch (choice)
                {
                case 1:
                    std::cout << "\nBinary: " << std::bitset<64>(convertedValue) << "\n";
                    break;

                case 2:
                    std::cout << "\nOctal: " << std::oct << convertedValue << std::dec << "\n";
                    break;

                case 3:
                    std::cout << "\nDecimal: " << convertedValue << "\n";
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
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    else
    {
        std::cout << "Invalid hexadecimal input.\n"
                  << std::endl;
    }
}