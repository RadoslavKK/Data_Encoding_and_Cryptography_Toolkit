#ifndef BASE62_KEY_VALIDATOR_H
#define BASE62_KEY_VALIDATOR_H

#include <string>

class Base62KeyValidator
{
public:
    Base62KeyValidator();
    bool validate62(const std::string& key);
};

#endif 
