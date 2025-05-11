#include "sha256.h"
#include "executeSha256.h"

#include <iostream>
#include <string>

void executeSha256()
{
    std::string input;

    std::cout << "\n|================ SHA-256 Hash Generator ================|\n";
    std::cout << "\nEnter your message: ";
    std::getline(std::cin, input);

    SHA256 sha256;
    sha256.update(reinterpret_cast<const uint8 *>(input.c_str()), input.length());

    uint8 hash[32];
    sha256.final(hash);

    std::string hex = toHexString(hash);

    std::cout << "\n---------------------------------------------------------\n";
    std::cout << "\nOriginal Message: " << input << '\n';
    std::cout << "\nSHA-256 Hash    : " << hex << '\n' << std::endl;
}