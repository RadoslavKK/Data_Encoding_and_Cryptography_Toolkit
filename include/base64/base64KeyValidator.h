#ifndef BASE64_KEY_VALIDATOR_H
#define BASE64_KEY_VALIDATOR_H

#include <string>

class Base64KeyValidator
{
public:
    Base64KeyValidator();
    bool validate64(const std::string& key);
};

#endif 
